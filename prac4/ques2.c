// Implement queue using linked list.
#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue *next;
};

struct queue *front = NULL;
struct queue *rear = NULL;

void view()
{
    struct queue *temp = front;
    printf("\nELEMENTS IN QUEUE ARE: ");
    while (temp->next != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("%d\t", temp->data);
}

void insert(int data)
{
    struct queue *newnode = malloc(sizeof(struct queue));
    newnode->data = data;
    newnode->next = NULL;
    // if (newnode == NULL)
    // {
    //     printf("Queue is full");
    // }
    if (front == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next = newnode; //inserting new node in end
        rear = newnode;       //updating rear with last node
    }
    view();
}

void deleteQ()
{
    struct queue *temp;
    if (front == NULL)
    {
        printf("Empty queue");
    }
    temp = front;
    front = front->next;
    free(temp);
    view();
}

int main()
{
    int x;
    int data;
    do
    {
        printf("\nEnter 1 to insert into queue\n");
        printf("Enter 2 to delete from queue\n");
        printf("Enter 3 to view\n");
        printf("Enter 0 to exit\n");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            printf("Enter data to PUSH ");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            deleteQ();
            break;
        case 3:
            view();
            break;
        default:
            break;
        }
    } while (x);
    return 0;
}