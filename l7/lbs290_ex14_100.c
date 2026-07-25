/*
  LBS290 Exercise 14. The program will create a 10 element array and read in 10 integers into the array.
  Then the program will print the integers backwards. Then the program will scan for entries in the array
  which contain the value 100 and print out the index of the entries with the number 100. The program will
  also count the number of entries which equal 100. The program should work even if there are no entries
  which equal 100. See the sample output for the expect format of the output.
  Fun Fact:Dr. Chuck used this exact assignment while teaching C - LBS 290 - Fall 1991.
*/

#include <stdio.h>

int main(void)
{
  int i, v, arr[10];
  for (i = 0; i < 10; ++i)
  {
    scanf("%d", &v);
    arr[i] = v;
  }

  for (i = 9; i >= 0; --i)
  {
    printf("numb[%d] = %d\n", i, arr[i]);
  }

  printf("\nSearching for entries equal to 100\n\n");

  v = 0; // Will store the number of entries equal to 100
  for (i = 0; i < 10; ++i)
  {
    if (arr[i] == 100)
    {
      printf("Found 100 at %d\n", i);
      ++v;
    }
  }
  printf("\nFound %d entries with 100\n", v);

  return 0;
}
