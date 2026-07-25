/*
   Exercise RS-12: Write a C function called py_lstrip() that removes whitespace (blanks, tabs, and newlines)
   from the beginning of a string. This function modifies its parameter and should never be called with a constant value.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void py_lstrip(char *inp)
{
  char *p = inp;
  while (*p == ' ' || *p == '\t' || *p == '\n') ++p;
  while (*p) *inp++ = *p++;
  *inp = '\0';
}

int main(void)
{
    char s1[] = "   Hello   World    ";
    py_lstrip(s1);
    printf("-%s-\n", s1);
}
