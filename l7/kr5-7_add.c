/* Exercise 5-7. Write the program add which evaluates a reverse Polish expression from the command line. For example,

       add 2 3 4 + *

   evaluates 2 * (3+4).
*/

#include <stdio.h>

#define MAXVAL 100 // Maximum depth of val stack
#define MAXOP 20   // Max size of operand, operator
#define NUMBER '0' // Signal that number found
#define TOOBIG '9' // Signal that string is too big

#define is_digit(x) ({                  \
  int __x_tmp__ = x;                    \
  (unsigned int)(__x_tmp__ - '0') < 10; \
})

// Prototypes
int getop(char *arg, char *buf);
void push(double x);
double pop();
double peak();
void clear();
double atof(char *s);

// Globals
double vstk[MAXVAL]; // Value stack
double *sp = vstk;   // Stack pointer

int main(int argc, char *argv[])
{
  char cop[MAXOP];
  double op2;

  for (int i = 1, type; i < argc && (type = getop(argv[i], cop)) != EOF; ++i)
  {
    switch (type)
    {
      case NUMBER:
        push(atof(cop));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("zero divisor popped\n");
        break;
      case '%':
        op2 = pop();
        if (op2 != 0.0)
          push((int)pop() % (int)op2);
        break;
      case '=':
        printf("\t%f\n", peak());
        break;
      case '<': // Erase
        pop();
        break;
      case 'C':
        clear();
        break;
      case TOOBIG:
        printf("%.20s ... is too long\n", cop);
        break;
      default:
        printf("unknown command %c\n", type);
        break;
    }
  }
  printf("\t%f\n", peak());

  return 0;
}

int getop(char *arg, char *buf)
{
  int ch = *arg++;
  char *buf_end = buf + MAXOP - 1;

  *buf++ = ch;
  *buf = '\0';

  if (ch != '.' && (!is_digit(ch)) && ch != '-')
    return ch; // Return operator

  // Check for unary minus '-'
  if (ch == '-')
  {
    int nextch = *arg;
    if (!is_digit(nextch) && nextch != '.')
      return '-';
    ch = *arg++;
    *buf++ = ch;
  }

  for (ch = *arg++; ch != '\0' && buf < buf_end; ch = *arg++)
    *buf++ = ch;

  if (ch == '.' && buf < buf_end)
  {
    *buf++ = ch;
    for (ch = *arg++; ch != '\0' && buf < buf_end; ch = *arg++)
      *buf++ = ch;
  }

  if (ch == '\0')
  {
    *buf = '\0';
    return NUMBER;
  }

  *buf_end = '\0';
  return TOOBIG;
}

void push(double x)
{
  if (sp < (vstk + MAXVAL))
    *sp++ = x;
  else
  {
    printf("error: value stack full...\n");
    clear();
  }
}

double pop()
{
  if (sp > vstk)
    return *--sp;

  printf("error: stack empty...\n");
  clear();
  return 0;
}

double peak()
{
  if (sp > vstk)
    return *(sp - 1);

  printf("error: stack empty...\n");
  clear();
  return 0;
}

void clear()
{
  sp = vstk;
}

double atof(char *s)
{
  int sign;
  double val, power;

  sign = 1;
  if (*s == '-' || *s == '+')
    sign = (*s++ == '-') ? -1 : 1;

  for (val = 0.0; is_digit(*s); ++s)
    val = 10.0 * val + *s - '0';

  if (*s == '.')
    ++s;

  for (power = 1.0; is_digit(*s); ++s)
  {
    power *= 10.0;
    val = 10.0 * val + *s - '0';
  }

  return sign * (val / power);
}
