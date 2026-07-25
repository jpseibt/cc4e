/*
  LBS290 Exercise 98 - A Touring Machine. This is a subset of an important concept in Computer Science
  called a Turing Machine. We call it a "Touring Machine" because it "wanders around and does things in
  memory" similar to a Turing Machine. Your computer has 256 characters of memory. The machine keeps track
  of the "position" or the "head" where data is to be written. The starting position is zero. You are to
  read a sequence of instructions from input and perform those instructions. When there are no more instructions,
  print the memory out as a zero-terminated C character array. Here are the instructions you need to support:
    42     Store this value into the memory at the current position
    >      Move the "position" one to the right (i.e. position++);
    <      Move the "position" one to the left (i.e. position--);
  All of the numbers should be in the range of 0-255 so they fit into a C char variable.
  Fun Fact: Dr. Chuck did not assign this question in 1991. But if time travel were possible, he would consider adding it to LBS 290.

  This will be provided as input to your program:
    42 > 114 > 105 > 97 >
    110 < < < < 66
  Expected output from your program:
    Memory:
    Brian
*/

#include <stdio.h>

int nazatoi(char *s)
{
  int sign = 1;
  int result = 0;

  if (*s == '-' || *s == '+')
    sign = (*s++ == '-') ? -1 : 1;

  while (*s)
    result = 10 * result + (*s++ - '0');

  return sign * result;
}

int str_len(char *s)
{
  char *p = s;
  while (*p) ++p;
  return p - s;
}

int str_match(char *str0, char *str1, int len)
{
  int i = 0;
  while ((*str0 && *str1) && *str0 == *str1)
  {
    ++i;
    ++str0;
    ++str1;
  }
  return i == len;
}

#define I_STORE "42"
#define I_RMOVE ">"
#define I_LMOVE "<"

int main(void)
{
  char memory[256], token[256];
  int position = 0, value;

  while (scanf("%s", token) == 1)
  {
    static int store = 0;

    if (str_match(token, I_STORE, str_len(token)))
    {
      if (!store)
      {
        store = 1;
        continue;
      }
    }

    if (str_match(token, I_RMOVE, str_len(token)))
    {
      ++position;
      if (position > 255) position = 0;
    }
    else if (str_match(token, I_LMOVE, str_len(token)))
    {
      --position;
      if (position < 0) position = 255;
    }
    else
    {
      memory[position] = (char)nazatoi(token);
    }
  }
  printf("Memory:\n%s\n", memory);
}
