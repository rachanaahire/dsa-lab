// PREFIX TO INFIX +A*B^CD  +A*BC
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
    printf("\nENTER THE PREFIX EXPRESSION: ");
    scanf("%s", &str);
    e = strrev(str);
    char *operand1, *operand2;
    while (*e != '\0')
    {
        if (isalnum(*e)) // OPERAND
        {
            pushOperand(*e);
        }
        else // OPERATOR
        {
            char buffer[50];
            operand1 = pop();
            operand2 = pop();
            sprintf(buffer, ") %s %c %s (", operand2, *e, operand1);
            push(buffer);
        }
        e++;
    }
    infix_data = pop();
    printf("\n INFIX EXPRESSION IS : %s", strrev(infix_data));
    return 0;
}
