// PREFIX TO POSTFIX +A*B^CD  +A*BC
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 20
char stack[6][MAX];
int top = -1;

void push(char *x)
{
    ++top;
    int i, n;
    n = strlen(x);
    if (n > 1)
    {
        for (i = 0; i < n; i++)
        {
            stack[top][i] = x[i];
        }
    }
}

void pushOperand(char x)
{
    stack[++top][0] = x;
}

char *pop()
{
    if (top == -1)
    {
        return "Stack UnderFlow";
    }
    else
    {
        return stack[top--];
    }
}
int main()
{
    int i, n;
    char str[MAX];
    char *e, *infix_data;
    printf("\nENTER THE POSTFIX EXPRESSION: ");
    gets(str);
    char *operand1, *operand2;
    n = strlen(str);
    for (i = n - 1; i > -1; i--)
    {
        if (isalnum(str[i]))
        {
            pushOperand(str[i]);
        }
        else
        {
            operand1 = pop();
            operand2 = pop();
            char buffer[50];
            sprintf(buffer, "%s %s %c", operand1, operand2, str[i]);
            push(buffer);
        }
    }
    printf("\n PREFIX EXPRESSION IS : %s", pop());
    return 0;
}
