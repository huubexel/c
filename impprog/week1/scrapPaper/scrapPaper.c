/* file: scrapPaper.c */
/* author: Huub Exel (email: h.exel@student.rug.nl) */
/* date: Sat Sep 17 2022 */
/* version: 1.0 */

/* Description:
 * This program takes 3 integers as input (in this order):
 * amount of students, sheets per student attending, sheets in 1 package.
 * It calculates how many packages will be needed and outputs it.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    /* Input */
    int students, sheets, sheetsInPackage;
    scanf("%d %d %d", &students, &sheets, &sheetsInPackage);

    /* This calculates and prints the number of packages needed according to the input */
    if ((students * sheets) % sheetsInPackage) {
        /* You need an extra package if you can't give all students the same amount of sheets */
        printf("%d\n", (students * sheets) / sheetsInPackage + 1);
    } else {
        printf("%d\n", (students * sheets) / sheetsInPackage);
    }
    return 0;
}
