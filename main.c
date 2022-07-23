#include <stdio.h>

#define UPPER 300
#define STEP 20
#define LOWER 0


int fahrenheit()
{
    int fahr;

    printf("Fahrenheit   Celsius\n");
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%10d   %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}

int print_input()
{
    int c;
    int check;

    while ((c = getchar()) != EOF) {
        putchar(c);
    }

    check = (getchar() != EOF);
    printf("\n%d\n", EOF);
    printf("%d\n", check);
}

int count_characters_while()
{
    long nc;

    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);
}

int count_characters_for()
{
    // Use control d to exit
    double nc;

    // not sure what this error means
    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
}

int main () {
    //fahrenheit();
    //print_input();
    //count_characters_while();
    count_characters_for();
}
