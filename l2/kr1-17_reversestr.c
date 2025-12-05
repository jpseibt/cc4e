/* Exercise 1-17. Write a function reverse(s) which reverses the character string s.
   Use it to write a program which reverses its input a line at a time.
*/

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 256

void reverse(char *s, int len);
int get_line(char *buffer, int maxl);

int main(int argc, char** argv)
{
    char line_buffer[MAX_SIZE];
    printf("input: ");
    while (get_line(line_buffer, MAX_SIZE) > 0)
    {
        reverse(line_buffer, strlen(line_buffer));
        printf("reversed: %s\ninput: ", line_buffer);
    }
}

void reverse(char *s, int len)
{
    int tail = len - 1;
    char c;
    for (int i = 0; i < tail; ++i)
    {
        tail = len - 1 - i;
        if (tail > i)
        {
            c = s[i];
            s[i] = s[tail];
            s[tail] = c;
        }
    }
}

int get_line(char *buffer, int maxl)
{
    int c, i;
    for (i = 0; i < maxl - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        buffer[i] = c;
    }
    buffer[i] = '\0';
    return i;
}
