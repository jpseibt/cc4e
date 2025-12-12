/* Exercise 2-8. Write the function invert(x, p, n) which inverts (i.e., changes 1 into 0 and vice versa)
   the n bits of x that begin at position p, leaving the others unchanged.
*/

#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n);
unsigned int wordlength();
void printbits(unsigned int x);

int main()
{
    printf("%d\n", wordlength());
    unsigned int x = 0x42, p = 5, n = 4;
    printf("x = %#x -> ", x);
    printbits(x);

    unsigned int xi = invert(x, p, n);
    printf("\ninvert n=%d bits of x from position p=%d\nxi = %#x -> ", n, p, xi);
    printbits(xi);

    printf("\n");
    return 0;
}

unsigned int invert(unsigned int x, int p, int n)
{
    unsigned int inverted_mask = (~0u >> (wordlength() - n)) << (p - n + 1);
    return x ^= inverted_mask;
}

unsigned int wordlength()
{
    unsigned int x = ~0u, count = 0;
    for (; x != 0; ++count)
        x >>= 1;
    return count;
}

void printbits(unsigned int x)
{
    int num_bits = wordlength();
    for (int i = num_bits - 1; i >= 0; --i)
    {
        unsigned int mask = 1u << i;
        printf("%c", (x & mask) ? '1' : '0');
        if (i != 0 && i % 8 == 0)
            printf(" ");
    }
}
