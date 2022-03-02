#include <stdio.h>
#include <ctype.h>
#include <string.h>
char stack[6][20];
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
    else
    {
        stack[top][0] = x[0];
    }

    //stack[++top] = x;
}

void pushA(char x)
{
    // char *r = x;
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
    char str[20] = "ABC/+";
    char exp[20], *e;
    char *operand1, *operand2, operator;
    n = strlen(str);
    for (i = 0; i < n; i++)
    {
        //char *r = &str[i];
        if (isalnum(str[i]))
        {
            pushA(str[i]);
            //  printf("\n%c", str[i]);
        }
        else
        {
            char buffer[50];
            //printf("%c", str[i]);
            //printf("%s", pop());
            operand1 = pop();
            operand2 = pop();
            printf("\n OPERAN1: %s", operand1);
            printf("\n OPERAN2: %s", operand2);
            sprintf(buffer, "( %s %c %s )", operand2, str[i], operand1);
            push(buffer);
            // push(buffer);
            // exp[0] = "(";
            // push(*exp);
        }
    }
    // char buffer[50];
    // sprintf(buffer, "( %s %s %s )", operand2, operator, operand1);
    // printf("%s", buffer);
    // char str[20] = "A+B";
    // push(str);
    // char *o = "O";
    // push(o);

    //push(*exp);
    // char *p = pop();
    // printf("%s", p);

    printf("\n%s", stack[top]);
    return 0;
}