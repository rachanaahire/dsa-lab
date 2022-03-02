// Implement stack operations using linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *top = NULL;

void size()
{
    int count = 0;
    struct node *temp = top;
    while (temp->link != NULL)
    {
        count++;
        temp = temp->link;
    }
    count++;
    printf("\nSIZE OF STACK: %d \n", count);
}

void view()
{
    struct node *temp = top;
    printf("\nSTACK ELEMENTS: ");
    while (temp->link != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->link;
    }
    printf("%d", temp->data);
    size();
}

void push(int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->link = NULL;

    if (top == NULL)
    {
        top = newnode;
    }
    else
    {
        newnode->link = top; //linking with previous node
        top = newnode;
    }
    view();
}

void pop()
{
    struct node *temp = malloc(sizeof(struct node));
    if (top == NULL)
    {
        printf("\nUNDERFLOW\n");
    }

    if (top->link == NULL)
    {
        printf("\nPOPPED: %d\n", top->data);
        free(top);
        top = NULL;
    }
    else
    {
        temp = top->link;
        printf("\nPOPPED: %d\n", top->data);
        free(top);
        top = temp;
    }
    view();
}

int main()
{
    int x;
    int data;
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
            printf("Enter data to PUSH ");
            scanf("%d", &data);
            push(data);
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
