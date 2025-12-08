/* Exercise 1-10. Write a program which prints the words in its input, one per line. */

#include <stdio.h>

int main()
{
    int c = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            putchar('\n');
        }
        else
        {
            putchar(c);
        }
    }
    return 0;
}
