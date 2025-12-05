/* Exercise 1-7. Write a program to copy its input to its output, replacing each string of one or
   more blanks by a single blank.
*/

#include <stdio.h>

bool is_blank(char a_char);

int main()
{
    int c, bc = 0;
    while ((c = getchar()) != EOF)
    {
        if (is_blank(c))
        {
            if (bc++ < 1)
                printf("%c", c);
        }
        else
        {
            bc = 0;
            printf("%c", c);
        }
    }
    return 0;
}

bool is_blank(char a_char)
{
    switch (a_char)
    {
        case ' ':
            break;
        case '\n':
            break;
        case '\t':
            break;
        case '\r':
            break;
        case '\v':
            break;
        default:
            return false;
    }
    return true;
}
