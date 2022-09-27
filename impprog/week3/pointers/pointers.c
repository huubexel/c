#include <stdio.h>

void func (int a, int *b) {
    // a is hier de waarde 3
    // *b is de waarde in de locatie van n
    // zou je hier alleen maar b printen dan print je de locatie van n

    a = 7 ;
    // a is nu de waarde 7, de rest is hetzelfde.

    *b = a ;
    // b = adres, *b is de waarde in dat hokje.
    // dus nu: het adres/huis van n heeft al inwoner 5, echter wordt dat nu 7.
    // dus nu is n = 7.

    // Door dit te doen veranderd b van het adres van &n (*b was de waarde in het adres van n)
    // naar het adres van a, dus alles wat hierna gebeurt, heeft geen effect meer op n.
    b = &a ;
    // b is het adres van *b wat een gewonen var is.
    // Dus je zou b hiervoor ook uit kunnen printen (zonder te initialiseren) en dan print je het adres van *b
    // Dus in het adres b dus in het hokje/huisje b stop je nu het adres van a.
    // Dus alles wat er nu voor a gebeurt, gebeurt ook voor *b.
    // b en &a zijn nu allebei het adres van a.


    *b = 4 ;
    // *b is de daadwerkelijk waarde van b
    // b is het adres van a
    // dus dit is de daadwerkelijk waarde van wat er in a zit.
    // dus hiermee maak je a 4 en je maakt *b maak je vier
    // b is nogsteeds het adres van a, &a is ook het nogsteeds het adres van a.


    printf("%d, %d\n", a, *b) ;
}

int main() {
    int m = 3, n = 5;
    // m is hier de waarde 3
    // n is hier de locatie n bijvoorbeeld locatie 0x1020
    func(m, &n);
    printf("%d, %d\n", m, n) ;
    return 0;
}