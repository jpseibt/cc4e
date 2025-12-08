/* Exercise 1-13. Write a program to convert its input to lower case, using a function lower(c)
   which returns c if c is not a letter, and the lower case value of c if it is a letter.
*/

#include <stdio.h>

char lower(char c);

int main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        putchar(lower(c));
    }
    return 0;
}

char lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    return c;
}
