/* Exercise 5-5. Rewrite readlines to create lines in an array supplied by main, rather than calling
  alloc to maintain storage. How much faster is the program?
  "Would be much faster as it eliminates the copying of buffers and memory allocations. By allocating
   a chunk of contiguous memory on the stack, a pointer can be passed to readlines() / writelines(),
   and pointer arithmetic can be used to fill segments of 'LINE_SIZE' bytes.
   Obs: the drawback is that a good portion of the allocated memory may be wasted / unused"
*/

#include <stdio.h>
#include <string.h>
#define LINES 100 // Max lines to be sorted
#define LINE_SIZE 1000

int readlines(char *linesbuf, int linebuf_max);
void writelines(char *linesbuf, int nlines);
int get_line(char *s, int max);
int str_len(char *s);

int main()
{
  char linesbuf[LINES * LINE_SIZE];
  int nlines;

  if ((nlines = readlines(linesbuf, LINES)) >= 0)
    writelines(linesbuf, nlines);
  else
    printf("input too big to sort...\n");

  return 0;
}

int readlines(char *linesbuf, int linebuf_max)
{
  int len, nlines;

  nlines = 0;
  while ((len = get_line(linesbuf, LINE_SIZE)) > 0)
  {
    if (nlines >= linebuf_max)
      return -1;
    else
    {
      *(linesbuf + len - 1) = '\0'; // zap newline
      linesbuf += len;
      ++nlines;
    }
  }
  return nlines;
}

void writelines(char *linesbuf, int nlines)
{
  for (int i = 0; i < nlines; ++i, linesbuf += str_len(linesbuf) + 1)
    printf("%d:\"%s\"\n", i + 1, linesbuf);
}

int get_line(char *s, int max)
{
  char *s_ptr = s;
  char *s_end = s + max - 1;
  int c;

  while ((c = getchar()) != EOF && c != '\n' && s_ptr < s_end - 1)
    *s_ptr++ = c;

  if (c == '\n')
    *s_ptr++ = c;

  *s_ptr = '\0';

  return s_ptr - s;
}

int str_len(char *s)
{
  char *p = s;
  while (*p)
    ++p;
  return p - s;
}
