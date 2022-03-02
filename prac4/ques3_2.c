// INFIX TO PREFIX K+L-M*N+(O^P)*W/U/V*T+Q 

#include <stdio.h>
#include <ctype.h>
#include <string.h>
char stack[30];
char prefix_data[30];
int top = -1;
int ind = -1;

void pushStack(char x)
{
    stack[++top] = x;
}

void pushData(char x)
{
    prefix_data[++ind] = x;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack UnderFlow");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

char printPrefix()
{
    return prefix_data[ind--];
}

int precedence(char x)
{
    if (x == '(')
    {
        return 0;
    }
    if (x == '^')
    {
        return 1;
    }
    if (x == '+' || x == '-')
    {
        return 2;
    }
    if (x == '/' || x == '*')
    {
        return 3;
    }
}

int associativity(char x)
{
    if (x == '^') // R - L
    {
        return 1;
    }
    if (x == '+' || x == '-' || x == '/' || x == '*') // L - R
    {
        return 2;
    }
}

int main()
{
    char exp[30];
    char *e, x;
    int i;

    printf("Enter the expression here: \n");
    scanf("%s", &exp);

    e = strrev(exp);
    printf("PREFIX EXPRESSION IS : ");
    while (*e != '\0')
    {
        if (isalnum(*e)) // OPERAND
        {
            pushData(*e);
        }
        else if (top == -1 || stack[top] == ')') // OPERATOR
        {
            pushStack(*e);
        }
        else // OPERATOR
        {
            if (*e == ')')
            {
                pushStack(*e);
            }
            else if (*e == '(')
            {
                while ((x = pop()) != ')')
                {
                    pushData(x);
                }
            }
            else
            {
                while (precedence(stack[top]) > precedence(*e)) // lower precedence than top
                {
                    pushData(pop());
                }
                if (precedence(stack[top]) < precedence(*e))
                {
                    pushStack(*e);
                }
                else
                {
                    if (associativity(*e) == 1)
                    {
                        pushData(pop());
                        pushStack(*e);
                    }
                    else if (associativity(*e) == 2)
                    {
                        pushStack(*e);
                    }
                }
            }
        }
        e++;
    }
    for (i = 0; i <= top; i++)
    {
        printf("%c", stack[i]);
    }
    printf("%s", strrev(prefix_data));

    return 0;
}