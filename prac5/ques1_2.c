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
    printf("\nFRONT =======> %d", front->data);
    printf("\nELEMENTS IN QUEUE ARE: ");
    while (temp->next != front)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("%d\t", temp->data);
}

void insertCQ(int data)
{
    struct queue *newnode = malloc(sizeof(struct queue));
    newnode->data = data;
    newnode->next = front;
    if (front == NULL)
    {
        front = newnode;
        front->next = front;
        rear = newnode;
    }
    else
    {
        rear->next = newnode; //inserting new node in end
        rear = newnode;       //updating rear with last node
    }
    view();
}

void deleteCQ()
{
    struct queue *temp = malloc(sizeof(struct queue));
    if (front == NULL)
    {
        printf("Empty queue");
    }
    printf("\nPOPPED: %d\n", front->data);
    temp = front->next;
    free(front);
    front = NULL;
    front = temp;
}

int main()
{
    int x;
    int data;
    do
    {
        printf("\n\nEnter 1 to insert into CIRCULAR queue\n");
        printf("Enter 2 to delete from CIRCULAR queue\n");
        printf("Enter 3 to view\n");
        printf("Enter 0 to exit\n");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            printf("Enter data to PUSH ");
            scanf("%d", &data);
            insertCQ(data);
            break;
        case 2:
            deleteCQ();
            break;
        default:
            break;
        }
    } while (x);
    return 0;
}