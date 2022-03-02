#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL;

void traverse(struct node *head)
{
    if (head == NULL)
    {
        printf("linked list empty");
    }
    struct node *ptr = head;
    printf("\nNodes data: ");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}

void addFirst(int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->next = head;
    newnode->data = data;
    head->prev = newnode; //assigning previous first nodes PREV with new node
    head = newnode; //new head node assigned
    traverse(head);
}

void addEnd(int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    struct node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newnode->prev = temp;
    newnode->next = NULL;
    newnode->data = data;
    temp->next = newnode;
    traverse(head);
}

void addBetween(int data, int after_data)
{
    struct node *newnode = malloc(sizeof(struct node));
    struct node *temp = head;

    while (temp->data != after_data)
    {
        temp = temp->next;
    }
    newnode->prev = temp;
    newnode->next = temp->next;
    newnode->data = data;
    temp->next->prev = newnode;
    temp->next = newnode;
    traverse(head);
}

void deleteFront()
{
    struct node *temp = head;

    if (temp->prev == NULL)
    {
        temp->next->prev = NULL;
        head = temp->next;
        free(temp);
    }
    traverse(head);
}

void deleteEnd()
{
    struct node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    traverse(head);
}

void deleteBetween(int position)
{
    struct node *temp = head;
    struct node *t2;
    while (position > 1)
    {
        temp = temp->next;
        position--;
    }
    t2 = temp->prev;
    t2->next = temp->next;
    temp->next->prev = t2;
    free(temp);
    traverse(head);
}

int main()
{
    int d1, x, data, add_sdata;
    head = malloc(sizeof(struct node));
    printf("Enter data for First node: ");
    scanf("%d", &d1);
    head->prev = NULL;
    head->next = NULL;
    head->data = d1;
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
        printf("Enter 7 to delete in between node\n");
        printf("Enter 0 to exit\n");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            traverse(head);
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
            printf("Enter the data after which you want to add a node: ");
            scanf("%d", &add_sdata);
            addBetween(data, add_sdata);
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
    return 0;
}