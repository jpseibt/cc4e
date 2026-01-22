/* Exercise 5-9. Extend entab and detab to accept the shorthand
          `entab m +n`
   to mean tabs stops every n columns, starting at column m. Choose convenient (for the user) default behavior.
*/

#include <stdio.h>

#define MAX_TSTOPS 20
#define DEFAULT_TAB_WIDTH 8
#define DEFAULT_TAB_START 8

#define is_digit(x) ((unsigned)((x) - '0') < 10)

int nazatoi(char *s);
int is_int(char *s);

int main(int argc, char *argv[])
{
  int tstops[MAX_TSTOPS], tstops_len;
  int idx, ch, column, space_count, next_tstop, remaining_tabs_width;

  tstops_len = 0;

  if (argc > 1)
  {
    // Check for `+n` at argv[2]
    if (argc > 2 && *argv[2] == '+')
    {
      // Set tabstops start column
      if (is_int(argv[1]) && is_int(argv[2]))
      {
        tstops_len = 1;
        tstops[0] = nazatoi(argv[1]);
        remaining_tabs_width = nazatoi(argv[2]);
        if (remaining_tabs_width <= 0)
          remaining_tabs_width = DEFAULT_TAB_WIDTH;
      }
      else
      {
        printf("Invalid arguments [%s]...\n", *argv);
        return 1;
      }
    }
    else
    { // Try to fill normal tstops array
      if ((argc - 1) <= MAX_TSTOPS)
        tstops_len = argc - 1;
      else
        tstops_len = MAX_TSTOPS;

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
      remaining_tabs_width = DEFAULT_TAB_WIDTH;
    }
  }

  idx = column = space_count = 0;
  while ((ch = getchar()) != EOF)
  {
    if (ch == ' ')
      ++space_count;
    else
    {
      while (space_count)
      {
        // Get next tab width and calculate the amount of spaces before the next tab stop
        if (tstops_len == 0 || idx >= tstops_len || column >= tstops[tstops_len - 1])
        { // End of tstops - use default
          next_tstop = remaining_tabs_width - (column % remaining_tabs_width);
        }
        else
        { // Next tab stop is in tstops arr
          while (idx < tstops_len && tstops[idx] <= column)
            ++idx;
          next_tstop = tstops[idx++] - column ; // post increment idx to point to the next possible tab stop
        }

        if (space_count >= next_tstop)
        {
          putchar('\t');
          column += next_tstop;
          space_count -= next_tstop;
        }
        else
        {
          column += space_count;
          while (space_count)
          {
            putchar('.');
            --space_count;
          }
        }
      }

      // Put non-whitespace char
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
