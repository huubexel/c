/* file: decimalNumber.c */
/* author: Huub Exel (email: h.exel@student.rug.nl) */
/* date: Sat Sep 17 2022 */
/* version: 1.0 */

/* Description:
 * This program takes an integer from 1000 to 9999 (1000 included, 10000 not included),
 * and outputs it in the format that will show how much 1000's, 100's, 10's and 1's
 * there will be needed to make the number. Starting with 1000's going down to 1's.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    /* Input */
    int n;
    scanf("%d", &n);

    /* prints how much 1000's, 100's, 10's and 1's there will be needed to make the integer inputted. */
    printf("%d=%d*1000 + %d*100 + %d*10 + %d\n", n, n/1000, (n%1000)/100, ((n%1000)%100)/10, ((n%1000)%100)%10);
}
