#include <stdio.h>
#include <stdbool.h>

void encode_char(const char character, bool bits[8]);
char decode_byte(const bool bits[8]);

int main() {

bool bits1[8];

encode_char('A', bits1);

for (int i = 0; i < 8; i++) {
    printf("%d", bits1[i]);
}
printf("\n");


bool bits2[8] = {0,1,0,0,0,0,0,1};

printf("%c\n", decode_byte(bits2));


    return 0;
}

void encode_char(const char character, bool bits[8]) {
    int ch = character;
    for (int i = 0; i < 8; i++) {
    bits[i] = ch % 2;
    ch /= 2;
    }

    for (int i = 0; i < 4; i++) {
        bool bitt = bits[i];
        bits[i] = bits[7 - i];
        bits[7 - i] = bitt;
    }
}

char decode_byte(const bool bits[8]) {
    int ch2 = 128;
    char word;
    for (int i = 0; i < 8; i++) {
        if (bits[i] == 1) {
            word = word + ch2;
        }
        ch2 = ch2 / 2;
    }

    return word;
}
