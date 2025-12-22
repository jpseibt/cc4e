/* Exercise 3-1. Write a function expand(s, t) which converts characters like newline and tab
   into visible escape sequences like \n and \t as it copies the string s to t. Use a switch.
*/

#include <stdio.h>

#define SIZE 255

void expand(char *s, char *t, int len);

int main()
{
    char s[SIZE] = "abc\tdefg\nhi\tjk\tl\nmnop\n";
    char t[SIZE];
    expand(s, t, SIZE);
    printf("s = \"%s\"\nt = \"%s\"\n", s, t);
    return 0;
}

void expand(char *s, char *t, int len)
{
    int i, j, c;
    i = j = 0;

    // Check if there's space to right 2 chars
    for (c = s[0]; c != '\0' && j < len - 2; c = s[++i], ++j)
    {
        switch (c)
        {
            case '\n':
                t[j] = '\\';
                t[++j] = 'n';
                break;
            case '\t':
                t[j] = '\\';
                t[++j] = 't';
                break;
            default:
                t[j] = c;
                break;
        }
    }

    if (c != '\0' && j < len - 1 && c != '\n' && c != '\t')
        t[j++] = c;

    t[j] = '\0';
}
