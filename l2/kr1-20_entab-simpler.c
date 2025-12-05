/* Exercise 1-20. Write the program entab which replaces strings of blanks by the minimum number
   of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
*/

#include <stdio.h>

#define TAB_WIDTH 8

int main()
{
    int c;
    int column = 0;
    int space_count = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            // Check if on a tab stop
            if ((column + 1) % TAB_WIDTH == 0)
            {
                putchar('\t');
                column++;
                space_count = 0; // Tab replaced buffered spaces
            }
            else
            {
                space_count++;
                column++;
            }
        }
        else
        {
            while (space_count > 0)
            {   // Print buffered spaces.
                putchar(' ');
                space_count--;
            }

            putchar(c);

            if (c == '\n')
            {   // Reset for newlines
                column = 0;
            }
            else
            {
                column++;
            }
        }
    }
    return 0;
}
