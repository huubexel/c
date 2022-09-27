/* file: numberAnagram.c */
/* author: Huub Exel (email: h.exel@student.rug.nl) */
/* date: Tue Sep 27 2022 */
/* version: 1.0 */

/* Description:
 * This program takes two integers and checks whether they are anagrams of each other.
 */

#include <stdio.h>

int main() {
    /* Input */
    int a, b;
    scanf("%d %d", &a, &b);

    int b0 = b, t, q;
    int x0 = 0, x1 = 1;
    if (b == 1) return 1;
    while (a > 1) {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return x1;
}