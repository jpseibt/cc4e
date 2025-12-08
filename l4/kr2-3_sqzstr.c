/* Exercise 2-3. Write an alternate version of squeeze(s1, s2) which deletes each character in s1
   which matches any character in the string s2.
*/

#include <stdio.h>

int squeeze(char* s1, char* s2);

int main()
{
    char str1[] = "abcdefg";
    char str2[] = "bdf";
    printf("%s - %s = ", str1, str2);
    squeeze(str1, str2);
    printf("\"%s\"\n", str1);
}

int squeeze(char* s1, char* s2)
{
    int idx = 0;
    for (int i = 0, in_s2 = 0; s1[i] != '\0'; ++i, in_s2 = 0)
    {
        for (int j = 0; s2[j] != '\0'; ++j)
        {
            if (s1[i] == s2[j])
            {   // Char s1[i] is in s2, will be skipped
                in_s2 = 1;
                break;
            }
        }
        if (!in_s2)
            s1[idx++] = s1[i];
    }
    s1[idx] = '\0';
    return idx;
}
