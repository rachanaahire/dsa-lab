// INFIX TO POSTFIX K+L-M*N+(O^P)*W/U/V*T+Q 

#include <stdio.h>
#include <ctype.h>
char stack[30];
int top = -1;

void push(char x)
{
    stack[++top] = x;
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
    printf("Enter the expression here: \n");
    scanf("%s", &exp);

    e = exp;
    printf("POSTFIX EXPRESSION IS : ");
    while (*e != '\0')
    {
        if (isalnum(*e)) // OPERAND
        {
            printf("%c", *e);
        }
        else if (top == -1 || stack[top] == '(') // OPERATOR
        {
            push(*e);
        }
        else // OPERATOR
        {
            if (*e == '(')
            {
                push(*e);
            }
            else if (*e == ')')
            {
                while ((x = pop()) != '(')
                {
                    printf("%c", x);
                }
            }
            else
            {
                while (precedence(stack[top]) > precedence(*e)) // lower precedence than top
                {
                    printf("%c", pop());
                }
                if (precedence(stack[top]) < precedence(*e))
                {
                    push(*e);
                }
                else
                {
                    if (associativity(*e) == 1)
                    {
                        push(*e);
                    }
                    else if (associativity(*e) == 2)
                    {
                        printf("%c", pop());
                        push(*e);
                    }
                }
            }
        }
        e++;
    }
    while (top != -1)
    {
        printf("%c", pop());
    }
    return 0;
}