/* Exercise 5-1. Write getfloat, the floating point analog of get_int.
   What type does getfloat return as its function value?
   "Should return an int, so getfloat() can return state or chars like EOF."
*/

#include <stdio.h>

#define is_digit(c) ((c) >= '0' && (c) <= '9')
#define NOTNUM -42
#define BUFSIZE 100

int getfloat(double *pf);
int getch();
void ungetch(int c);

static char buf[BUFSIZE];
static int bufp = 0;

int main(void)
{
  double f;
  int state;

  while ((state = getfloat(&f)) != EOF)
  {
    if (state != NOTNUM)
      printf("f = %f\n", f);
  }

  return 0;
}

int getfloat(double *pf)
{
  int c, sign;
  double power;

  while ((c = getch()) == ' ' || c == '\n' || c == '\t')
    ; // Skip leading whitespace

  if (c != '-' && c != '+' && c != '.' && !is_digit(c))
  {
    if (c == EOF)
      return EOF;
    return NOTNUM;
  }

  sign = 1;
  if (c == '-' || c == '+')
  {
    sign = (c == '-') ? -1 : 1;
    c = getch();
    if (!is_digit(c))
      return NOTNUM;
  }

  for (*pf = 0; is_digit(c); c = getch())
    *pf = *pf * 10.0 + c - '0';

  if (c == '.')
    c = getch();

  for (power = 1; is_digit(c); c = getch())
  {
    power *= 10.0;
    *pf = *pf * 10.0 + c - '0';
  }

  *pf = sign * (*pf / power);

  // Scientific notation
  if (c == 'e' || c == 'E')
  {
    c = getch();
    sign = 1;
    if (c == '-' || c == '+')
    {
      sign = (c == '-') ? -1 : 1;
      c = getch();
    }

    int exp;
    for (exp = 0; is_digit(c); c = getch())
      exp = exp * 10 + c - '0';

    power = 1.0;
    for (int i = 0; i < exp; ++i)
      power *= 10.0;

    if (sign > 0)
      *pf *= power;
    else
      *pf /= power;
  }

  if (c != EOF)
    ungetch(c);
  return c;
}

int getch()
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("Ungetch: too many chars / buffer full\n");
  else
    buf[bufp++] = c;
}
