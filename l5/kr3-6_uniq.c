/* Exercise 3-6. Write a program which copies its input to its output, except that
   it prints only one instance from each group of adjacent identical lines.
   (This is a simple version of the UNIX utility uniq.)
*/

#include <stdio.h>

#define BUFFER_SIZE 1000

int get_line(char *buf, int max);
int str_cmp(char *str0, char *str1);

int main()
{
    char buf0[BUFFER_SIZE], buf1[BUFFER_SIZE];
    // Pointers that swap buffers at each new line
    char *curr = buf0;
    char *prev = buf1;
    char *tmp;

    prev[0] = '\0';     // Initialize for first iteration
    while ((get_line(curr, BUFFER_SIZE)) > 0)
    {
        if (str_cmp(curr, prev) != 0)
            printf("%s\n", curr);

        tmp = prev;
        prev = curr;
        curr = tmp;
    }

    return 0;
}

int get_line(char *buf, int max)
{
    int i, c;
    for (i = 0, c = getchar(); i < max - 1 && c != EOF && c != '\n'; ++i, c = getchar())
    {
        buf[i] = c;
    }
    buf[i] = '\0';

    if (i == 0 && c == EOF)
        return -1;
    return i;
}

int str_cmp(char *str0, char *str1)
{
    int i = 0;
    while (str0[i] == str1[i])
    {
        if (str0[i] == '\0')
            return 0;
        ++i;
    }
    return str0[i] - str1[i];
}
