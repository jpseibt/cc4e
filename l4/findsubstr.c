/* Exercise. Write the function substring(s1, s2) which returns the first element in the string s1 where
   the substring s2 occurs, or -1 if s1 not contain a substring s2.
*/

#include <stdio.h>

int substring(char *s1, char *s2);

int main()
{
    char str1[] = "mississippi";
    char str2[] = "issip";
    int loc = substring(str1, str2);
    printf("\"%s\" substring in \"%s\" = %d\n", str2, str1, loc);

    return 0;
}

int substring(char *s1, char *s2)
{
    for (int i = 0, j = 0; s1[i] != '\0'; ++i, j = 0)
    {
        for (; s2[j] != '\0'; ++j)
        {
            if (s1[i + j] != s2[j])
                break;
        }
        if (s2[j] == '\0')
            return i;
    }
    return -1;
}
