/* file: numberAnagram.c */
/* author: Huub Exel (email: h.exel@student.rug.nl) */
/* date: Tue Sep 27 2022 */
/* version: 1.0 */

/* Description:
 * This program takes two integers and checks whether they are anagrams of each other.
 */

#include <stdio.h>

int main() {
    /* Input */
    int budget, c, numberRolled;
    scanf("%d\n", &budget); /* scanf the budget on separate first line */

    while (c != '\n') {
        scanf("%d", &numberRolled);
        c = getchar();

        // dus wat je moet doen is dat nummer meegeven aan een functie, dus iets met een pointer?
        // dit meegeven samen met het budget,
        // Dan aan de hand van welke nummer het is het budget + winst of bust meegeven en daar
        // dan voor het volgend nummer iets mee doen.

        // gebruik een functie die niks returned
    }



    return 0;

}


// INPUT
// BOVENAAN: hoeveel geld de speler heeft (totale budget voor de avond)
// daaronder: nummers die gedraaid worden, met een -1 op het eind.
// Wat eruit moet komen is hoeveel geld de speler op het eind van de avond heeft of dat ie bust is.