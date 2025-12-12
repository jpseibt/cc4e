/* Exercise 2-7. Write the function rightrot(n, b) which rotates the integer n to the right by b bit positions. */

#include <stdio.h>

unsigned int rightrot(unsigned int n, unsigned int b);
unsigned int wordlength();
void printbits(unsigned int x);

int main()
{
    unsigned int n = 5, b = 1;
    printf("n = %#x -> ", n);
    printbits(n);

    unsigned int nr = rightrot(n, b);
    printf("\nn rotated by b=%d bits:\nnr = %#x -> ", b, nr);
    printbits(nr);

    printf("\n");
    return 0;
}

unsigned int rightrot(unsigned int n, unsigned int b)
{
    unsigned int rotated_bits = n << (wordlength() - b);
    n = (n >> b) | rotated_bits;

    return n;
}

unsigned int wordlength()
{
    unsigned int x = ~0, count = 0;
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
