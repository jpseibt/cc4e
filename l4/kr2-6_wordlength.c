/* Exercise 2-6. Write a function wordlength() which computes the word length of the host machine,
   that is, the number of bits in an int. The function should be portable, in the sense that the
   same source code works on all machines.
*/

#include <stdio.h>

int wordlength();

int main()
{
    printf("Host machine word length: %d\n", wordlength());
    return 0;
}

int wordlength()
{
    unsigned int x = ~0, count = 0;
    for (; x != 0; ++count)
    {
        x = x >> 1;
    }
    return count;
}

