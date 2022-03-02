#include <stdio.h>
#include <ctype.h>
#define MAX 6

int CQ[MAX];
int count = 0;
int front = 0;
int rear = 0;

void view()
{
    int i;
    printf("\nELEMENTS IN QUEUE ARE: ");
    for (i = front; i < rear; i++)
    {
        printf("%d\t", CQ[i]);
    }
}

void insertCQ(int data)
{
    if (count == MAX)
        printf("Circular queue is full");
    else
    {
        CQ[rear++] = data;
        count++;
    }
    view();
}

void deleteCQ()
{
    if (count == 0)
    {
        printf("Circular queue is empty");
        count = 0;
    }
    else
    {
        printf("\nDELETED DATA: %d", CQ[front++]);
        count--;
    }
}

int main()
{
    int x;
    int data;
    do
    {
        printf("\n\nEnter 1 to insert into queue\n");
        printf("Enter 2 to delete from queue\n");
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