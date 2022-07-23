#include <stdio.h>

#define UPPER 300
#define STEP 20
#define LOWER 0

void fahrenheit();
void print_input();

int main () {
    fahrenheit();
    //print_input();

}

void fahrenheit() {
    int fahr;

    printf("Fahrenheit   Celsius\n");
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%10d   %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}

void print_input() {
    int c;
    int check;

    while ((c = getchar()) != EOF) {
        putchar(c);
    }

    check = (getchar() != EOF);
    printf("\n%d\n", EOF);
    printf("%d\n", check);
}