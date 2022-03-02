#include <stdio.h>
#include <ctype.h>
#include <string.h>
char stack[6];
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
int main()
{
    char *exp;
    char *e, x, operator1, operator2;

    printf("Enter the expression here: \n");
    scanf("%s", &exp);
    e = exp;
    while (*e != '\0')
    {
        if (isalnum(*e)) // OPERAND
        {
            //printf("%c\t", *e);
            push(*e);
        }
        else // OPERATOR
        {
            operator1 = stack[top];
            pop();
            operator1 = stack[top];
            pop();
            exp = '(' + operator1 + *e + operator2 + ')';
            push(exp);
            //printf("%c", *e);
            //printf("%c %c %c", pop(), *e, pop());
        }
        e++;
        printf(stack[top]);
    }
    return 0;
}