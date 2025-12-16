/* Exercise 3-4. Write the analogous function itob(n, s) which converts the unsigned integer n
   into a binary character representation in s. Write itoh, which converts an integer to
   hexadecimal representation.
*/

#include <stdio.h>

void itob(unsigned n, char *s);
void itoh(int n, char *s);
void reverse(char *s, int len);
int str_len(char *s);
unsigned int wordlength();
void printbits(unsigned int x);

int main()
{
    char s[32];
    unsigned int n = 0xabcdef98;

    printf("Test itob:\n");
    printf("\tn = 0b");
    itob(n, s);
    printbits(n);
    printf("\n\ts = 0b");
    for (int i = 0; s[i] != '\0'; ++i)
    {
        printf("%c", s[i]);
        if ((i + 1) % 8 == 0)
            printf(" ");
    }
    printf("\n");

    printf("Test itoh:\n");
    n >>= 1;    // Fit n into a signed int
    itoh(n, s);
    printf("\tn = %#x\n\ts = 0x%s\n", n, s);

    return 0;
}

void itob(unsigned n, char *s)
{
    int i = 0;
    do
    {
        s[i++] = (n & 1u) ? '1' : '0';
    } while ((n >>= 1) != 0);

    s[i] = '\0';
    reverse(s, str_len(s));
}

void itoh(int n, char *s)
{
    unsigned int un, hexd;
    un = n;

    int i = 0;
    do
    {
        hexd = un & 0xFu;
        s[i++] = (hexd <= 9) ? hexd + '0' : hexd + 'a' - 10;
    } while ((un >>= 4) != 0);

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

int str_len(char *s)
{
    char *p = s;
    while (*p != '\0')
        ++p;
    return p - s;
}

unsigned int wordlength()
{
    unsigned x, count;
    for (x = ~0u, count = 0; x != 0; x >>= 1, ++count)
        ;
    return count;
}

void printbits(unsigned int x)
{
    for (int i = wordlength() - 1, mask; i >= 0; --i)
    {
        mask = 1u << i;
        printf("%c", (x & mask) ? '1' : '0');
        if (i != 0 && i % 8 == 0)
            printf(" ");
    }
}
