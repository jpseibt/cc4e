/* Exercise 1-21. Write a program to "fold" long input lines after the last non-blank character
   that occurs before the n-th column of input, where n is a parameter. Make sure your program
   does something intelligent with very long lines, and if there are no blanks or tabs before the
   specified column.
*/

#include <stdio.h>

#define FOLD_COLUMN 81

int main()
{
    char line_buff[FOLD_COLUMN];
    int c, buff_idx = 0;

    while ((c = getchar()) != EOF)
    {
        if (buff_idx < (FOLD_COLUMN - 1))
        {
            line_buff[buff_idx++] = c;
        }
        else
        {
            line_buff[buff_idx] = c;

            // Process line. Start by finding the last blank
            int last_blank = 0;
            for (int i = buff_idx; i >= 0 && last_blank == 0; --i)
            {
                switch (line_buff[i])
                {
                    case ' ':
                    case '\n':
                    case '\t':
                        last_blank = i;
                        break;
                }
            }

            if (last_blank > 0)
            {   // Print the line up to the last blank before the fold column
                for (int i = 0; i <= last_blank; ++i)
                {
                    putchar(line_buff[i]);
                }
                putchar('\n');

                buff_idx = 0;
                for (int i = last_blank + 1; i < FOLD_COLUMN; ++i)
                {
                    line_buff[buff_idx++] = line_buff[i];
                }
            }
            else
            {   // Print all chars up to FOLD_COLUMN
                for (int i = 0; i < FOLD_COLUMN; ++i)
                {
                    putchar(line_buff[i]);
                }
                printf("-|\n");
                buff_idx = 0;
            }

        }
    }
    // Flush the buffer
    int end = buff_idx;
    for (int i = 0; i < end; ++i)
        putchar(line_buff[i]);

    printf(">>END\n");
    return 0;
}
