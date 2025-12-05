/* Exercise 1-19. Write a program detab which replaces tabs in the input with the proper number
   of blanks to space to the next tab stop. Assume a fixed set of tab stops, say
   every n positions.
*/

#include <stdio.h>

#define TAB_WIDTH 8

int main()
{
    int c, i = 0, column = 0, tabstop = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            tabstop = TAB_WIDTH - (column % TAB_WIDTH);
            for (i = 0; i < tabstop; ++i)
            {
                putchar('.'); // Whitespace
            }
            column += tabstop;
        }
        else if (c == '\n')
        {
            putchar(c);
            column = 0;
        }
        else
        {
            putchar(c);
            ++column;
        }
    }
    return 0;
}
