/* Exercise 5-3. Write a macro for strcpy. */

#include <stdio.h>

#define macro_strcpy(s, t) do {         \
  char *__ps__ = (s);              \
  char *__pt__ = (t);              \
  while ((*__ps__++ = *__pt__++)); \
} while(0)

int main(void)
{
  char s[] = "abc";
  char t[] = "xyz";

  printf("s = \"%s\"\nt = \"%s\"\n", s, t);
  macro_strcpy(s, t);
  printf("After macro_strcpy(s, t):\n\ts = \"%s\"\n\tt = \"%s\"\n", s, t);

  return 0;
}
