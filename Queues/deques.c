#include <stdio.h>
#define qsize 10

void insert_rear(int item, int *f, int *r, int q[])
{
    if(*r==qsize-1)
    {
        printf("Queue overflow \n");
        return;
    }
    *r =*r + 1;
    q[*r] = item;
}

void delete_front(int *f, int *r, int q[])
{
    int item;
    if(*f>*r)
    {
        printf("Queue is empty. \n");
        return;
    }
    item = q[*f];
    printf("Item deleted is %d \n", item);
    *f =*f+1;

    if(*f>*r)
    {
        *f=0;
        *r=-1;
    }
}

void insert_front(int item, int *f, int *r, int q[])
{
    if(*f==0 && *r != -1)
    {
        printf("You cannot insert front. \n");
        return;
    }
    if(*f==0)
    {
        *r += 1;
        q[*r] = item;
        return;
    }

    *f -= 1;
    q[*f] = item;
}

void delete_rear(int *f, int*r, int q[])
{
    int item;
    if(*f>*r)
    {
        printf("Queue is empty \n");
        return;
    }
    item = q[*r];
    printf("Item deleted %d \n", item);
    *r -= 1;
    if(*f>*r)
    {
        *f = 0;
        *r = -1;
    }
}

void display(int f, int r, int q[])
{
    int i;
    if(f>r)
    {
        printf("Queue is empty. \n");
        return;
    }   
    printf("The contents of the queue are: \n");
    for(i=f;i<=r;i++)
    {
        printf("%d \n", q[i]);
    }
}

int main()
{
    int choice;
    int q[qsize];
    int f = 0, r = -1;
    int item;
    for(;;)
    {
        printf("Enter 1.Insert_rear 2.Delete_Front 3.Insert_front 4.Delete_rear 5.Display and 6.Exit: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: printf("Enter the item: ");
                    scanf("%d", &item);
                    insert_rear(item, &f, &r, q);
                    break;
            case 2: delete_front(&f, &r, q);
                    break;
            case 3: printf("Enter the item: ");
                    scanf("%d", &item);
                    insert_front(item,&f,&r,q);
                    break;
            case 4:delete_rear(&f,&r,q);
                    break;
            case 5: display(f,r,q);
                    break;
            
            default: return 0;
        }
    }
    return 0;
}
