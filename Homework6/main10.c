#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void encode_string(const char string[], bool bytes[strlen(string)+1][8]);
void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]);

int main() {

char* text = "Hello, how are you?";
const int len = strlen(text);
bool bytes1[len + 1][8];

encode_string(text, bytes1);

for(int j = 0; j <= len; j++){
    printf("%c: ", text[j]);
    for(int i = 0; i < 8; i++){
        printf("%d", bytes1[j][i]);
    }
    printf("\n");
}
printf("\n");



bool bytes2[7][8] = {
    {0,1,0,0,1,0,0,0},
    {0,1,1,0,0,1,0,1},
    {0,1,1,0,1,1,0,0},
    {0,1,1,0,1,1,0,0},
    {0,1,1,0,1,1,1,1},
    {0,0,1,0,0,0,0,1},
    {0,0,0,0,0,0,0,0}
};
char string[7];
decode_bytes(7, bytes2, string);
printf("%s\n", string);


    return 0;
}


void encode_string(const char string[], bool bytes[strlen(string)+1][8]) {
    int word;
    bool byte;
    for (int j = 0; j < strlen(string) + 1; j++) {
        word = string[j];
        for ( int i = 0; i < 8; i++) {
            if (string[i] != '\0') {
                bytes[j][i] = word % 2;
                word /= 2;
            } else {
                bytes[j][i] = 0;
            }
        }
    }


    for (int j = 0; j < strlen(string) + 1; j++) {
        for (int i = 0; i < 4; i++) {
            bool byte = bytes[j][i];
            bytes[j][i] = bytes[j][7 - i];
            bytes[j][7 - i] = byte;
        } 
    }

}

void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]) {
    int ch2 = 128;
    int word = 0;
    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < 8; i++) {
            if (bytes[j][i] == 1) {
                word = word + ch2;
            }
            ch2 = ch2 / 2;
        }
        string[j] = word;
        ch2 = 128;
        word = 0;
    }
}