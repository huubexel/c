/* file: stockMarket.c */
/* author: Huub Exel (email: h.exel@student.rug.nl) */
/* date: Sat Sep 10 2022 */
/* version: 1.0 */

/* Description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int stocks;
    float pricePerStock, percFirstYear, percSecondYear;
    scanf("%d %f %f %f", &stocks, &pricePerStock, &percFirstYear, &percSecondYear);
    printf("%d %f %f %f", stocks, pricePerStock, percFirstYear, percSecondYear);
}