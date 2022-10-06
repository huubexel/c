/* file: alphabeticSentence.c */
/* author: Huub Exel (email: h.exel@student.rug.nl) */
/* date: Thu Oct 06 2022 */
/* version: 1.0 */

/* Description:
 * Input: a sentence
 * Output: YES || NO
 * Looks through a sentence and checks whether each word in the sentence
 * starts with a letter that is further in the alphabet than the first letter of the previous word.
 */

#include <stdio.h>

int toLowerChar(int word) {
    if ((((int)word) > 64) && (((int)word) < 91)) {
        return word+32;
    } else {
        return word;
    }
}

int main() {

    int asciiCharToBeat = 0; /* asciiCharToBeat is the ascii value of the character to beat */
    int correctSequences = 0;

    /* These 2 are value 1, so it immediately takes the first character of the sentence without needing a whitespace */
    int amountOfWords = 1;
    int counter = 1;

    char c;
    while (c != '\n') { /* While loops stops when enter is pressed */

        c = getchar();
        if (c == ' ') {
            counter = 0;
            amountOfWords += 1; /* if there is a space the amount of words goes up by 1 */
        }

        /* If it is the first char of the sentence or the first char after a whitespace */
        if (counter == 1 && (((int)c) < 128)) {
            /* If the (lowered) character is higher in the alphabet than the character to beat */
            if (toLowerChar(((int)c)) >= asciiCharToBeat) {
                correctSequences += 1;
                if (toLowerChar(((int)c)) != ((int)c)) {
                    asciiCharToBeat = toLowerChar(c); /* uppercase characters */
                } else {
                    asciiCharToBeat = c; /* lowercase characters */
                }
            }
        }

        counter += 1;
    }

    if (correctSequences == amountOfWords) {
        /* If the first letter of each word in the sentence
         * starts with a letter that is further in the alphabet than the first letter of the previous word.
         * Print YES */
        printf("YES\n");
    } else {
        /* If this is not the case, print NO */
        printf("NO\n");
    }
    return 0;
}