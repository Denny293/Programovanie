#include <stdio.h>
#include <string.h>
#include <stdbool.h>
FILE *file;
void balance_output(int);
void balance_stored(int, char *);
void profile_password(int, char *);


int main() {
    int balance = 0;
    int password = 0;
    int deposit_amount = 0;
    int withdraw_amount = 0;
    int command_number = 0;
    bool c = true;
    int count_main = 1;
    int count_read = 0;
    char data_string[256];

    // file = fopen("balance.txt", "w");
    // fclose(file);
    // file = fopen("pin.txt", "w");
    // fclose(file);
    // printf("Enter your balance: ");
    // scanf("%d", &balance);
    
 file = fopen("balance.txt" , "r"); 
 while ( fgets (data_string, 225, file) != NULL ) {
        puts(data_string);
        for (int i = 0; data_string[i] != '\0'; i++) {
            balance = balance * 10 + (data_string[i] - 48);
        }
 } 
 printf("Your balance: %d\n", balance);
 fclose(file);


 return 0;


while (c) {
    printf("1-deposit \t 2-withdraw \t 3-leave \t 4 - profile \n");
    scanf("%d", &command_number);
    
    if ( command_number == 3) {
        break;
    }

    if ( command_number == 1 ) {
        printf("Enter deposit amount: ");
        scanf("%d", &deposit_amount);
        balance = deposit_amount + balance;
        balance_stored(balance, data_string);
        balance_output(balance);  
    } else if ( command_number == 2 ) {
        printf("Enter withdraw amount: ");
        scanf("%d", &withdraw_amount);
        balance = balance - withdraw_amount;
        balance_stored(balance, data_string);
        balance_output(balance); 
    } else if ( command_number == 4 ) {
        printf("Enter password \n");
        scanf("%d", &password);
        profile_password(password, data_string);
    }

    
    printf("Back to main menu-? \n");
    scanf("%d", &command_number);

    if ( command_number == 1 || command_number == 2 || command_number == 4 ) {
        continue;
    } else {
        c = false;
    }
}
// ############# FILE READER ###############
//  file = fopen("profile.txt" , "r"); 
//  while ( fgets (balance_string, 225, file) != NULL ) {
//     count_read++;
//     if ( count_read == 2 ) {
//          puts(balance_string);
//          printf("Balance: %s", puts(balance_string));
//     }
//       } 
//    fclose(file);

      return 0;
}

// simple printing function
void balance_output(int balance) {
    printf("Balance: %d\n", balance);
}

// importing data into the balance.txt file
void balance_stored(int balance, char *data_string) {
    file = fopen("balance.txt", "a");
    sprintf(data_string, "%d", balance);
    fputs(data_string, file);
    fclose(file);
}

// importing data into the pin.txt file
void profile_password(int password, char *data_string) {
    file = fopen("pin.txt", "a");
    sprintf(data_string, "%d", password);
    fputs(data_string, file);
    fclose(file);
}

