/* Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator.
   Add the modulus (%) and unary minus operators. Add an "erase" command which erases the
   top entry on the stack. Add commands for handling variables.
   (Twenty-six single-letter variable names is easy.)
*/

#include <stdio.h>

#define BUFSIZE 100
#define MAXVAL 100 // Maximum depth of val stack
#define MAXOP 20   // Max size of operand, operator
#define NUMBER '0' // Signal that number found
#define TOOBIG '9' // Signal that string is too big
#define VAR 'A'    // Signal that variable found
#define ASSIGN '$' // Signal to assign value to var

// Prototypes
int getop(char *s, int max);
int getch();
void ungetch(int c);

double pop();
double push(double x);
double peak();
void clear();

double atof(char *s);
int is_digit(int c);
int is_lower(int c);

// Globals
char chbuf[BUFSIZE]; // Input char buffer
int bufp = 0;        // chbuf pointer

double vstk[MAXVAL]; // Value stack
int sp = 0;          // Stack pointer
double vars[26];     // Variables a-z

int main()
{
    for (int i = 0; i < 26; ++i)
        vars[i] = 0.0;

    int type;
    char s[MAXOP];
    double op2;

    printf("Operators:\n\tAdition -> '+'\n\tMultiplication -> '*'\n\tSubtraction -> '-'\n\tDivision -> '/'\n\tModulus -> '%%'\nMisc:\n\tClear -> 'C'\n\tErase -> '<'\n\tVariables -> 'a-z' (lower-case)\n\tAssign Var -> '@' (`10 a @` for a = 10)\n");
    printf("==================================================\n");

    while ((type = getop(s, MAXOP)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case VAR:
                push(vars[s[0] - 'a']);
                break;
            case ASSIGN:
                vars[s[0] - 'a'] = peak();
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
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
                    printf("zero divisor popped");
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
                printf("%.20s ... is too long\n", s);
                break;
            default:
                printf("unknown command %c\n", type);
                break;
        }
    }
}

int getop(char *s, int max)
{
    int i, c, nextch;

    while ((c = getch()) == ' ' || c == '\n' || c == '\t')
        ;

    s[0] = c;
    s[1] = '\0';
    i = 1;

    if (c != '.' && (!is_digit(c)) && c != '-')
    {
        if (is_lower(c))
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
            return c; // Return operator
    }

    // Check for negative number (unary minus)
    if (c == '-')
    {
        nextch = getch();
        if (!is_digit(nextch) && nextch != '.')
        {   // It was a subtraction operator
            ungetch(nextch);
            return '-';
        }
        c = nextch;
        s[i++] = c;
    }

    for (c = getch(); i < max && is_digit(c); ++i, c = getch())
        s[i] = c;

    if (c == '.' && i < max)
    {
        s[i] = c;
        for (++i, c = getch(); i < max && is_digit(c); ++i, c = getch())
            s[i] = c;
    }

    if (i < max)
    {
        ungetch(c);
        s[i] = '\0';
        return NUMBER;
    }
    else
    {
        while (c != '\n' && c != EOF)
            c = getchar(); // clear input
        s[max - 1] = '\0';
    }
    return TOOBIG;
}

int getch()
{
    return (bufp > 0) ? chbuf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many chars / buffer full\n");
    else
        chbuf[bufp++] = c;
}

double pop()
{
    if (sp > 0)
        return vstk[--sp];
    else
    {
        printf("Error: stack empty\n");
        clear();
    }
    return 0;
}

double push(double x)
{
    if (sp < MAXVAL)
        return (vstk[sp++] = x);
    else
    {
        printf("Error: stack full\n");
        clear();
    }
    return 0;
}

double peak()
{
    if (sp > 0)
        return vstk[sp - 1];
    else
        return 0;
}

void clear()
{
    sp = 0;
}

double atof(char *s)
{
    int i, exp, sign;
    double val, power;

    for (i = 0; s[i] == ' ' || s[i] == '\n' || s[i] == '\t'; ++i)
        ; // Skip whitespace

    sign = 1;
    if (s[i] == '+' || s[i] == '-')
        sign = (s[i++] == '-') ? -1 : 1;

    for (val = 0; is_digit(s[i]); ++i)
        val = val * 10.0 + s[i] - '0';

    if (s[i] == '.')
        ++i;

    for (power = 1; is_digit(s[i]); ++i)
    {
        power *= 10.0;
        val = val * 10.0 + s[i] - '0';
    }

    val = sign * (val / power);

    // Check for scientific notation
    if (s[i] == 'e' || s[i] == 'E')
    {
        ++i;
        sign = 1;
        if (s[i] == '+' || s[i] == '-')
            sign = (s[i++] == '-') ? -1 : 1;

        for (exp = 0; is_digit(s[i]); ++i)
            exp = exp * 10 + s[i] - '0';

        power = 1.0;
        for (int j = 0; j < exp; ++j)
            power *= 10.0;

        if (sign > 0)
            val *= power;
        else
            val /= power;
    }

    return val;
}

int is_digit(int c)
{
    return c >= '0' && c <= '9';
}

int is_lower(int c)
{
    return c >= 'a' && c <= 'z';
}
