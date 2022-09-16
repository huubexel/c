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

    int x, y;

    if (x1Rec2 > x2Rec1 || x2Rec2 < x1Rec1) {
        x = 0;
    } else {
        printf("point1x: %d \npoint2x: %d\n", (x1Rec1 > x1Rec2 ? x1Rec1 : x1Rec2), (x2Rec1 < x2Rec2 ? x2Rec1 : x2Rec2));

        /* Calculates the 2 x-points from the overlapping area points.
         * x will be the length of the x-line of the overlapping area.
         * The left part of the x calculates the left-bottom x and
         * the right part calculates the top-right x.
         * If rectangle 1 is more left than rectangle 2,
         * it will give x1Rec2 and x2Rec1, other way around it will give x1Rec1, x2Rec2 */
        x = (x1Rec1 > x1Rec2 ? x1Rec1 : x1Rec2) - (x2Rec1 < x2Rec2 ? x2Rec1 : x2Rec2);
    }

    if (y1Rec2 > y2Rec1 || y2Rec2 < y1Rec1) {
        y = 0;
    } else {
        printf("point1y: %d \npoint2y: %d\n", (y1Rec1 > y1Rec2 ? y1Rec1 : y1Rec2), (y2Rec1 < y2Rec2 ? y2Rec1 : y2Rec2));

        /* Because I made sure to always put the rectangle with the lowest
         * y-point as rectangle1, the y-point1 value is always y1Rec2 */
        y = (y1Rec1 > y1Rec2 ? y1Rec1 : y1Rec2) - (y2Rec1 < y2Rec2 ? y2Rec1 : y2Rec2);
    }

    int a = x * y;

    printf("%d\n", a);
}