#include <stdio.h>

int main()
{
    float fahrenheit, celsius;
    int upper, step;

    while (fahrenheit <= upper) {
        celsius = (5.0/9.0) * (fahrenheit-32.0);
        printf("%3.0f %6.1f\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + step;
    }
}
