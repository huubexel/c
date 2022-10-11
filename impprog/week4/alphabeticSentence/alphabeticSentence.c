/* file: alphabeticSentence.c */
/* author: Huub Exel (email: h.exel@student.rug.nl) */
/* date: Mon Oct 11 2022 */
/* version: 1.0 */

/* Description:
 * Input: a sentence
 * Output: YES || NO
 * Looks through a sentence and checks whether each word in the sentence
 * starts with a letter that is further in the alphabet than the first letter of the previous word.
 */

#include <stdio.h>
#include <stdlib.h>

int toLowerChar(int word) {
    /* returns the lowered character */
    if ((((int)word) > 64) && (((int)word) < 91)) {
        return word+32;
    } else {
        return word;
    }
}

int isAlphabeticChar(int letter) {
    /* Checks if the character given is Alphabetic */
    if (((((int)letter) > 64) && (((int)letter) < 91)) || ((((int)letter) > 96) && (((int)letter) < 123))) {
        return 1;
    } else {
        return 0;
    }
}

int main() {

    int asciiCharToBeat = 0; /* asciiCharToBeat is the ascii value of the character to beat */

    /* This is 1 So it will immediately take the first character */
    int counter = 1;

    char c;
    while (c != '\n') { /* While loops stops when enter is pressed */

        c = getchar();
        if (c == ' ') { /* If the char is a space, set counter to 0 */
            counter = 0;
        }

        /* If it is the first char of the sentence or the first char after a whitespace, and it is alphabetic */
        if (counter == 1 && isAlphabeticChar(((int)c))) {
            /* If the (lowered) character is higher in the alphabet than the character to beat */
            if (toLowerChar(((int)c)) > asciiCharToBeat) {
                asciiCharToBeat = toLowerChar(c); /* the ascii value of the new character to beat is set here */
            } else {
                /* If it is not a correct sequence print NO */
                printf("NO\n");
                exit(0);
            }
        }

        if (counter == 1 && (!(isAlphabeticChar(((int)c))))) {
            /* If the first character is not alphabetic, wait first the first one that will be alphabetic */
            counter = 1;
        } else {
            counter += 1;
        }
    }

    /* If de sequence is alphabetic print YES */
    printf("YES\n");

    return 0;
}
