#include <stdio.h>

int main () {
    /* Copy input to output first version */
    int c;
    int check;

    while ((c = getchar()) != EOF) {
        putchar(c);
    }

    check = (getchar() != EOF);
    printf("\n%d\n", EOF);
    printf("%d\n", check);
}