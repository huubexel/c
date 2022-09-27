/* file: martingaleRed.c */
/* author: Huub Exel (email: h.exel@student.rug.nl) */
/* date: Tue Sep 27 2022 */
/* version: 1.0 */

/* Description:
 * Input: a starting amount of money (the budget), numbers on the roulette wheel where the ball landed on,
 * followed by the -1 (this must be the last number) to end it and count how much the player has won or lost that day.
 * If the player has less money than the martingale red strategy requires for a bet, print BUST and end program.
 * The program simulates a game of roulette where the user bets 1 euro as starting bet and plays with
 * the martingale red strategy.
 * Output: print BUST if the condition above is met, otherwise print how much money the player has at the end.
 */

#include <stdio.h>
#include <stdlib.h>

void gameHandler(int *pBudget, int num, int *pBet) {
    if (*pBudget >= *pBet) { /* if you have enough budget to bet at least 1 more time */
        if (((num%2 || num == 1) && (((num > 0) && (num < 10)) || ((num > 18) && (num < 28)))) ||
            ((!(num%2)) && (((num > 10) && (num <= 18)) || ((num > 28) && (num < 37))))) {
            /* Rolled a red! */
            *pBudget += (*pBet * 2) - 1;
            *pBet = 1;
        } else { /* Rolled a black/green */
            /* so you'll have to bet double to get your money back + 1 unit profit */
            *pBudget -= *pBet * 2;
            *pBet *= 2;
        }
    } else {
        /* You don't have enough money to afford this strategy anymore,
         * the next bet you'll do will be over your budget, bust. */
        printf("BUST\n");
        exit(0);
    }
}

int main() {
    /* Input and arrange variables */
    int budget, numberRolled, c;
    int bet = 1; /* You bet 1 euro in the first round */
    scanf("%d\n", &budget);
    budget = budget - bet; /* the 1 euro has to come out of your budget */

    while (c != '\n') {
        scanf("%d", &numberRolled);

        /* checking whether the user of this program filled in a roulette number */
        if (numberRolled > 36 || numberRolled < -1) {
            printf("You filled in a number that is not an a roulette wheel.\n");
            printf("Exiting program ...\n");
            exit(0);
        }

        if (numberRolled >= 0) { /* If the number filled in is a legit roulette wheel number */
            gameHandler(&budget, numberRolled, &bet);
        } else { /* filled in -1, so you stopped betting */
            printf("%d\n", budget + bet);
            break;
        }

        c = getchar(); /* makes the while loop continue until the break; is called */
    }

    return 0;
}
