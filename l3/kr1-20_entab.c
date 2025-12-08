/* Exercise 1-20. Write the program entab which replaces strings of blanks by the minimum number
   of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
*/

#include <stdio.h>

#define TAB_WIDTH 8

int main()
{
    int c, i, column = 0, nspaces = 0, next_tabstop;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            ++nspaces;
        }
        else
        {
            while (nspaces)
            {
                next_tabstop = TAB_WIDTH - (column % TAB_WIDTH);
                if (nspaces >= next_tabstop)
                {
                    putchar('>');
                    column += next_tabstop;
                    nspaces -= next_tabstop;

                }
                else
                {
                    for (i = 0; i < nspaces; ++i)
                    {
                        putchar('.');
                    }
                    column += nspaces;
                    nspaces = 0;
                }
            }
            putchar(c);
            column = (c == '\n') ? 0 : ++column;
        }
    }
    return 0;
}
