/* file: areaOfOverlap.c */
/* author: Huub Exel (email: h.exel@student.rug.nl) */
/* date: Sat Sep 13 2022 */
/* version: 1.0 */

/* Description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    /* Input */
    int int1, int2, int3, int4, int5, int6, int7, int8;
    scanf("%d %d %d %d", &int1, &int2, &int3, &int4);
    scanf("%d %d %d %d", &int5, &int6, &int7, &int8);

    /* How to read these 8 variables, for example x1Rec1:
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

    // hier dat stukje wat ik heb afgesproken met mezelf neerzetten.
    if (y1Rec2 < y1Rec1 || (y1Rec2 == y1Rec1 && x1Rec2 < x1Rec1)) {
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


    /* overlapX1 is the left-under x point of overlapping etc*/
    int x, y;
    int overlapX1, overlapX2, overlapY1, overlapY2;

    if (x1Rec2 > x2Rec1 || x2Rec2 < x1Rec1) {
        x = 0;
    } else {
        if (x1Rec1 > x1Rec2) {
            overlapX1 = x1Rec1;
        } else {
            overlapX1 = x1Rec2;
        }
        if (x2Rec1 < x2Rec2) {
            overlapX2 = x2Rec1;
        } else {
            overlapX2 = x2Rec2;
        }
        x = overlapX1 - overlapX2;
    }


    if (y1Rec2 > y2Rec1 || y2Rec2 < y1Rec1) {
        y = 0;
    } else {
        if (y2Rec1 < y2Rec2) {
            overlapY2 = y2Rec1;
        } else {
            overlapY2 = y2Rec2;
        }

        /* Because I made sure to always put the rectangle with the lowest
         * y-point as rectangle1, this is always the case */
        overlapY1 = y1Rec2;

        y = overlapY1 - overlapY2;
    }

    printf("point1 (%d, %d)\n", overlapX1, overlapY1);
    printf("point2 (%d, %d)\n", overlapX2, overlapY2);

    int a = x * y;

    printf("%d\n", a);

}