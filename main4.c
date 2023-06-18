#include <stdio.h>
#include <string.h>

int opposite_number( const int, const int);

int main() {
    const int n;
    const int number;
    scanf("%d %d", &n, &number);
    printf("%d\n", opposite_number(n, number));

    return 0;
}

int opposite_number( const int n, const int number) {
    int g;
    if (number <= (n / 2)) {
        g = n / 2 + number;
    } else {
        g = (n / 2 + number) - n;
    }
    return g;
}