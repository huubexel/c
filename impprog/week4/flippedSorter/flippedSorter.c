/* file: flippedSorter.c */
/* author: Huub Exel (email: h.exel@student.rug.nl) */
/* date: Thu Oct 06 2022 */
/* version: 1.0 */

/* Description:
 * Input:
 * Output:
 */

#include <stdio.h>

// (10,82) (34,1) (100,64)#

int swapNumbers(int start, end, int fullArray[lenArray]) {
    return 0;
}

int main() {
    int lenArray, numb, startingNumb, endingNumb;
    scanf("%d", &lenArray); /* Get array length */

    int array[lenArray];

    /* Fill the array with the input */
    for (int i = 0; i < lenArray; i++) {
        scanf("%d", &numb);
        array[i] = numb;
    }

    char c;
    while (c != '#') {
        c = getchar();
        scanf("(%d,%d)", &startingNumb, &endingNumb);

        swapNumbers(startingNumb, endingNumb, &array[lenArray]);
    }

    return 0;
}