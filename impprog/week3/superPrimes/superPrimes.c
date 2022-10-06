/* file: superPrimes.c */
/* author: Huub Exel (email: h.exel@student.rug.nl) */
/* date: Tue Sep 27 2022 */
/* version: 1.0 */

/* Description:
 *
 */

#include <stdio.h>
#include <stdlib.h>

int sieveOfEratosthenes(int n) {
    // Wat je kunt doen is inderdaad deze sieve gebruiken of je kunt
    // beter kijken https://algorithms.tutorialhorizon.com/find-all-prime-numbers-less-than-equal-to-n/
    // naar de onderste van deze 2 versies.
    if ((!(n%2))||(!(n%3))||(!(n%5))||(!(n%7))||(n!=1))) {
        return 1;
    } else{
        return 0;
    }
}

int main() {
    /* Input */
    int inp1, inp2;
    scanf("%d %d", &inp1, &inp2);
    int tOrf = sieveOfEratosthenes(inp1);
    printf("%d", tOrf);
}