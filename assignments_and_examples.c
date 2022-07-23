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

int count_lines()
{
    int c, nl;
    nl = 0;

    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
}

int count_more()
{
    // 1.8
    int c, blanks, tabs, newlines;

    blanks = 0;
    tabs = 0;
    newlines = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n')
            ++newlines;
        if (c == '\t')
            ++tabs;
        if (c == ' ')
            ++blanks;
    }

    printf("blanks: %d tabs: %d newlines: %d\n", blanks, tabs, newlines);
}

int replace_multiple_blanks_with_single()
{
    // 1.9
    int c, counter;

    while ((c = getchar()) != EOF) {

        // I don't know what this warning means
        if (c == ' ') {
            ++counter;
        } else if (c == '\t'){
            ++counter;
        } else {
            counter = 0;
        }
        if (counter < 2) {
            putchar(c);
        }
    }
}

int main () {
    //fahrenheit();
    //print_input();
    //count_characters_while();
    //count_characters_for();
    //count_lines();
    //count_more();
    replace_multiple_blanks_with_single();
}
