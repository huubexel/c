/* file: areaOfOverlap.c */
/* author: Huub Exel (email: h.exel@student.rug.nl) */
/* date: Sat Sep 13 2022 */
/* version: 1.0 */

/* Description:
 */

// Als 1 van de vierkanten in de ander zit, dan gaat de kleinste bovenaan de calculatie

// Dus stel de y waarde van beide is hetzelfde (de x-lijnen zijn op dezelfde hoogtes),
// Dan is diegene die bovenaan moet is degene met de kleinste x-waarde
// Dit geld ook als de x waarde van beide hetzelfde is.


// Edge cases:
// 1. ze hebben precies hetzelfde startpunt. Bijvoorbeeld allebei 0,0
// 2. 2 points of 1 rect are in another rect en dit links of onder. 1 groter dan de ander.
// 3. de x-ass of de y-ass die onder of links is komt overeen voor beide vierkanten.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    /* Input */
    int int1, int2, int3, int4, int5, int6, int7, int8;
    scanf("%d %d %d %d", &int1, &int2, &int3, &int4);
    scanf("%d %d %d %d", &int5, &int6, &int7, &int8);

    /* How to read these 8 variables:
     * x1Rec1 --> can be deciphered in 3 parts (this works for all 8 of these variables):
     * x --> x-ass value for this point, y being the y-ass value for this point
     * 1 --> bottom-left point, 2 being the top-right point
     * Rec1 --> from rectangular 1, Rec2 being from rectangular 2 */
    int x1Rec1, y1Rec1, x2Rec1, y2Rec1;
    int x1Rec2, y1Rec2, x2Rec2, y2Rec2;

    /* For my equation I will need the two points where this program does the calculations on
     * to be the bottom-left point and the top-right point, this will make sure that is the case.
     *
     * For the bottom-left point, it will take the lowest x and lowest y from the points that are given
     * and for the top-right point, it will take the highest x and highest y */

    if (int1 > int3) {
        x2Rec1 = int1;
        x1Rec1 = int3;
    } else {
        x2Rec1 = int3;
        x1Rec1 = int1;
    }

    if (int2 > int4) {
        y2Rec1 = int2;
        y1Rec1 = int4;
    } else {
        y2Rec1 = int4;
        y1Rec1 = int2;
    }

    if (int5 > int7) {
        x2Rec2 = int5;
        x1Rec2 = int7;
    } else {
        x2Rec2 = int7;
        x1Rec2 = int5;
    }

    if (int6 > int8) {
        y2Rec2 = int6;
        y1Rec2 = int8;
    } else {
        y2Rec2 = int8;
        y1Rec2 = int6;
    }

    /* The rectangle, which lowest x is higher than the other rectangles'
     * lowest x, has to be rectangle1 in my equation, if that is not the case
     * this will switch the two rectangles */
    if (x1Rec1 < x1Rec2 || (x1Rec1 == x1Rec2 && (y2Rec2 < y2Rec1 || x2Rec2 < x2Rec1))) {
        int temp1, temp2, temp3, temp4;
        temp1 = x1Rec2;
        temp2 = y1Rec2;
        temp3 = x2Rec2;
        temp4 = y2Rec2;
        x1Rec2 = x1Rec1;
        y1Rec2 = y1Rec1;
        x2Rec2 = x2Rec1;
        y2Rec2 = y2Rec1;
        x1Rec1 = temp1;
        y1Rec1 = temp2;
        x2Rec1 = temp3;
        y2Rec1 = temp4;
    }

    printf("%d %d %d %d\n", x1Rec1, y1Rec1, x2Rec1, y2Rec1);
    printf("%d %d %d %d\n", x1Rec2, y1Rec2, x2Rec2, y2Rec2);


    // Wat er dan fout gaat, is dat ze allebei dezelfde y hebben, die lijnen.

    int x, y;
    int endLineX, startLineX, topLineY, bottomLineY;

    if (x1Rec2 > x2Rec1 || x2Rec2 < x1Rec1) {
        x = 0;
    } else {
        if (x2Rec1 < x2Rec2) {
            endLineX = x2Rec1;
        } else {
            endLineX = x2Rec2;
        }
        if (x1Rec1 > x1Rec2) {
            startLineX = x1Rec1;
        } else {
            startLineX = x1Rec2;
        }
        printf("endLineX %d startLineX %d\n\n", endLineX, startLineX);
        x = endLineX - startLineX;
    }


    if (y1Rec2 > y2Rec1 || y2Rec2 < y1Rec1) {
        y = 0;
        printf("het is y\n");
    } else {
        if (y2Rec1 < y2Rec2) {
            topLineY = y2Rec1;
        } else {
            topLineY = y2Rec2;
        }

        if (y1Rec1 > y1Rec2) {
            bottomLineY = y1Rec1;
        } else {
            bottomLineY = x2Rec2;
        }

        printf("topLineY %d bottomLineY %d\n\n", topLineY, bottomLineY);

        y = topLineY - bottomLineY;
    }

    int a = x * y;

    printf("%d\n", a);

}