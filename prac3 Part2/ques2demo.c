#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *addEnd(struct node *head, int data, struct node *tail)
{
    struct node *temp = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    tail->next = newnode;
    tail = newnode;
    return head;
}

void traverse(struct node *head)
{
    struct node *temp = head;

    while (temp->next != head)
    {
        printf("%d", temp->data);
        printf("\n");
        temp = temp->next;
    }
    printf("%d", temp->data);
}

struct node *addFront(struct node *head, int data, struct node *tail)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->next = head;
    tail->next = p;
    head = p;
    return head;
}

struct node *addBetween(struct node *head, int value, int inx)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    struct node *temp, *temp2;
    temp = head;
    temp2 = NULL;
    for (int i = 0; i < inx - 1; i++)
    {
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = p;
    p->data = value;
    p->next = temp;

    return head;
}

struct node *deleteFront(struct node *head, struct node *tail)
{
    struct node *temp = head;
    temp = temp->next;
    tail->next = temp;
    head = temp;
    return head;
}
struct node *deleteEnd(struct node *head, struct node *tail)
{
    struct node *temp = head;
    struct node *temp2;
    while (temp != tail)
    {
        temp2 = temp;
        temp = temp->next;
    }
    tail = temp2;
    temp2->next = head;
    free(temp);
    temp = 0;
    return tail;
}

int main()
{
    int n, choice, value, inx;
    struct node *p, *temp, *head;
    printf(" enter the no of nodes you want to enter :");
    scanf("%d", &n);
    head = NULL;
    for (int i = 0; i < n; i++)
    {
        p = (struct node *)malloc(sizeof(struct node *));
        printf("enter the data for node %d ", i + 1);
        scanf("%d", &p->data);
        if (head == 0)
        {
            head = p;
            p->next = p;
        }
        else
        {
            p->next = head;
            temp->next = p;
        }
        temp = p;
    }
    struct node *tail = temp;
    do
    {
        printf("\n linked list operations menu :\n");
        printf("press 1 to traverse the list .\n");
        printf("press 2 to insert an element at first.\n");
        printf("press 3 to insert an element at specific index\n");
        printf("press 4 to insert an element at end.\n");
        printf("press 5 to delete an element at first .\n");
        printf("press 6 to delete an element from specific index.\n");
        printf("press 7 to delete an element from end.\n");
        printf("press 0 to exit.\n ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            continue;

        case 1:
            traverse(head);
            break;

        case 2:
            printf("\nEnter the data to insert: ");
            scanf("%d", &value);
            head = addFront(head, value, tail);
            break;

        case 3:
            printf("\n enter the data to insert :");
            scanf("%d", &value);
            printf("\n enter the index at which to insert :");
            scanf("%d", &inx);
            head = addBetween(head, value, inx);
            break;

        case 4:
            printf("\n enter the data to insert :");
            scanf("%d", &value);
            head = addEnd(head, value, tail);
            break;

        case 5:
            head = deleteFront(head, tail);
            break;

        case 6:
            printf("\n enter the index to delete :");
            scanf("%d", &inx);
            //head=deleteBetween(head,inx);
            break;

        case 7:
            tail = deleteEnd(head, tail);
            break;

        default:
            printf("enter a valid choice.\n");
            break;
        }
    } while (choice != 0);
}