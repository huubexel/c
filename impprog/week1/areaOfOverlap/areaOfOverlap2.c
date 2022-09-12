/* file: areaOfOverlap.c */
/* author: Huub Exel (email: h.exel@student.rug.nl) */
/* date: Sat Sep 11 2022 */
/* version: 1.0 */

/* Description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Voor het compleet omcirkelen moet je wat anders maken

int main(int argc, char *argv[]) {
    int x, y;
    x = 0;
    y = 0;

    int calc1, calc2, calc3, calc4;

    int x1Rect1, y1Rect1, x2Rect1, y2Rect1;
    int x1Rect2, y1Rect2, x2Rect2, y2Rect2;
    scanf("%d %d %d %d", &x1Rect1, &y1Rect1, &x2Rect1, &y2Rect1);
    scanf("%d %d %d %d", &x1Rect2, &y1Rect2, &x2Rect2, &y2Rect2);

    // The x part is completely finished and works every way possible!
    if (x1Rect2 > x2Rect1 || x2Rect2 < x1Rect1) {
        x = 0;
        printf("het is x\n");
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
        x = calc1 - calc2;
    }


    // The y part should be completely revisited. And just thought of quite good.
    if (y1Rect2 > y2Rect1 || y2Rect2 < y1Rect1) {
        y = 0;
        printf("het is y\n");
    } else {
        if (x2Rect1 < y2Rect2) {
            calc3 = x2Rect1;
        } else {
            calc3 = y2Rect2;
        }

        if (y1Rect1 < x2Rect2) {
            calc4 = y1Rect1;
        } else {
            calc4 = x2Rect2;
        }

        printf("calc3 %d calc4 %d\n", calc3, calc4);
        if (calc4 < 0) {
            y = calc3 + calc4;
        } else {
            y = calc3 - calc4;
        }

        if (y < 0) {
            y = y * -1;
        }
    }

    int a = x * y;

    printf("%d", a);

}