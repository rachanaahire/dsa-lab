#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

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
        ptr = ptr->link;
    }
    printf("\n\n");
}

void add_end(struct node *head, int data)
{
    struct node *new_node = malloc(sizeof(struct node));
    struct node *temp = head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = new_node;
    new_node->data = data;
    new_node->link = NULL;
    traverse(head);
}

void add_between(struct node *head, int data, int afterData)
{
    struct node *new_node = malloc(sizeof(struct node));
    struct node *temp = head;
    while (temp->data != afterData)
    {
        temp = temp->link;
    }
    new_node->data = data;
    new_node->link = temp->link;
    temp->link = new_node;
    traverse(head);
}

void delete_end(struct node *head)
{
    struct node *temp = head;
    while (temp->link->link != NULL)
    {
        temp = temp->link;
    }
    free(temp->link);
    temp->link = NULL;
    traverse(head);
}

void delete_between(struct node *head, int data)
{
    struct node *temp1 = head;
    while (temp1->link->data != data)
    {
        temp1 = temp1->link;
    }
    struct node *temp2 = temp1->link;
    temp1->link = temp1->link->link;
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
    printf("\nEnter the data for node 1: ");
    scanf("%d", &data1);
    head->data = data1;
    head->link = NULL;

    struct node *current = malloc(sizeof(struct node));
    printf("\nEnter the data for node 2: ");
    scanf("%d", &data2);
    current->data = data2;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(struct node));
    printf("\nEnter the data for node 3: ");
    scanf("%d", &data3);
    current->data = data3;
    current->link = NULL;
    head->link->link = current;

    do
    {
        printf("Linked List option menu:\n");
        printf("Enter 1 to traverse\n");
        printf("Enter 2 to add node in end\n");
        printf("Enter 3 to add node in between\n");
        printf("Enter 4 to delete end node\n");
        printf("Enter 5 to delete in between node\n");
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
            add_end(head, addData);
            break;
        case 3:
            printf("\nEnter node data to add: ");
            scanf("%d", &addData);
            printf("Enter the data after which you want to add a node: ");
            scanf("%d", &addIndex);
            add_between(head, addData, addIndex);
            break;
        case 4:
            delete_end(head);
            break;
        case 5:
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