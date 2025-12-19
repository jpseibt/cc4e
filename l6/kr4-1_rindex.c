/* Exercise 4-1. Write the function rindex(s, t), which returns the position of
   the rightmost occurrence of t in s, or -1 if there is none.
*/

#include <stdio.h>

#define BUFFER_SIZE 1000

int rindex(char *s, char *t);
int get_line(char *s, int max);
unsigned int str_len(char *s);

int main()
{
    char buffer[BUFFER_SIZE];

    while (get_line(buffer, BUFFER_SIZE) > 0)
    {
        if (rindex(buffer, "the") >= 0)
            printf("-> %s", buffer);
    }

    return 0;
}

int rindex(char *s, char *t)
{
    for (int i = str_len(s) - str_len(t), j, k; i >= 0 && s[i] != '\0'; --i)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k)
            ;
        if (t[k] == '\0')
            return i;
    }
    return -1;
}

int get_line(char *buf, int max)
{
    int i, c;

    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        buf[i] = c;
    }
    if (c == '\n')
    {
        buf[i++] = c;
    }
    buf[i] = '\0';

    if (i == 0 && c == EOF)
    {
        return -1;
    }
    return i;
}

unsigned int str_len(char *s)
{
    char *p = s;
    while (*p != '\0')
        ++p;
    return p - s;
}

