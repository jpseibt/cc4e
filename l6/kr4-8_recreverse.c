/* Exercise 4-8. Write a recursive version of the function reverse(s), which reverses the string s. */

#include <stdio.h>

int itoa(int n, char *s);
char * recitoa(int n, char *s);
void reverse(char *s, int len);
unsigned int wordlength();

int main(void)
{
  char s[12];
  int n = -1568976512;
  itoa(n, s);
  printf("Negative number test:\n\tn =  %d\n\ts = \"%s\"\n", n, s);

  n = 1 << (wordlength() - 1);
  itoa(n, s);
  printf("Largest negative number test:\n\tn =  %d\n\ts = \"%s\"\n", n, s);

  n = ~0u >> 1u;
  itoa(n, s);
  printf("Largest positive number test:\n\tn =  %d\n\ts = \"%s\"\n", n, s);

  return 0;
}

int itoa(int n, char *s)
{
  int len = recitoa(n, s) - s;

  if (n < 0)
  {
    s[len] = '-';
    s[++len] = '\0';
  }

  reverse(s, len);

  return len;
}

char * recitoa(int n, char *s)
{
  if (n > 0)
    n = -n;

  *s = -(n % 10) + '0';

  if ((n /= 10) != 0)
    return recitoa(n, ++s);
  else
    *(++s) = '\0';

  return s;
}

void reverse(char *s, int len)
{
  if (s < (s + len - 1))
  {
    int c = *s;
    *s = s[len - 1];
    s[len - 1] = c;
    reverse(++s, len - 2);
  }
}

unsigned int wordlength()
{
  unsigned int count, x;
  for (count = 0, x = ~0u; x != 0; ++count, x >>= 1)
    ;
  return count;
}
