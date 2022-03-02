// POSTFIX TO INFIX - ABC*+ , ABCD^*+
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 40
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
    printf("\nENTER THE POSTFIX EXPRESSION: ");
    gets(str);
    char *operand1, *operand2;
    n = strlen(str);
    for (i = 0; i < n; i++)
    {
        if (isalnum(str[i]))
        {
            pushOperand(str[i]);
        }
        else
        {
            char buffer[50];
            operand1 = pop();
            operand2 = pop();
            sprintf(buffer, "( %s %c %s )", operand2, str[i], operand1);
            push(buffer);
        }
    }

    printf("\n INFIX EXPRESSION IS : %s", pop());
    return 0;
}