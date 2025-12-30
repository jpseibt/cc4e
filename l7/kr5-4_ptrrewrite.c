/* Exercise 5-4. Rewrite appropriate programs from earlier chapters and exercises with pointers instead
   of array indexing. Good possibilities include get_line (Chapter 1 and 4), atoi, itoa, and their
   variants (Chapter 2, 3, and Chapter 4), reverse (Chapter 3), and index and getop (Chapter 4).
*/

#include <stdio.h>

#define MAXLINE 1000
#define BUFSIZE 100
#define MAXOP 20
#define NUMBER '0' // Signal that number found
#define TOOBIG '9' // Signal that string is too big
#define VAR 'A'    // Signal that variable found
#define ASSIGN '$' // Signal to assign value to var

#define is_digit(x) ((unsigned int)((x) - '0') < 10)
#define is_lower(x) ((unsigned int)((x) - 'a') < 26)

int get_line(char *s, int max);
void atoinaz(int *pn, char *s);
void itoanaz(int n, char *s);
void reverse(char *s);
int index(char *s, char *t);
int getop(char *s);
int getch();
void ungetch(int ch);

static int chbuf[BUFSIZE];
static int *chbuf_ptr = chbuf;

int get_line(char *s, int max)
{
  char *s_ptr = s;
  int ch;
  ch = 0;
  for (ch = getchar(); s_ptr - s < max - 1 && ch != EOF && ch != '\n'; ch = getchar())
    *s_ptr++ = ch;

  *s_ptr = '\0';
  return s_ptr - s;
}

void atoinaz(int *pn, char *s)
{
  int sign = 1;
  if (*s == '-' || *s == '+')
    sign = (*s++ == '-') ? -1 : 1;

  *pn = 0;
  while (is_digit(*s))
    *pn = 10 * *pn + *s++ - '0';

  *pn *= sign;
}

void itoanaz(int n, char *s)
{
  int sign = n;
  char *s_head = s;

  if (n > 0)
    n = -n;

  do
  {
    *s++ = -(n % 10) + '0';
  } while ((n /= 10) != 0);

  if (sign < 0)
    *s++ = '-';

  *s = '\0';
  reverse(s_head);
}

void reverse(char *s)
{
  char *j = s;
  while (*j)
    ++j;
  --j; // Move to the char before '\0'

  while (s < j)
  {
    char tmp = *s;
    *s++ = *j;
    *j-- = tmp;
  }
}

int index(char *s, char *t)
{
  for (char *s_ptr = s, *s_trav, *t_trav; *s_ptr != '\0'; ++s_ptr)
  {
    for (s_trav = s_ptr, t_trav = t; *t_trav != '\0' && *s_trav == *t_trav;)
    {
      ++s_trav;
      ++t_trav;
    }
    if (*t_trav == '\0')
      return s_ptr - s;
  }
  return -1;
}

int getop(char *s)
{
  int ch, nextch;
  char *s_end = s + MAXOP - 1;

  while ((ch = getch()) == ' ' || ch == '\n' || ch == '\t')
    ;

  *s++ = ch;
  *s = '\0';

  // Check for VAR / ASSIGN or operator
  if (ch != '.' && !is_digit(ch) && ch != '-')
  {
    if (is_lower(ch))
    {
      while ((nextch = getch()) == ' ' || nextch == '\n' || nextch == '\t')
        ;
      if (nextch == '@')
        return ASSIGN;
      else
      {
        ungetch(nextch);
        return VAR;
      }
    }
    else
      return ch; // Return operator
  }

  // Check for negative number (unary minus)
  if (ch == '-')
  {
    nextch = getch();
    if (!is_digit(nextch) && nextch != '.')
    {
      ungetch(nextch);
      return '-';
    }
    ch = nextch;
    *s++ = ch;
  }

  for (ch = getch(); s < s_end && is_digit(ch); ch = getch())
    *s++ = ch;

  if (ch == '.' && s < s_end)
  {
    *s++ = ch;
    for (ch = getch(); s < s_end && is_digit(ch); ch = getch())
      *s++ = ch;
  }

  if (s <= s_end)
  {
    ungetch(ch);
    *s = '\0';
    return NUMBER;
  }
  else
  {
    while (ch != '\n' && ch != EOF)
      ch = getch(); // Clear input
    *s_end = '\0';
  }
  return TOOBIG;
}

int getch()
{
  return ((chbuf_ptr - chbuf) > 0) ? *--chbuf_ptr : getchar();
}

void ungetch(int ch)
{
  if (chbuf_ptr < chbuf + BUFSIZE)
    *chbuf_ptr++ = ch;
  else
    printf("[ungetch()] Char buffer full...");
}
