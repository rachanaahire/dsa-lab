// Implement stack operations using array
#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int stack_array[MAX];
int top = -1;

void size()
{
    printf("There are %d elements inside stack\n", top + 1);
}

void view()
{
    int i;
    printf("STACK with %d elements : ", top + 1);
    for (i = 0; i <= top; i++)
    {
        printf("%d\t", stack_array[i]);
    }
    printf("\n");
    size();
}

void push(int data)
{
    if (top == MAX - 1)
    {
        printf("push %d : Stack Overflow\n", MAX + 1);
        return;
    }
    stack_array[++top] = data;
    view();
}

void pop()
{
    if (top == -1)
    {
        printf("Stack UnderFlow");
        return;
    }
    printf("Popped data: %d\n", stack_array[top--]);
    view();
}

int main()
{
    int x;
    int data;
    int items;
    int ind;
    int i;
    do
    {
        printf("\nEnter 1 to push onto stack\n");
        printf("Enter 2 to pop from stack\n");
        printf("Enter 3 to view\n");
        printf("Enter 4 to get size of stack with elements\n");
        printf("Enter 0 to exit\n");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            printf("How many elements you want to push inside the stack? ");
            scanf("%d", &items);
            ind = top + 1;
            for (i = ind; i < ind + items; i++)
            {
                printf("\nEnter data %d to Push : ", i + 1);
                scanf("%d", &data);
                push(data);
            }
            break;
        case 2:
            pop();
            break;
        case 3:
            view();
            break;
        case 4:
            size();
            break;
        default:
            break;
        }
    } while (x);

    return 0;
}