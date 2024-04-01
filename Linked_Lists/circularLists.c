#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node * link;
};
typedef struct node * NODE;

NODE insert_rear(int item, NODE last)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->info = item;
    temp->link = temp;
    if(last==NULL)
    {
        return temp;
    }
    temp->link = last->link;
    last->link = temp;
    return temp;
}
NODE delete_front(NODE last)
{
    NODE first;
    if(last == NULL)
    {
        printf("List is empty. \n");
        return last;
    }
    if(last->link == NULL)
    {
        printf("The item deleted is %d \n",last->info);
        free(last);
        return NULL;
    }
    first = last->link;
    last->link = first -> link;
    printf("The item deleted is %d \n",first->info);
    free(first);
    return last;
}
NODE insert_front(int item, NODE last)
{
    NODE cur, temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->info = item;
    temp->link = temp;
    if(last == NULL)
    {
        return temp;
    }
    temp->link=last->link;
    last->link=temp;
    return last;
}
NODE delete_rear(NODE last)
{
    NODE cur, prev;
    if(last == NULL)
    {
        printf("List is empty \n");
        return last;
    }
    if(last->link == NULL)
    {
        printf("Item deleted %d \n",last->info);
        free(last);
        return NULL;
    }
    cur = last->link;
    prev = NULL;
    while(cur->link != last)
    {
        cur = cur->link;
    }
    cur->link = last->link;
    printf("Item deleted %d\n", last->info);
    free(last);
    return cur;
}
void display(NODE last)
{
    NODE cur;
    if(last == NULL)
    {
        printf("List is empty \n");
        return;
    }
    cur = last->link;
    printf("The contents of the list are: \n");
    while(cur != last)
    {
        printf("%d \n", cur->info);
        cur = cur->link;
    }
    printf("%d\n", last->info);
}

void main()
{
    int choice, item;
    NODE last = NULL;
    for(;;)
    {
        printf("Enter 1.Insert_front 2.Delete_front 3.Insert_rear 4.Delete_rear 5.Display and 6.Exit: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter the item: ");
                    scanf("%d", &item);
                    last = insert_front(item,last);
                    break;
            case 2:last = delete_front(last);
                    break;
            case 3:printf("Enter the item: ");
                    scanf("%d", &item);
                    last = insert_rear(item, last);
                    break;
            case 4:last = delete_rear(last);
                    break;
            case 5:display(last);
                    break;
            default:return;
        }
    }
}