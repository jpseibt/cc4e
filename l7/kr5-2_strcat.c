/* Exercise 5-2. Write a pointer version of the function strcat which we showed
   in Chapter 2: strcat(s, t) copies the string t to the end of s.
*/

#include <stdio.h>

void str_cat(char *s, char *t);

int main(void)
{
  char s[10] = "abc";
  char t[] = "def";
  printf("s = %s    t = %s\n", s, t);

  str_cat(s, t);
  printf("strcat(s, t):\n\ts = %s\n", s);

  return 0;
}

void str_cat(char *s, char *t)
{
  while (*s)
    ++s; // Find end of s
  while ((*s++ = *t++))
    ; // Copy t
}
