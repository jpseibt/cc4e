/* Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table. */

#include <stdio.h>

#define UPPER_BOUND 300

// Prototype
float fahr_to_cels(float a_fahr);

int main()
{
    int step = 20;
    float fahr = 0.0, cels = 0.0;

    printf("from fahrtocels...\nFahrenheit | Celsius\n");
    while (fahr < UPPER_BOUND)
    {
        printf("%4.0f       | %6.1f\n", fahr, fahr_to_cels(fahr));
        fahr += step;
    }
    printf("--------------------\n");
    return 0;
}

float fahr_to_cels(float a_fahr)
{
    return (5.0 / 9.0) * (a_fahr - 32.0);
}
