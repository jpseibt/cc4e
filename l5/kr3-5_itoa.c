/* Exercise 3-5. Write a version of itoa which accepts three arguments instead of two.
   The third argument is a minimum field width; the converted number must be padded
   with blanks on the left if necessary to make it wide enough.
*/

#include <stdio.h>

void itoa(int n, char *s, int field);
void reverse(char *s, int len);
unsigned int str_len(char *s);
int wordlength();

int main()
{
    int n = -42;
    int field = 6;
    char s[wordlength() + 2]; // + sign and terminator

    itoa(n, s, field);
    printf("Negative number test:\n\tn =  %d\n\ts = \"%s\" (field=%d)\n", n, s, field);

    n = 1 << (wordlength() - 1);
    field = 12;
    itoa(n, s, field);
    printf("Largest negative number test:\n\tn =  %d\n\ts = \"%s\" (field=%d)\n", n, s, field);

    n = ~0u >> 1u;
    field = 18;
    itoa(n, s, field);
    printf("Largest positive number test:\n\tn =  %d\n\ts = \"%s\" (field=%d)\n", n, s, field);

    return 0;
}

void itoa(int n, char *s, int field)
{
    int i, sign;

    sign = n;
    if (n > 0)
        n = -n;

    i = 0;
    do
    {
        s[i++] = -(n % 10) + '0';
    } while ((n /= 10) != 0);

    if (sign < 0)
        s[i++] = '-';

    int w = wordlength() + 2; // + sign and terminator
    while (i < field && i < w)
        s[i++] = ' ';

    s[i] = '\0';
    reverse(s, str_len(s));
}

void reverse(char *s, int len)
{
    for (int i = 0, j = len - 1, c; i < j; ++i, --j)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    s[len] = '\0';
}

unsigned int str_len(char *s)
{
    char *p = s;
    while (*p != '\0')
        ++p;
    return p - s;
}

int wordlength()
{
    unsigned x, count;
    for (x = ~0u, count = 0; x != 0; x >>= 1, ++count)
        ;
    return count;
}
