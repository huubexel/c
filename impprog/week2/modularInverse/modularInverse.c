#include <stdio.h>

int main() {
    /* Input */
    int inp1, inp2;
    scanf("%d %d", &inp1, &inp2);

    int len1, len2; /* This is where the length of inp1 and inp2 will go */

    /* get the length of both inputs */
    for (int i = 0; i < 2; i++) {
        int n;
        int count = 0; /* counts the number of digits */
        n = (!i) ? inp1 : inp2; /* get the input we are dealing with */

        /* I decided to keep 0 in if it is the only number put in for that integer
         * because 0 0 is an anagram, leading zeros are furthermore ignored */
        do {               /* Here we count the length of both inputs */
            n /= 10;
            ++count;
        } while (n != 0);

        /* Give the right count to the right number */
        if (!i) {
            len1 = count;
        } else {
            len2 = count;
        }
    }

    if (len1 == len2) {
        int magicNumber = 0;
        int magicNumberChecker = 0;
        int rem1 = 10;
        for (int i = 1; (i < (len1+1)); i++) {
            magicNumberChecker += (inp1 % rem1)/(rem1/10);

            int rem2 = 10;
            for (int j = 0; j < len2; j++) {
                if ((inp1 % rem1)/(rem1/10) == ((inp2 % rem2)/(rem2/10))) {
                    magicNumber += (inp2 % rem2)/(rem2/10);
                    break;
                }
                rem2 *= 10;
            }
            rem1 *= 10;
        }

        if (magicNumber == magicNumberChecker) {
            printf("YES\n");
        }
    } else {
        printf("NO\n");
    }

    return 0;
}
