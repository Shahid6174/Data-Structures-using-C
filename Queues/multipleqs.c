#include <stdio.h>
#define maxqs 5
#define qsize 10
int front[maxqs];
int rear[maxqs];
int q[qsize];
int n;

void delete_front(int i)
{
    if(front[i]>rear[i])
    {
        printf("Queue is empty.\n");
        return;
    }
    int item = q[front[i]];
    printf("Item deleted: %d\n", item);
    front[i] += 1;
    if(front[i]>rear[i])
    {
        front[i] = (qsize/n)*i;
        rear[i] = (qsize/n)*i-1;
    }
}

void insert_rear(int item, int i)
{
    if(rear[i] == front[i+1])
    {
        printf("Queue overflow\n");
        return;
    }   
    rear[i] += 1;
    q[rear[i]] = item;
}

void display(int i)
{
    if(front[i]>rear[i])
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("The contents of the queue are:\n");
    for(int j = front[i]; j<=rear[i]; j++)
    {
        printf("%d\n", q[j]);
    }
}

int main()
{
    int i, item, choice;

    printf("Enter number of queues: ");
    scanf("%d", &n);

    for(int j = 0; j<n; j++)
    {
        front[j] = (qsize/n)*j;
        rear[j] = (qsize/n)*j-1;

    }

    for(;;)
    {
        printf("1.Insert    2.Delete    3.Display   4.Exit: \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: printf("Enter queue number: ");
                scanf("%d", &i);
                printf("Enter item: ");
                scanf("%d", &item);
                insert_rear(item, i);
                break;    
        case 2: printf("Enter queue number: ");
                scanf("%d", &i);
                delete_front(i);
                break;
        case 3: printf("Enter queue number: ");
                scanf("%d", &i);
                display(i);
                break;
        default:return 0;
        }
    }
}