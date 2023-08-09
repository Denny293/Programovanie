#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include "hangman.h"


int get_word(char secret[]){
    // check if file exists first and is readable
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if( fp == NULL ){
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    // get the filesize first
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do{
        // generate random number between 0 and filesize
        long int random = (rand() % size) + 1;
        // seek to the random position of file
        fseek(fp, random, SEEK_SET);
        // get next word in row ;)
        int result = fscanf(fp, "%*s %20s", secret);
        if( result != EOF )
            break;
    }while(1);

    fclose(fp);

    return 0;
}

int is_word_guessed(const char secret[], const char letters_guessed[]) {
    int counter;
    for (int i = 0; i < strlen(secret); i++){
        for (int j = 0; j < strlen(letters_guessed); j++) {
            if (secret[i] == letters_guessed[j]){
                counter = 0;
            } else if (counter != 0 && secret[i] != letters_guessed[j]) {
                counter = 1;
            }
        }
        if (counter == 1) {
            return 1;
        } 
        counter = 2;
    }
    return 0;
}

void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]) {
    int counter = 10;
    for (int i = 0; i < strlen(secret); i++) {
        for (int j = 0; j < strlen(letters_guessed); j++) {
            if (secret[i] == letters_guessed[j]){
                guessed_word[i] = letters_guessed[j];
                counter = 0;
            } else if (counter != 0 && secret[i] != letters_guessed[j]) {
                guessed_word[i] = '_';
            }
        }
        counter = 10;
    }
}

void get_available_letters(const char letters_guessed[], char available_letters[]) {
    for (int i = 0; i < strlen(letters_guessed); i++) {
        for (int j = 0; j < strlen(available_letters); j++) {
            if (letters_guessed[i] == available_letters[j]) {
                for (int k = j; k < strlen(available_letters); k++){
                    available_letters[k] = available_letters[k + 1];
                }
            }
        }
    }
}

void hangman(const char secret) {

    int guesses_left = 8;
    char available_letters[125];
    char letters_guessed[125];
    char guessed_word[125];

    int length = 0;

    printf("Welcome to the game, Hangman!\n");
    printf("I am thinking of a word that is %d letters long.\n", strlen(secret));

    while (guesses_left != 0) {
        printf("You have %d guesses left.\n", guesses_left);
        get_available_letters(letters_guessed, available_letters);
        printf("Available letters: %s\n", available_letters);
        printf("Please guess a letter: \n");
        length = strlen(letters_guessed);   
        scanf("%s", &letters_guessed);
        length-= strlen(letters_guessed);
        for (int i = 0; i < strlen(letters_guessed); i++) {
            letters_guessed[i] = tolower(letters_guessed[i]);
        }
        get_guessed_word(secret, letters_guessed, guessed_word);

        if (length == strlen(secret)) {
            if (secret == guessed_word) {
                printf("Congratulations you won!\n");
                break;
            } else {
                printf("Sorry, bad guess. The word was %s.", secret);
                break;
            }
        }

        if (secret == guessed_word) {
            printf("Good guess!: %s\n", guessed_word);
            printf("Congratulations, you won! %s\n");
            guesses_left = 0;
            break;
        } else if (is_word_guessed(secret, letters_guessed) == 0) {
            printf("Good guess!: %s\n", guessed_word);
        } else {
            printf("Oops! That letter is not in my word: %s\n", guessed_word);
            guesses_left--;
        }

        if (guesses_left == 0) {
            printf("Sorry, you ran out of guesses. The word was %s\n", secret);
        }
    }

    
}

