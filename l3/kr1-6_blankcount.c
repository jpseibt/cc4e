/* Exercise 1-6. Write a program to count blanks, tabs, and newlines. */

#include <stdio.h>

bool is_blank(char a_char);

int main()
{
    int blanks = 0, c;
    while ((c = getchar()) != EOF)
    {
        if (is_blank(c))
            ++blanks;
    }
    printf("\nNumber of whitespace chars: %d\n", blanks);
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
