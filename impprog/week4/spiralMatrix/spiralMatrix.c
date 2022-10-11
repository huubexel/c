/* file: spiralMatrix.c */
/* author: Huub Exel (email: h.exel@student.rug.nl) */
/* date: Thu Oct 06 2022 */
/* version: 1.0 */

/* Description:
 * Input:
 * Output:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sqrtCheck(int counter) {
    /* This checks whether you can actually make it into a spiral and if not, stop the program!
     * and also return the sqrt of counter */
    double sqRootCounter = sqrt(counter);
    int sqRC = sqRootCounter;

    if((sqRC * sqRC) != counter) {
        printf("Sorry! It is not possible to make a spiral out of this!\n");
        exit(0);
    }

    return sqRC;
}

void *safeMalloc(int n) {
    void *p = malloc(n);
    if (p == NULL) {
        printf("Error: malloc(%d) failed. Out of memory?\n", n);
        exit(EXIT_FAILURE);
    }
    return p;
}

int main() {
    int counter = 0;

    /* malloc the amount of ints, typecast it to an int pointer and
     * store it in the int --> int *ptr
     * int ptr is the address of the first byte of the block data allocated, if I am not mistaken */
    int *ptr = (int *) safeMalloc(sizeof(int));

    /* Get all the integer characters with this do-while */
    do {
        scanf("%d", (ptr + counter));
        counter++;
        ptr = (int *)realloc(ptr, (sizeof(int) * (counter + 1)));
    } while(getchar() != '\n');

    /* Check whether it is possible to make a spiral and return de sqrt of counter */
    int sqrtCounter = sqrtCheck(counter);

    /* How to get your stuff back? */
    for (int i = 0; i < counter; i++) {
        printf("%d\n", *(ptr+i));
    }

    return 0;
}
