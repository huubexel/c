#include <stdio.h>

int main () {
    /* Copy input to output first version */
    int c;

    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}