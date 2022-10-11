/* file: flippedSorter.c */
/* author: Huub Exel (email: h.exel@student.rug.nl) */
/* date: Mon Oct 11 2022 */
/* version: 1.0 */

/* Description:
 * Input: first line, the amount of numbers in the array
 *        second line, the numbers in the array
 *        third line, the segments that need to be swapped.
 * Output: YES || NO
 * This program looks whether the array you give it is ascending after it reversed
 * the segments from which the user gives the first and last index per segment.
 */

#include <stdio.h>
#include <stdlib.h>

int ascending(int elements, int *numbArray) {
    int numToCompare = numbArray[0];     /* Get number to compare with */

    /* for each number compare to the one before this one */
    for (int counter = 1; counter < elements; ++counter) {
        if (numbArray[counter] < numToCompare) {
            /* If the number you are comparing is smaller than the number before this one,
             * the array is not ascending return 0 */
            return 0;
        }
        numToCompare = numbArray[counter];
    }

    return 1; /* The array is ascending, return 1 */
}

void reverseSegment(int i1, int i2, int *numbArray) {
    int indexer1 = 0;
    int indexer2 = 0;
    int *tempArray = malloc(sizeof(int) * (i2 - i1 + 1)); /* temporary array for reversed elements */

    /* Add numbers to temporary array */
    for (int i = i2; i != i1 - 1; i--) {
        tempArray[indexer1] = numbArray[i];
        indexer1 += 1;
    }

    /* put the numbers from the temporary array in numbArray at the original spot */
    for (int j = i1; j <= i2; ++j) {
        numbArray[j] = tempArray[indexer2];
        indexer2 += 1;
    }

    free(tempArray); /* We don't need the tempArray no more, so free it's allocated memory here */
}

int main() {
    /* Input amount of elements in array */
    int amountOfElements;
    scanf("%d", &amountOfElements);
    int *numberArray = malloc(sizeof(int)*amountOfElements); /* memory allocation for array */

    /* Scan in the numbers from the second line of input and put them in numberArray */
    int num;
    for (int i = 0; i <= amountOfElements; ++i) {
        scanf("%d", &num);

        /* This removes the newline at the end of the input line */
        if (amountOfElements != i) {
            numberArray[i] = num;
        }
    }

    /* Input for segments to reverse, third line */
    int index1, index2;
    while (1) {
        int foundInput = scanf("(%d,%d)", &index1, &index2);
        if (!(foundInput)) {
            /* There is nothing to swap anymore and the '#' is found, so the input can be stopped */
            break;
        }

        /* Reverse the segment and put it back into the numberArray */
        reverseSegment(index1, index2, numberArray);
    }

    printf("%s\n", ascending(amountOfElements, numberArray) ? "YES" : "NO");

    free(numberArray); /* Free the space for the number array */
    return 0;
}
