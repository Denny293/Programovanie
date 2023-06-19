#include <stdio.h>

unsigned long sum_squared(const int);

int main() {
    const int line;
    scanf("%d", &line);
    printf("%lu\n", sum_squared(line));

    return 0;
}

unsigned long sum_squared(const int line) {
    int a = 1;
    for (int i = 0; i < line; i++) {
        a = a * 2;
    }
    
    return a;
}