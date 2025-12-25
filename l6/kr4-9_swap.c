/* Exercise 4-9. Define a macro swap(x, y) which interchanges its two int arguments. (Block structure will help.)
   "Now I've learned about GNU C extensions, variable shadowing bugs, static inline,
    naked blocks and if-else bugs with them."
*/

#include<stdio.h>

/* GNU extension: ({...}) become a statement. Clang supports the majority of GCC
   extensions, but compilers that don't support them would throw an error. */
#define swapGNU(x, y) ({int __swp_tmp__ = (x); (x) = (y); (y) = __swp_tmp__;})

// Naked block: this would break an if-else statement if called followed by a semicolon.
#define swapNB(x, y) { \
  int __swp_tmp__ = x; \
  x = y;               \
  y = __swp_tmp__;     \
}

// Portable way that eliminates the naked block bug.
#define swapISO(x, y) do { \
  int __swp_tmp__ = x;     \
  x = y;                   \
  y = __swp_tmp__;         \
} while (0)

// Inline function: tells the compiler to substitute the call with its code body.
static inline void swap_inline(int *x, int *y)
{
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

int main(void)
{
  int a = 10;
  int b = 27;
  printf("Before swap: \n\ta = %d\n\tb = %d\n", a, b);

  swapGNU(a, b);
  printf("After swapGNU: \n\ta = %d\n\tb = %d\n", a, b);

  swapNB(a, b);
  /* Break example:
     if (a > b)
       swapNB(a, b);
     else
       ...

     Would expand to:
     if (a > b)
     {
       int __swp_tmp__ = x;
       x = y;
       y = __swp_tmp__;
     }; <- "the semicolon is interpreted as an empty statement"
     else
       ...
  */
  printf("After swapNB: \n\ta = %d\n\tb = %d\n", a, b);

  swapISO(a, b);
  printf("After swapISO: \n\ta = %d\n\tb = %d\n", a, b);

  swap_inline(&a, &b);
  printf("After swap_inline: \n\ta = %d\n\tb = %d\n", a, b);

  return 0;
}
