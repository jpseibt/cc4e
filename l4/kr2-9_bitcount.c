/* Exercise 2-9. In a 2's complement number system, x & ( x-1 ) deletes the rightmost 1-bit in x.
   (Why?)-> Because every subtraction by `1` in binary borrows from the rightmost `1` bit, fliping it to
            `0` and the next `k` bits to `1`. Then the AND operation flips the `k` bits back to `0`.
   Use this observation to write a faster version of bitcount.
       bitcount(n) count 1 bits in n
       unsigned n;
       {
           int b;

           for (b = 0; n != 0; n >>= 1)
               if (n & 01)
                   b++;
           return(b);
   }
*/

#include <stdio.h>

unsigned int bitcount(unsigned int n);
void printbits(unsigned int x);

int main()
{
    unsigned int n = 0x42;
    printf("n = %#x -> ", bitcount(n));
    printbits(n);
    printf("\ntotal number of 1 bits in n: %d\n", bitcount(n));
    return 0;
}

unsigned int bitcount(unsigned int n)
{
    unsigned count = 0;
    for (; n != 0; ++count)
        n &= n - 1;
    return count;
}

void printbits(unsigned int x)
{
    // Get the total number of bits on an unsigned int for the machine
    int num_bits = 0;
    for (unsigned int val = ~0u; val != 0; val >>= 1u, ++num_bits);

    // Print bits from MSB
    for (int i = num_bits - 1; i >= 0; --i)
    {
        unsigned int mask = 1u << i;
        printf("%c", (x & mask) ? '1' : '0');
        if (i != 0 && i % 8 == 0)
            printf(" ");
    }
}
