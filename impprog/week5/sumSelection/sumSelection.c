/* file: sumSelection.c */
/* author: Huub Exel (email: h.exel@student.rug.nl) */
/* date: Fri Oct 14 2022 */
/* version: 1.0 */

/* Description:
 * Input:
 * Output:
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *members;
    int length;
} Set;

Set* init(); /* Set *setA = init(); */
bool is_empty(Set *set); /* you can use this as a function for example if (is_empty(setA)) {... */
void insert(Set *set, int member); /* insert(setA, 8); */
void print_set(Set *set); /* print_set(setA); */
Set *set_union(Set *setA, Set *setB); /* Set *setC = set_union(setA, setB); */
Set *set_intersection(Set *setA, Set *setB); /* Set *setC = set_intersection(setA, setB); */

/* Set *setC = set_difference(setA, setB); this is A - B, if you want B - A: set_difference(setA, setB)*/
Set *set_difference(Set *setA, Set *setB);
bool is_subset(Set *setA, Set *setB); /* is_subset(setA, setB); */
bool set_equality(Set *setA, Set *setB); /* set_equality(setA, setB); */
bool is_member(Set *setA, int value); /* is_member(setA, 10); */

Set* init() {
    Set *new_set = malloc(sizeof(Set));
    new_set->length = 0;
    new_set->members = malloc(sizeof(int));
    return new_set;
}

bool is_empty(Set *set) {
    return (set->length == 0);
}

void insert(Set *set, int member) {
    if (!is_member(set, member)) {
        set->members = realloc(set->members, sizeof(int) * (set->length + 1));
        set->members[set->length] = member;
        set->length += 1;
    }
}

void print_set(Set *set) {
    for (int i = 0; i < set->length; i++) {
        if (i + 1 == set->length) {
            printf("%d\n", set->members[i]);
        } else {
            printf("%d, ", set->members[i]);
        }
    }
}

Set *set_union(Set *setA, Set *setB) {
    Set *new = init();
    for (int i = 0; i < setA->length; i++) {
        insert(new, setA->members[i]);
    }

    for (int i = 0; i < setB->length; i++) {
        insert(new, setB->members[i]);
    }

    return new;
}

Set *set_intersection(Set *setA, Set *setB) {
    Set *new = init();

    for (int i = 0; i < setA->length; i++) {
        if (is_member(setB, setA->members[i])) {
            insert(new, setA->members[i]);
        }
    }

    return new;
}

Set *set_difference(Set *setA, Set *setB) {
    Set *new = init();

    for (int i = 0; i < setA->length; i++) {
        if (!is_member(setB, setA->members[i])) {
            insert(new, setA->members[i]);
        }
    }

    return new;
}

bool is_subset(Set *setA, Set *setB) {
    for (int i = 0; i < setA->length; i++) {
        if (!is_member(setB, setA->members[i])) {
            return false;
        }
    }
    return true;
}

bool set_equality(Set *setA, Set *setB) {
    if (setA->length != setB->length) {
        return false;
    }

    return is_subset(setA, setB);
}

bool is_member(Set *set, int value) {
    for (int i = 0; i < set->length; i++) {
        if (value == set->members[i]) {
            return true;
        }
    }
    return false;
}

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


int closeTheGap(int target, int j, int numbsLeft, int *arr, int *tempArr, int deLijst) {
    int *answerArray = (int *)malloc(sizeof(int) * (numbsLeft - j));

    int k = j; /* steal the number to put into the recursion later on */

    if ((numbsLeft - j) == (sizeof(deLijst) + 1)) { /* if there is only one left in the array */
        return 0;
    }

    int gap = 0; /* this is how much you have added now */
    int arrayIndex = 0;
    int i = j;
    while (i < numbsLeft) {
        /* arr[i] is the current number down the array */
        if (arr[i] < (target - gap)) {
            gap += arr[i];
            answerArray[arrayIndex] = arr[i];
            arrayIndex++;
        } else if (arr[i] == (target - gap)) {
            printf("hoera");
            insert(arr[i], &deLijst);
            closeTheGap(target, k, numbsLeft, arr, tempArr, deLijst);
        } else {
            insert(arr[i], &deLijst);
        }

        /* this is the current index in the array */
        i++;
    }
    /* If the gap is smaller than the target, and you used all indexes out of the tempArray */
    if ((gap < target) && (arrayIndex = )) { /* check array length here */
        insert(arr[1], &deLijst);
        closeTheGap(target, k, numbsLeft, arr, tempArr, deLijst);
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

    int numbersLeft = 10 - biggerNumCount;

    /* reallocation of the possible numbers array if possible */
    if (biggerNumCount) {
        numArray = (int *)realloc(numArray, (sizeof(int) * numbersLeft));
    }

    descend(numArray, numbersLeft); /* descend the ints in the array list */

    int *tempArray = (int *)malloc(sizeof(int) * numbersLeft);
    for (int currentArrInd = 0; currentArrInd < numbersLeft; currentArrInd++) {
        tempArray = (int *)realloc(tempArray, (sizeof(int) * (numbersLeft - currentArrInd)));
        for (int i = 0; i < (numbersLeft - currentArrInd); i++) {
            tempArray[i] = numArray[currentArrInd + i];
        }
        closeTheGap(targetSum, currentArrInd, numbersLeft, numArray, tempArray, create(int set[]));
    }

    return 0;
}



//    for (int j = 0; j < (10-biggerNumCount); j++) {
//        printf("%d ", actualArray[j]);
//    }
