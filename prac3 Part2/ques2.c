#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *tail = NULL;

void traverse(struct node *tail)
{
    if (tail == NULL)
    {
        printf("Underflow");
    }

    struct node *p = tail->next;
    printf("\nTAIL ===========> %d", tail->data);
    printf("\n NODES: \t");
    do
    {
        printf("%d \t", p->data);
        p = p->next;
    } while (p != tail->next);

    printf("\n\n");
}

void addFirst(int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = tail->next;
    tail->next = newnode;
    traverse(tail);
}

void addEnd(int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = tail->next;
    tail->next = newnode;
    tail = newnode; //tail will become end node
    traverse(tail);
}

void addBetween(int data, int position)
{
    struct node *temp = tail;
    struct node *newnode = malloc(sizeof(struct node));
    while (position > 1)
    {
        temp = temp->next;
        position--;
    }
    newnode->data = data;
    newnode->next = temp->next;
    temp->next = newnode;
    traverse(tail);
}

void deleteFront()
{
    struct node *temp = tail->next;
    tail->next = temp->next;
    free(temp);
    traverse(tail);
}

void deleteEnd()
{
    struct node *temp = tail;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = tail->next;
    free(tail);
    tail = temp;
    traverse(tail);
}

void deleteBetween(int position)
{
    struct node *temp = tail;
    struct node *temp2 = tail;
    while (position > 0)
    {
        temp2 = temp;
        temp = temp->next;
        position--;
    }
    temp2->next = temp->next;
    free(temp);
    traverse(tail);
}

int main()
{
    int d1, x, data, index;
    struct node *temp = malloc(sizeof(struct node));
    printf("Enter the data for first node: ");
    scanf("%d", &d1);
    temp->data = d1;
    temp->next = temp;
    tail = temp;
    printf("\n Node created successfully!!");
    do
    {
        printf("Linked List option menu:\n");
        printf("Enter 1 to traverse\n");
        printf("Enter 2 to add node in front\n");
        printf("Enter 3 to add node in end\n");
        printf("Enter 4 to add node in between\n");
        printf("Enter 5 to delete front node\n");
        printf("Enter 6 to delete end node\n");
        printf("Enter 7 to delete in between\n");
        printf("Enter 0 to exit\n");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            traverse(tail);
            break;
        case 2:
            printf("\nEnter node data to add at first: ");
            scanf("%d", &data);
            addFirst(data);
            break;
        case 3:
            printf("\nEnter node data to add at end: ");
            scanf("%d", &data);
            addEnd(data);
            break;
        case 4:
            printf("\nEnter node data to add: ");
            scanf("%d", &data);
            printf("\nEnter the index to add data in: ");
            scanf("%d", &index);
            addBetween(data, index);
            break;
        case 5:
            deleteFront();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            printf("\nEnter index of data to be deleted: ");
            scanf("%d", &data);
            deleteBetween(data);
            break;
        default:
            break;
        }
    } while (x != 0);
}