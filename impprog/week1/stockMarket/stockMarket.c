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
    float yearOne = (stocks * pricePerStock) * (percFirstYear / 100);
    float yearTwo = ((stocks * pricePerStock) + yearOne) * (percSecondYear / 100);
    //switch () {

    //}
    // hier een switch maken voor minder dan 0, 0 en meer dan 0.
    printf("%f\n", ((stocks * pricePerStock) + yearOne) + yearTwo);
}
