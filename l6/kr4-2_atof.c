/* Exercise 4-2. Extend atof so it handles scientific notation of the form 123.45e-6 where
   a floating point number may be followed by e or E and an optionally signed exponent.
*/

#include <stdio.h>

double atof(char *s);

int main()
{
    char s[] = "123.45e-6";

    printf("s = \"%s\"\natof(s) = %.8f\n", s, atof(s));

    return 0;
}

double atof(char *s)
{
    int i, exp, sign;
    double val, power;

    for (i = 0; s[i] == ' ' || s[i] == '\n' || s[i] == '\t'; ++i)
        ; // Skip leading whitespace

    sign = 1;
    if (s[i] == '+' || s[i] == '-')
        sign = (s[i++] == '+') ? 1 : -1;

    for (val = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        val = val * 10.0 + s[i] - '0';

    if (s[i] == '.')
        ++i;

    for (power = 1; s[i] >= '0' && s[i] <= '9'; ++i)
    {
        power *= 10.0;
        val = val * 10.0 + s[i] - '0';
    }

    val = sign * (val / power);

    if (s[i] == 'e' || s[i] == 'E')
    {   // Scientific notation number
        ++i;
        sign = 1;
        if (s[i] == '+' || s[i] == '-')
            sign = (s[i++] == '+') ? 1 : -1;

        for (exp = 0; s[i] >= '0' && s[i] <= '9'; ++i)
            exp = exp * 10 + s[i] - '0';

        power = 1.0;
        for (int j = 0; j < exp; ++j)
            power *= 10.0;

        if (sign > 0)
            val *= power;
        else
            val /= power;
    }

    return val;
}
