/* Exercise 5-8. Modify the programs entab and detab (written as exercises in Chapter 1) to accept a
   list of tab stops as arguments. Use the normal tab settings if there are no arguments.
*/
#include <stdio.h>

#define MAX_TSTOPS 20
#define DEFAULT_TAB_WIDTH 8

#define is_digit(x) ((unsigned)((x) - '0') < 10)

int nazatoi(char *s);
int is_int(char *s);

int main(int argc, char *argv[])
{
  int tstops[MAX_TSTOPS], tstops_len;
  int idx, ch, column, next_tstop;

  tstops_len = 0;
  if (argc > 1)
  {
    if ((argc - 1) <= MAX_TSTOPS)
      tstops_len = argc - 1;
    else
      tstops_len = MAX_TSTOPS;
  }

  // Fill tab stops arr
  for (idx = 0; idx < tstops_len; ++idx)
  {
    if (!is_int(*++argv))
    {
      printf("Invalid argument [%s]...\n", *argv);
      return 1;
    }
    tstops[idx] = nazatoi(*argv);
  }

  idx = column = 0;
  while ((ch = getchar()) != EOF)
  {
    if (ch == '\t')
    {
      // Get next tab width and calculate the amount of spaces before the next tab stop
      if (tstops_len == 0 || idx >= tstops_len || column >= tstops[tstops_len - 1])
      { // End of tstops - use default
        next_tstop = DEFAULT_TAB_WIDTH - (column % DEFAULT_TAB_WIDTH);
        next_tstop += column;
      }
      else
      { // Next tab stop is in tstops arr
        while (idx < tstops_len && tstops[idx] <= column)
          ++idx;
        next_tstop = tstops[idx++]; // post increment idx to point to the next possible tab stop
      }

      while (column < next_tstop)
      {
        putchar('.');
        ++column;
      }
    }
    else
    {
      putchar(ch);
      if (ch == '\n')
      {
        idx = 0;
        column = 0;
      }
      else
        ++column;
    }
  }

  return 0;
}

int nazatoi(char *s)
{
  int sign, val;

  sign = 1;
  if (*s == '-' || *s == '+')
    sign = (*s++ == '-') ? -1 : 1;

  val = 0;
  while (*s)
    val = 10 * val + *s++ - '0';

  return sign * val;
}

int is_int(char *s)
{
  if (*s == '-' || *s == '+')
    ++s;

  if (!is_digit(*s++))
    return 0;

  while (is_digit(*s))
    ++s;

  return *s == '\0';
}
