/* Exercise 1-22. Write a program to remove all comments from a C program. Don't
   forget to handle quoted strings and character constants properly.
*/

#include <stdio.h>

int main()
{
    int c, prev_c = 0, in_comment = 0, in_str = 0, in_char = 0;

    while ((c = getchar()) != EOF)
    {
        if (!in_comment && !in_str && !in_char)
        {
            switch (c)
            {
                case '"':
                    in_str = 1;
                    putchar(c);
                    break;
                case '\'':
                    in_char = 1;
                    putchar(c);
                    break;
                case '*':
                    if (prev_c == '/')
                        in_comment = 1;
                    break;
                case '/':
                    if (prev_c == '/')
                        in_comment = 1;
                    break;
                default:
                    if (prev_c == '/' || prev_c == '*')
                        putchar(prev_c);
                    putchar(c);
            }
        }
        else if (in_comment)
        {
            if (c == '/' && prev_c == '*')
            {
                in_comment = 0;
                c = 0; // Prevent prev_c of being printed
            }
        }
        else if (in_str)
        {
            if (c == '"' && prev_c != '\\')
                in_str = 0;
            putchar(c);
        }
        else if (in_char)
        {
            if (c == '\'' && prev_c != '\\')
                in_char = 0;
            putchar(c);
        }

        prev_c = c;
    }
    return 0;
}
