#include <stdio.h>

#define UPPER 300
#define STEP 20
#define LOWER 0

int main()
{
    int fahr;

    printf("Fahrenheit   Celsius\n");
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%10d   %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
