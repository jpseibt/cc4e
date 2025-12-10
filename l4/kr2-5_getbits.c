/* Exercise 2-5. Modify getbits to number bits from left to right.
   get n bits from position p
        getbits(x, p, n)
        unsigned x, p, n;
        {
            return((x >> (p+1-n)) &  ~(~0 << n));
        }
*/

#include <stdio.h>

unsigned int getbits(unsigned x, unsigned p, unsigned n);
void printbits(unsigned int x);

int main()
{
    unsigned x = 0xfffffffb, p = 29, n = 3;
    unsigned int xb = getbits(x, p, n);

    printf("x  = %#x -> ", x);
    printbits(x);
    printf("\nxb = %#x -> ", xb);
    printbits(xb);

    printf("\nFrom bit at position=%d the n=%d bits are: ", p, n);
    for (unsigned int i = 0; i < n; ++i)
    {
        unsigned int mask = 1u << (sizeof(unsigned int) * 8 - p - i - 1);
        printf("p=%d:%c ", p - i, (x & mask) ? '1' : '0');
    }
    printf("\n");

    return 0;
}

unsigned int getbits(unsigned x, unsigned p, unsigned n)
{
    unsigned int shift = sizeof(unsigned int) * 8 - (p + n);
    return (x >> shift) & ~(~0 << n);
}

void printbits(unsigned int x)
{
    int num_bits = sizeof(unsigned int) * 8;
    for (int i = num_bits - 1; i >= 0; --i)
    {
        unsigned int mask = 1u << i;
        printf("%c", (x & mask) ? '1' : '0');
        if (i != 0 && i % 8 == 0)
            printf(" ");
    }
}

