#include <stdio.h>
#define qsize 4

void insert_rear(int item, int *f, int *r, int q[], int *count)
{
    if(*count==qsize)
    {
        printf("Queue overflow \n");
        return;
    }
    *r =(*r + 1)%qsize;
    q[*r] = item;
    *count = *count + 1;
}

void delete_front(int *f, int *r, int q[], int *count)
{
    int item;
    if(*count == 0)
    {
        printf("Queue is empty. \n");
        return;
    }
    item = q[*f];
    printf("Item deleted is %d \n", item);
    *f =(*f+1)%qsize;
    *count = *count - 1;
}

void display(int f, int r, int q[], int count)
{
    int i;
    if(count==0)
    {
        printf("Queue is empty. \n");
        return;
    }   
    printf("The contents of the queue are: \n");
    for(i=1;i<=count;i++)
    {
        printf("%d \n", q[f]);
        f = (f+1)%qsize;
    }
}

int main()
{
    int choice;
    int q[qsize];
    int f = 0, r = -1;
    int item;
    int count = 0;
    for(;;)
    {
        printf("Enter 1.Insert_rear 2.Delete_Front 3.Display and 4.Exit: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: printf("Enter the item: ");
                    scanf("%d", &item);
                    insert_rear(item, &f, &r, q, &count);
                    break;
            case 2: delete_front(&f, &r, q, &count);
                    break;
            case 3: display(f,r,q,count);
                    break;
            default: return 0;
        }
    }
    return 0;
}
