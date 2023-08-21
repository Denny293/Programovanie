#include <stdio.h>
#include <string.h>
#include "hangman.c"


int main() {

    

    hangman("sdfef");

    // char guessed_word[125]={"_"};
    // char length_1[125];
    // for (int i = 0; i < strlen(guessed_word); i++) {
    //     length_1[i] = guessed_word[i];
    // }
    // guessed_word[125]='_';
    // int result = memcmp(guessed_word, length_1, strlen(guessed_word));

    // for (int i = 0; i < strlen(guessed_word); i++) {
    //     length_1[i] = guessed_word[i];
    // }
    // result = memcmp(guessed_word, length_1, strlen(guessed_word));

    // printf("%d\n",result);

    // printf("%d",is_word_guessed("sefs", "sef"));

    // char array[125];
    // char arrayy[125];

    // scanf("%s",&array[0]);

    // for (int i = 0; i < 2; i++) {
    //     arrayy[i] = array[i];
    //     arrayy[2] = '\0';
    //     printf("%c\t",array[i]);
    // }

    // scanf("%s",&array[2]);

    // for (int i = 0; i < 11; i++) {
    //     arrayy[i] = array[i];
    //     arrayy[11] = '\0';
    //     printf("%c\t",array[i]);
    // }

    // printf("%d",strlen(arrayy));


    return 0;
}