/* Exercise 1-14. Revise the main routine of the longest-line program so it will correctly print the length of
   arbitrarily long input lines, and as much as possible of the text.

   Exercise 1-15. Write a program to print all lines that are longer than 80 characters.
*/

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int get_line(char s[], int lim); /* get line into s, return length */
void copy(char s1[], char s2[]); /* copy s1 to s2; assume s2 big enough */

int main() /* find longest line */
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char save[MAXLINE]; /* longest line, saved */

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(line, save);
        }
        if (len > 80) {
            printf("Greater than 80 chars long: \"%s\"\n", line);
        }
    if (max > 0) /* there was a line */
        printf("Length: %d characters\nLine: \"%s\"", max, save);
}

int get_line(char s[], int lim) /* get line into s, return length */
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char s1[], char s2[]) /* copy s1 to s2; assume s2 big enough */
{
    int i;

    i = 0;
    while ((s2[i] = s1[i]) != '\0')
        ++i;
}
