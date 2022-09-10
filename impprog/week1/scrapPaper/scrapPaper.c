/* file: scrapPaper.c */
/* author: Huub Exel (email: h.exel@student.rug.nl) */
/* date: Sat Sep 10 2022 */
/* version: 1.0 */

/* Description:
 * This program calculates how many packages of sheets will be needed with
 * the amount of students that will be attending the exam and
 * the amount of sheets every attending student will get
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int students, sheets, sheetsInPackage;
    scanf("%d %d %d", &students, &sheets, &sheetsInPackage);

    // The version of the conditional with the ternary operator, wouldn't make this any prettier.
    if ((students * sheets) % sheetsInPackage) {
        printf("%d\n", (students * sheets) / sheetsInPackage + 1);
    } else {
        printf("%d\n", (students * sheets) / sheetsInPackage);
    }
    return 0;
}