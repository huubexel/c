#include <stdio.h>
#include <string.h>

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

    blanks = tabs = newlines = 0;

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

int replace_real_characters()
{
    // 1.10
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
            putchar('\n');
        }
        if (c == '\b') {
            putchar('\\');
            putchar('b');
            putchar('\n');
        }
        if (c == '\\') {
            putchar('\\');
            putchar('\\');
            putchar('\n');
        }
    }
}

//int word_per_line()
//{
//     1.12
//     Will figure this out further when I know how an array works
//     Or something more usefull.
//    strcat concetenates two strings
//     string_name[], maak je een string mee.
//    int c;
//    char string[] = "";
//
//    while ((c = getchar()) != EOF) {
//        if (c == ' ' || c == '\n' || c == '\t') {
//            printf("%s\n", string);
//            memset(string,0,strlen(string));
//        } else {
//            char d = c + '0';
//            strcat(string, d);
//        }
//    }
//}


int word_per_line_2()
{
    // you can probably do this with putchar(c)
    // and without an array, which is also cool.

    int c, i, counter;
    int word_array[99]; /* make array for one word at the time */

    counter = 0;

    while ((c = getchar()) != EOF) {
        word_array[counter] = c;
        ++counter;
        if (c == '\n') {
            for (i = 0; word_array[i] != '\0'; ++i) {
                if (word_array[i] == ' ')
                    printf("\n");
                else
                    printf("%c", word_array[i]); /* print character */
                word_array[i] = '\0'; /* empty this index of array */
            }
            printf("\n");
            counter = 0; /* set counter to 0, cause the word is printed */
        }
    }
}

int d_w_o_counter()
{
    /* c is input,
     * i is an array,
     * nwhite is number of whitespaces, tabs, newlines
     * nother is number of other characters (letters) */
    int c, i, nwhite, nother;
    int ndigit[10]; /* array */

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        /* fill the array with 10 zero's */
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
        /* if the input character is a number */
        if (c >= '0' && c <= '9')
            /* c-'0' is the numeric value of input
             * numeric value of the digit. */
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    /*
     * A little explanation to myself here:
     * c is the input, this is a number (an ASCII number)
     * let's say the input to '5' is ASCII number 63
     * than '6' is 64, '7' is 65 etc.
     * If you subtract '0' which would according to this
     * example be 58 as ASCII number, say the input is 5
     * which for the machine is 63, now you don't want to
     * update the 63th (or 64th because you start at 0)
     * index of the array, you want to update the 5th.
     * How do you get 5 from '5', well if you substract
     * '0' from '5' you get this equation: 63 - 58 = 5
     * which is the index you want, this is how it works.
     */

    printf("digits = ");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
}

int histogram_length_of_words() {
    // 1.13
    // I know that the histogram is not aligned next to each other
    // And I could make it that it works that way, but I have more things
    // to do in live.

    int c, counter;

    counter = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == ' ' || c == '\t') {
            //for (i = counter; )
            printf("%d chars long\n", counter);
            printf(" __ \n");
            while (counter != 0) {
                printf("|  |\n");
                --counter;
            }
            printf("\n");
        } else
            ++counter;
    }
}


int main () {
    //fahrenheit();
    //print_input();
    //count_characters_while();
    //count_characters_for();
    //count_lines();
    //count_more();
    //replace_multiple_blanks_with_single();
    //replace_real_characters();
    //word_per_line_2();
    //d_w_o_counter();
    histogram_length_of_words();
}
