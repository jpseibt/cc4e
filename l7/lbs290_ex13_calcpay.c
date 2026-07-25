/*
  LBS290 Exercise 13. This program will read an un-specified number of employee time records from input.
  Each time record will contain an employee number (integer), an employee rate per hour (float) and number
  of hours worked. You should give the employee time-and-a-half for overtime (hours over 40). You must write
  a function named calcpay() to calculate the pay. The function should have no return value and must not use
  any global variables. The calculated pay should be passed out of the function using call by location.
  Fun Fact:Dr. Chuck used this exact assignment while teaching C - LBS 290 - Fall 1991.
*/

#include <stdio.h>

#define WORKING_HOURS 40.0f
#define OVERTIME_EXTRA 1.5f

void calcpay(float *p, float r, float h);

int main(void)
{
  int empno;
  float rate, hours, pay;

  while (1)
  {
    if ( scanf("%d %f %f", &empno, &rate, &hours) < 3 ) break;
    calcpay(&pay, rate, hours);
    printf("Employee=%d Rate=%.2f Hours=%.2f Pay=%.2f\n", empno, rate, hours, pay);
  }

  return 0;
}

void calcpay(float *p, float r, float h)
{
  int overtime = (h > WORKING_HOURS) ? 1 : 0;
  *p = 0.0f;

  while (h > WORKING_HOURS)
  {
    h -= WORKING_HOURS;
    *p += WORKING_HOURS * r;
  }

  if (overtime)
  {
    r = r * OVERTIME_EXTRA;
  }

  *p += h * r;
}
