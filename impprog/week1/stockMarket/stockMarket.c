/* file: stockMarket.c */
/* author: Huub Exel (email: h.exel@student.rug.nl) */
/* date: Sun Sep 11 2022 */
/* version: 1.0 */

/* Description:
 * Input: number of stocks, price per stock,
 * profit or loss percentage over those stocks in the first year and
 * profit or loss percentage over those stocks in the second year.
 * It takes those in the order stated above.
 * Output: Profit, Loss or Tie and if the profit or loss is higher than one cent
 * it also outputs how much is gained or lost in those two years.
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

    if (yearOne+yearTwo < -0.01 || yearOne+yearTwo > 0.01) {
        if (yearOne+yearTwo > 0.01) {
            printf("Profit %.2f\n", yearOne + yearTwo);
        } else {
            printf("Loss %.2f\n", -1 * (yearOne + yearTwo));
        }
    } else {
        printf("Tie\n");
    }
}
