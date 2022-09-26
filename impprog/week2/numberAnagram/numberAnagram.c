/* file: numberAnagram.c */
/* author: Huub Exel (email: h.exel@student.rug.nl) */
/* date: Mon Sep 26 2022 */
/* version: 1.0 */

/* Description:
 * This program takes two integers and checks whether they are anagrams of each other.
 */

#include <stdio.h>

int main() {
    /* Input */
    int inp1, inp2;
    scanf("%d %d", &inp1, &inp2);

    /* This is where the length of inp1 and inp2 will go */
    int len1, len2;

    /* get the length of both inputs */
    for (int i = 0; i < 2; i++) {
        int n;
        int count = 0;          /* counts the number of digits */
        n = (!i) ? inp1 : inp2; /* get the input we are dealing with */

        /* I decided to keep 0 in if it is the only number put in for that integer
         * because 0 0 is an anagram, leading zeros are furthermore ignored */
        do {               /* Here we count the length of both inputs */
            n /= 10;
            ++count;
        } while (n != 0);

        /* Give the right count to the right number */
        if (!i) {
            len1 = count;
        } else {
            len2 = count;
        }
    }

    if (len1 == len2) { /* If the 2 numbers are not the same length you can immediately print NO */

        /* By using (input1or2 remainder 10^x) / (10^x-1),
         * we will be able to get each number separately,
         * which is very useful for comparing them. */

        /* Say you fill in the numbers 3333 3444,
         * then those 3's in the first input will have a match every single time,
         * even tho 3333 and 3444 are not a palindrome of each other. How are we going to make sure
         * that we do have the same number, if we sum the digits of both inputs. */
        int sum1 = 0;
        int sum2 = 0;

        int rem1 = 10;
        for (int i = 1; (i < (len1+1)); i++) {
            sum1 += (inp1 % rem1)/(rem1/10); /* Add the current digit to sum of digits1 */

            int rem2 = 10;
            for (int j = 0; j < len2; j++) {
                if ((inp1 % rem1)/(rem1/10) == ((inp2 % rem2)/(rem2/10))) {
                    sum2 += (inp2 % rem2)/(rem2/10); /* Add the current digit to sum of digits2 */
                    /* Once it finds a match, it should not on for the same number,
                     * because it has already been matched, that's why we break here */
                    break;
                }
                rem2 *= 10;
            }/* Increase the remainder so next iteration we will have acces to the
              * digit one position more to the left. (For both rem) */
            rem1 *= 10;
        }

        if (sum1 == sum2) {
            printf("YES\n");
        }
    } else {
        printf("NO\n");
    }

    return 0;
}
