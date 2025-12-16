/* Exercise 3-3. In a 2's complement number representation, our version of itoa does not handle the largest
   negative number, that is, the value of n equal to -(2wordsize-1). Explain why not. Modify it to print
   that value correctly, regardless of the machine it runs on.
   (Why?)-> Signed binary numbers can represent 2^w possible values (`w=number of bits`): -2^(w-1) to 2^(w-1)-1
            Since getting the 2's compliment of a value is ~val+1, when getting the compliment of
            the most negative number we get an overflow, as in: n = -8 (0b1000)
                                                                ~n = 0b0111
                                                                n + 1 = 0b1000
            Because the first version of itoa converts a negative number to a positive before processing,
            it would fail to process the most negative number.
*/

#include <stdio.h>

void itoa(int n, char *s);
void reverse(char *s, int len);
int str_len(char *s);
unsigned int wordlength();

int main()
{
    char s[12];
    int n = -1568976512;
    itoa(n, s);
    printf("Negative number test:\n\tn =  %d\n\ts = \"%s\"\n", n, s);

    n = 1 << (wordlength() - 1);
    itoa(n, s);
    printf("Largest negative number test:\n\tn =  %d\n\ts = \"%s\"\n", n, s);

    n = ~0u >> 1u;
    itoa(n, s);
    printf("Largest positive number test:\n\tn =  %d\n\ts = \"%s\"\n", n, s);

    return 0;
}

void itoa(int n, char *s)
{
    int i, sign;

    // Always process negative numbers and just add the sign accordingly
    if ((sign = n) > 0)
        n = -n;

    i = 0;
    do
    {
        s[i++] = -(n % 10) + '0';
    } while((n /= 10) != 0);

    if (sign < 0)
        s[i++] = '-';

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
