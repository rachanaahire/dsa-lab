#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *addToEmpty(struct node *head)
{
    //struct node *temp = malloc(sizeof(struct node));
}

void traverse(struct node *head)
{
    if (head == NULL)
    {
        printf("linked list empty");
    }
    struct node *ptr = NULL;
    ptr = head;
    printf("\nNodes data: ");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n hi");
}

void add_first(struct node *head, int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->data = data;
    newnode->next = head;
    head = newnode;
    traverse(head);
    //return head;
}

void add_end(struct node *head, int data)
{
    struct node *new_node = malloc(sizeof(struct node));
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
    new_node->data = data;
    new_node->next = NULL;
    traverse(head);
}

void add_between(struct node *head, int data, int afterData)
{
    struct node *new_node = malloc(sizeof(struct node));
    struct node *temp = head;
    while (temp->data != afterData)
    {
        temp = temp->prev;
    }
    new_node->prev = temp; // new node prev
    new_node->data = data;
    new_node->next = temp->next; //newnode next
    temp->next = new_node;       //before node next
    temp->next->prev = new_node; // after node Prev
    traverse(head);
}

void delete_end(struct node *head)
{
    struct node *temp = head;
    while (temp->prev->prev != NULL)
    {
        temp = temp->prev;
    }
    free(temp->prev);
    temp->prev = NULL;
    traverse(head);
}

void delete_between(struct node *head, int data)
{
    struct node *temp1 = head;
    while (temp1->prev->data != data)
    {
        temp1 = temp1->prev;
    }
    struct node *temp2 = temp1->prev;
    temp1->prev = temp1->prev->prev;
    free(temp2);
    traverse(head);
}

int main()
{
    int options;
    int data1, data2, data3;
    int addData;
    int addIndex;
    int delIndex;
    struct node *head;                  //declare head pointer
    head = malloc(sizeof(struct node)); //allocated memory
    printf("\nEnter the data for FIRST node : ");
    scanf("%d", &data1);
    head->prev = NULL;
    head->data = data1;
    head->prev = NULL;

    do
    {
        printf("Linked List option menu:\n");
        printf("Enter 1 to traverse\n");
        printf("Enter 2 to add node in front\n");
        printf("Enter 3 to add node in end\n");
        printf("Enter 4 to add node in between\n");
        printf("Enter 5 to deleted end node\n");
        printf("Enter 6 to delete in between node\n");
        printf("Enter 0 to exit\n");
        scanf("%d", &options);
        switch (options)
        {
        case 1:
            traverse(head);
            break;
        case 2:
            printf("\nEnter node data to add: ");
            scanf("%d", &addData);
            add_first(head, addData);
            break;
        case 3:
            printf("\nEnter node data to add: ");
            scanf("%d", &addData);
            add_end(head, addData);
            break;
        case 4:
            printf("\nEnter node data to add: ");
            scanf("%d", &addData);
            printf("Enter the data after which you want to add a node: ");
            scanf("%d", &addIndex);
            add_between(head, addData, addIndex);
            break;
        case 5:
            delete_end(head);
            break;
        case 6:
            printf("Enter the data to be deleted: ");
            scanf("%d", &delIndex);
            delete_between(head, delIndex);
            break;
        default:
            break;
        }
    } while (options != 0);

    //traverse(head);
    // add_end(head, 69);
    // add_between(head, 45);
    // delete_end(head);
    // delete_between(head, 90);
    return 0;
}