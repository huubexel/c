/* file: areaOfOverlap.c */
/* author: Huub Exel (email: h.exel@student.rug.nl) */
/* date: Sat Sep 17 2022 */
/* version: 1.0 */

/* Description:
 * This program takes 8 integers on 2 lines (4 per line) as input.
 * Each line are 2 points of one rectangle, these points must be
 * the exact opposite of each other: (bottom-left && top-right) || (bottom-right && top-left).
 * For each point, you have to fill in the x-value first, and second the y-value.
 * The output gives you the area of overlap of the 2 rectangles.
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
     * Rec1 --> from rectangle 1, Rec2 being from rectangle 2 */
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

    if ((x1Rec2 > x2Rec1 || x2Rec2 < x1Rec1) || (y1Rec2 > y2Rec1 || y2Rec2 < y1Rec1)) {
        /* If this is true, then there is no area of overlap. */
        printf("0\n");
    } else {
        int x, y;

        /* x = length of the line between bottom-left point and bottom-right point, from area of overlap.
         * Left part of x calculates the bottom-left x-value of overlapping area.
         * Right part of x calculates the bottom-right x-value of overlapping area.
         * If rectangle 1 is left from rectangle 2, x = x1Rec2 - x2Rec1,
         * other way around x = x1Rec1 - x2Rec2 */
        x = (x1Rec1 > x1Rec2 ? x1Rec1 : x1Rec2) - (x2Rec1 < x2Rec2 ? x2Rec1 : x2Rec2);

        /* y = length of the line between bottom-left point and top-left point, from area of overlap.
         * Left part of y calculates the bottom-left y-value of overlapping area.
         * Right part of y calculates the top-left y-value of overlapping area.
         * If rectangle 1 is higher than rectangle 2, y = y1Rec1 - y2Rec2,
         * other way around y = y1Rec2 - y2Rec1 */
        y = (y1Rec1 > y1Rec2 ? y1Rec1 : y1Rec2) - (y2Rec1 < y2Rec2 ? y2Rec1 : y2Rec2);

        printf("%d\n", x * y); /* Print area of overlap */
    }
    return 0;
}
