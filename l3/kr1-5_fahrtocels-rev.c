/* Exercise 1-5. Modify the temperature conversion program to print the table in reverse order,
   that is, from 300 degrees to 0.
*/

#include <stdio.h>

#define UPPER_BOUND 300

// Prototype
float fahr_to_cels(float a_fahr);

int main()
{
    printf("from fahrtocels-reverse...\nFahrenheit | Celsius\n");
    for (int fahr = UPPER_BOUND - 20; fahr >= 0; fahr -= 20)
    {
        printf("%4d       | %6.1f\n", fahr, fahr_to_cels(fahr));
    }
    printf("--------------------\n");
    return 0;
}

float fahr_to_cels(float a_fahr)
{
    return (5.0 / 9.0) * (a_fahr - 32.0);
}
