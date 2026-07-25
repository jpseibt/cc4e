/*
  Exercise RS-10: Write a C program to prompt for two strings and concatenate them as shown in the
  Python code below. Use the functions strcpy and strcat from the string.h library in your code.
  Pre-allocate your character arrays large enought to handle up to 100 characters on input for each
  string (i.e. do not use malloc as we have not yet covered that yet).

    print('Enter two strings');
    first = input()
    second = input()
    print(first + " & " + second)
*/

#include <stdio.h>
#include <string.h>

int str_len(char *s)
{
  char *p = s;
  while (*p) ++p;
  return p - s;
}

char first_str[101] = {0};
char second_str[101] = {0};
char third_str[201] = {0};

int main(void)
{
  printf("Enter two strings\n");
  scanf("%s %s", (char*)&first_str, (char*)&second_str);

  char *p = third_str;
  strcpy(p, first_str);
  p += str_len(first_str);
  strcpy(p, " & ");
  p += 3;
  strcpy(p , second_str);

  printf("%s\n", third_str);
  return 0;
}
