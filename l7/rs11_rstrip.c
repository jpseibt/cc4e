/*
  Exercise RS-11: Write a C function called py_rstrip() that removes spaces from the end of a string.
  This function modifies its parameter and should never be called with a constant value.
*/

#include <stdio.h>
#include <string.h>

int str_len(char *s)
{
  char *p = s;
  while (*p) ++p;
  return p - s;
}

void py_rstrip(char *inp)
{
  char *p = inp + str_len(inp) - 1;
  while (*p == ' ') --p;
  *(p+1) = '\0';
}

int main(void)
{
    char s1[] = "   Hello   World    ";
    py_rstrip(s1);
    printf("-%s-\n", s1);
}
