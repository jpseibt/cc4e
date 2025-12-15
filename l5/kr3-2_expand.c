/* Exercise 3-2. Write a function expand(s1 , s2) which expands shorthand notations like a-z in the
   string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and
   digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z.
   (A useful convention is that a leading or trailing - is taken literally.)
*/

#include <stdio.h>

#define SIZE 255

void expand(char *s1, char *s2, int len);
int is_alpha(char c);
int is_lower(char c);
int is_digit(char c);

int main()
{
    char s1[] = "8-0-9a-z --135! = C-H 4-8 a-G o-00-o a-b-c";
    char s2[SIZE];
    expand(s1, s2, SIZE);
    printf("s1 = \"%s\"\ns2 = \"%s\"\n", s1, s2);
    return 0;
}

void expand(char *s1, char *s2, int len)
{
    int i, j, dashed, exp;
    i = j = dashed = exp = 0;

    while ((s1[i] != '\0' || dashed) && j < len - 1)
    {
        if (s1[i] == '-' && !dashed && i > 0)
        {
            dashed = 1;
            ++i;
        }
        else
        {
            if (dashed)
            {
                if (is_alpha(s1[i]) && is_alpha(s2[j - 1]) && (is_lower(s2[j - 1]) == is_lower(s1[i])))
                {   // Last check if the last copied char value is less than s1[i]
                    exp = (s2[j - 1] < s1[i]) ? 1 : 0;
                }
                else if (is_digit(s1[i]) && is_digit(s2[j - 1]))
                {
                    exp = (s2[j - 1] < s1[i]) ? 1 : 0;
                }

                if (exp && s2[j - 1] < s1[i])
                {   // Expand sequence from the last copied char value + 1 to s1[i]
                    for (int c = s2[j - 1] + 1; c <= s1[i] && j < len - 1; ++c, ++j)
                        s2[j] = c;
                    exp = 0;
                    ++i;
                }
                else
                {   // Consume dash and s1[i]
                    s2[j++] = '-';
                    if (s1[i] != '\0' && j < len - 1)
                        s2[j++] = s1[i++];
                }

                dashed = 0;
            }
            else
                s2[j++] = s1[i++];
        }
    }

    s2[j] = '\0';
}

int is_alpha(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int is_lower(char c)
{
    return c >= 'a' && c <= 'z';
}

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}
