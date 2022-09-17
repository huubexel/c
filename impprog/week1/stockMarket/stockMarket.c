/* file: stockMarket.c */
/* author: Huub Exel (email: h.exel@student.rug.nl) */
/* date: Sat Sep 17 2022 */
/* version: 1.0 */

/* Description:
 * Input (in this order): number of stocks, price per stock,
 * profit or loss percentage over those stocks in the first year and
 * profit or loss percentage over those stocks (including first years' percentage) in the second year.
 * Output: Profit, Loss or Tie and if the profit or loss is higher than one cent,
 * it also outputs how much is gained or lost in those two years.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    /* Input */
    int stocks;
    float pricePerStock, percFirstYear, percSecondYear;
    scanf("%d %f %f %f", &stocks, &pricePerStock, &percFirstYear, &percSecondYear);

    /* Profit or loss year 1 and year 2 */
    float yearOne = (stocks * pricePerStock) * (percFirstYear / 100);
    float yearTwo = ((stocks * pricePerStock) + yearOne) * (percSecondYear / 100);

    if (yearOne+yearTwo < -0.01 || yearOne+yearTwo > 0.01) { /* If the profit or loss is higher than 1 cent */
        if (yearOne+yearTwo > 0.01) {
            /* Print how much profit is gained over those 2 years */
            printf("Profit %.2f\n", yearOne + yearTwo);
        } else {
            /* Print how much loss is suffered over those 2 years */
            printf("Loss %.2f\n", -1 * (yearOne + yearTwo));
        }
    } else {
        printf("Tie\n"); /* If the profit or loss is less than 1 cent, print Tie */
    }
}
