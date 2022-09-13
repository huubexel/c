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

    /* For my equation I will need the two points to be the bottom-left point
     * and the top-right point, this will make sure that is the case */
    int x1Rect1, y1Rect1, x2Rect1, y2Rect1;
    int x1Rect2, y1Rect2, x2Rect2, y2Rect2;
    if (int1 > int3) {
        x2Rect1 = int1;
        x1Rect1 = int3;
    } else {
        x2Rect1 = int3;
        x1Rect1 = int1;
    }

    if (int2 > int4) {
        y2Rect1 = int2;
        y1Rect1 = int4;
    } else {
        y2Rect1 = int4;
        y1Rect1 = int2;
    }

    if (int5 > int7) {
        x2Rect2 = int5;
        x1Rect2 = int7;
    } else {
        x2Rect2 = int7;
        x1Rect2 = int5;
    }

    if (int6 > int8) {
        y2Rect2 = int6;
        y1Rect2 = int8;
    } else {
        y2Rect2 = int8;
        y1Rect2 = int6;
    }

    /* The rectangle, which lowest x is higher than the other rectangles'
     * lowest x, has to be rectangle1 in my equation, if that is not the case
     * switch the two rectangles */
    if (x1Rect1 < x1Rect2) {
        int temp1, temp2, temp3, temp4;
        temp1 = x1Rect2;
        temp2 = y1Rect2;
        temp3 = x2Rect2;
        temp4 = y2Rect2;
        x1Rect2 = x1Rect1;
        y1Rect2 = y1Rect1;
        x2Rect2 = x2Rect1;
        y2Rect2 = y2Rect1;
        x1Rect1 = temp1;
        y1Rect1 = temp2;
        x2Rect1 = temp3;
        y2Rect1 = temp4;
    }

    printf("%d %d %d %d\n", x1Rect1, y1Rect1, x2Rect1, y2Rect1);
    printf("%d %d %d %d\n", x1Rect2, y1Rect2, x2Rect2, y2Rect2);


    int x, y;
    int calc1, calc2, calc3, calc4;
    if (x1Rect2 > x2Rect1 || x2Rect2 < x1Rect1) {
        x = 0;
    } else {
        if (x2Rect1 < x2Rect2) {
            calc1 = x2Rect1;
        } else {
            calc1 = x2Rect2;
        }
        if (x1Rect1 > x1Rect2) {
            calc2 = x1Rect1;
        } else {
            calc2 = x1Rect2;
        }
        printf("calc1 %d calc2 %d\n\n", calc1, calc2);
        x = calc1 - calc2;
    }


    // The y part should be completely revisited. And just thought of quite good.
    if (y1Rect2 > y2Rect1 || y2Rect2 < y1Rect1) {
        y = 0;
        printf("het is y\n");
    } else {
        if (y2Rect1 < y2Rect2) {
            calc3 = y2Rect1;
        } else {
            calc3 = y2Rect2;
        }

        if (y1Rect1 > y1Rect2) {
            calc4 = y1Rect1;
        } else {
            calc4 = x2Rect2;
        }

        // wat je uit moet rekenen is de afstand van het lijntje
        // dus stel de lijn loopt van 1 tm -2 dan wordt het dus 1 - - 2
        printf("calc3 %d calc4 %d\n\n", calc3, calc4);

        y = calc3 - calc4;
    }

    int a = x * y;

    printf("%d\n", a);

}