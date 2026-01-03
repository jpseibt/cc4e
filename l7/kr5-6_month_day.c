/* Exercise 5-6. Rewrite the routines day_of_year and month_day with pointers instead of indexing. */

#include <stdio.h>

int day_of_year(int year, int month, int day); // Set day of year from month & day
void month_day(int year, int yearday, int *pmonth, int *pday); // Set month, day from day of year

static char day_tab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main(void)
{
  int yearday, year, month, day;
  yearday = 242;
  year = 2026;

  month_day(year, yearday, &month, &day);
  printf("yearday:%d\nyear:%d\nmonth:%d\nday:%d\nday_of_year():%d\n", yearday, year, month, day, day_of_year(year, month, day));

  return 0;
}

int day_of_year(int year, int month, int day)
{
  int leap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
  char *p = day_tab[leap];

  while (--month > 0)
  {
    day += *++p;
  }
  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int leap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
  char *p = day_tab[leap];

  while (yearday > *++p)
  {
    yearday -= *p;
  }
  *pmonth = (int)(p - day_tab[leap]);
  *pday = yearday;
}
