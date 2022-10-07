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


    /* How to get your stuff back? */
    for (int i = 0; i < counter; i++) {
        printf("%d\n", *(ptr+i));
    }

    return 0;
}
