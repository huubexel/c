/* file: sumSelection.c */
/* author: Huub Exel (email: h.exel@student.rug.nl) */
/* date: Thu Oct 06 2022 */
/* version: 1.0 */

/* Description:
 * Input:
 * Output:
 */

#include <stdio.h>
#include <stdlib.h>

void descend(int *numArr, int arrSize) {
    int i, j, temp;


    /* for the comments let's call, the current element of this for loop, the elem to be checked */
    for (i = 0; i < arrSize; i++) { /* for every array element */

        /* iterate through all the elements behind i */
        for (j = i + 1; j < arrSize; j++) {

            /* if the elem to be checked is smaller than one of the elements behind it */
            if (numArr[i] < numArr[j]) {
                /* swap the elem to be checked with the current elem */
                temp = numArr[i];
                numArr[i] = numArr[j];
                numArr[j] = temp;
            }
        }
    }
}





int main() {
    /* Input */
    int biggerNumCount = 0;
    int targetSum, tempNum;
    scanf("%d", &targetSum);

    /* numArray is here the address of the first location of the array */
    int *numArray = (int *)malloc(sizeof(int) * 10);

    for (int i = 0; i < (10 - biggerNumCount); i++) { /* Fill the array with the second line */
        scanf("%d", &tempNum);
        if (tempNum > targetSum) {
            biggerNumCount++;
            i--;
        } else {
            numArray[i] = tempNum;
        }
    }

    /* reallocation of the possible numbers array if possible */
    if (biggerNumCount) {
        numArray = (int *)realloc(numArray, (sizeof(int) * (10 - biggerNumCount)));
    }

    descend(numArray, (10 - biggerNumCount)); /* descend the ints in the array list */

    for (int j = 0; j < (10 - biggerNumCount); j++) {
        printf("%d ", numArray[j]);
    }


    return 0;
}



//    for (int j = 0; j < (10-biggerNumCount); j++) {
//        printf("%d ", actualArray[j]);
//    }

