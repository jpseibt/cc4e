/* Exercise 2-2. Write the function htoi(s), which converts a string of hexadecimal digits into its
   equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.
*/

#include <stdio.h>
#include <string.h>

int htoi(char *s, int len);

int main()
{
    char s[] = "0xfffffff";
    int si = htoi(s, strlen(s));
    printf("%s: %d\n", s, si);
    return 0;
}

int htoi(char* s, int len)
{
    int res = 0;
    int val = 0;

    int i = (s[1] == 'x' || s[1] == 'X') ? 2 : 0; // Skip "0x"
    for (; i < len; ++i)
    {
        if ((s[i] >= '0' && s[i] <= '9'))
        {
            val = s[i] - '0';
        }
        else if ((s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'))
        {
            val = (s[i] >= 'a' && s[i] <= 'f') ? s[i] - 'a' + 10 : s[i] - 'A' + 10;
        }
        else
        {   // Invalid hex str
            return 0;
        }
        res = res * 16 + val;
    }
    return res;
}


