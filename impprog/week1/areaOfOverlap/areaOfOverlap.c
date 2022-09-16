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
    int in1, in2, in3, in4, in5, in6, in7, in8;
    scanf("%d %d %d %d", &in1, &in2, &in3, &in4);
    scanf("%d %d %d %d", &in5, &in6, &in7, &in8);

    /* How to read these 8 variables, for example x1Rec1:
     * x --> x-ass value for this point, y being the y-ass value for this point
     * 1 --> bottom-left point, 2 being the top-right point
     * Rec1 --> from rectangular 1, Rec2 being from rectangular 2 */
    int x1Rec1, y1Rec1, x2Rec1, y2Rec1;
    int x1Rec2, y1Rec2, x2Rec2, y2Rec2;

    /* For the equation I will need the two points of each rectangle to be
     * the bottom-left point and the top-right point,
     * the code below will make sure that is the case. */
    if (in1 > in3) {
        x2Rec1 = in1;
        x1Rec1 = in3;
    } else {
        x2Rec1 = in3;
        x1Rec1 = in1;
    }

    if (in2 > in4) {
        y2Rec1 = in2;
        y1Rec1 = in4;
    } else {
        y2Rec1 = in4;
        y1Rec1 = in2;
    }

    if (in5 > in7) {
        x2Rec2 = in5;
        x1Rec2 = in7;
    } else {
        x2Rec2 = in7;
        x1Rec2 = in5;
    }

    if (in6 > in8) {
        y2Rec2 = in6;
        y1Rec2 = in8;
    } else {
        y2Rec2 = in8;
        y1Rec2 = in6;
    }

    /* Here I make sure that rectangle1 will always be the rectangle with
     * the lowest y-point of both rectangles. */
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

    int x, y;

    int overlapX1, overlapX2; // Make sure to put these in the else at the end, this is pure for the print to work
    int overlapY1, overlapY2; // Make sure to put these in the else at the end, this is pure for the print to work

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
         * y-point as rectangle1, this is always true  */
        overlapY1 = y1Rec2;

        y = overlapY1 - overlapY2;
    }

    printf("point1 (%d, %d)\n", overlapX1, overlapY1);
    printf("point2 (%d, %d)\n", overlapX2, overlapY2);

    int a = x * y;

    printf("%d\n", a);
}