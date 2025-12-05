/* Exercise 1-12. Write a program to print a histogram of the lengths of words in its input.
   It is easiest to draw the histogram horizontally; a vertical orientation
   is more challenging.
*/

#include <stdio.h>

#define YES 1
#define NO  0
#define MAX_LENGTH 30 // Max word length to track separately

int main()
{
    int c = 0, ccount = 0, inword = 0;

    /* Each element is the number of words of lengths 1 to MAX_LENGTH.
       words_len[0] = count of words with length 1
       words_len[1] = count of words with length 2
       ...
       words_len[29] = count of words with length 30 or more
    */
    int words_len[MAX_LENGTH];
    for (int i = 0; i < MAX_LENGTH; ++i)
    {
        words_len[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (inword && (c == ' ' || c == '\n' || c == '\t'))
        {
            if (ccount < MAX_LENGTH)
                ++words_len[ccount - 1];
            else
                ++words_len[MAX_LENGTH - 1];
            ccount = 0;
            inword = NO;
        }
        else
        {
            if (inword == NO)
                inword = YES;
            ++ccount;
        }
    }

    /* Check for last word */
    if (inword == YES) {
        if (ccount < MAX_LENGTH)
            ++words_len[ccount - 1];
        else
            ++words_len[MAX_LENGTH - 1];
    }

    /* Finds the greater element */
    int mostwords = words_len[0];
    for (int i = 1; i < MAX_LENGTH; ++i)
    {
        if (words_len[i] > mostwords)
            mostwords = words_len[i];
    }

    /* Prints the histogram horizontally */
    printf("\n====== Horizontal Word Lenght Histogram ======\n");
    for (int i = 0; i < MAX_LENGTH; ++i)
    {
        printf("length %d: ", i + 1);
        if (i < 9)
            putchar(' '); /* Prints another space to maintain alignment */

        for (int j = 0; j < mostwords; ++j)
            if (j < words_len[i])
                putchar('*');
            else
                putchar(' ');

        printf(" |%d\n", words_len[i]);
    }

    /* Prints the histogram vertically */
    printf("\n====== Vertical Word Lenght Histogram ======\n");
    for (int i = mostwords; i > 0; --i)
    {
        for (int j = 0; j < MAX_LENGTH; ++j)
        {
            if (words_len[j] < i)
                printf(" . ");
            else
                printf(" * ");
        }
        printf(" |%d\n", i);
    }

    for (int i = 0; i < MAX_LENGTH; ++i)
        printf("---");
    putchar('\n');

    for (int i = 0; i < MAX_LENGTH; ++i)
    {
        printf (" %d", i + 1);
        if (i < 9)
            putchar(' ');
    }
    printf("+\n");

    return 0;
}

