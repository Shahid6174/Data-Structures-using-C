#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node * link;
};
typedef struct node * NODE;

NODE insert_front(int item, NODE first)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->info = item;
    temp->link = first;
    return temp;
}
NODE delete_front(NODE first)
{
    NODE temp;
    if(first == NULL)
    {
        printf("List is empty. \n");
        return first;
    }
    temp = first;
    first = first -> link;
    printf("The item deleted is %d \n",temp->info);
    free(temp);
    return first;
}
NODE insert_rear(int item, NODE first)
{
    NODE cur, temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->info = item;
    temp->link = NULL;
    if(first == NULL)
    {
        return temp;
    }
    cur=first;
    while(cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}
NODE delete_rear(NODE first)
{
    NODE cur, prev;
    if(first == NULL)
    {
        printf("List is empty \n");
        return first;
    }
    if(first->link == NULL)
    {
        printf("Item deleted %d \n",first->info);
        free(first);
        return NULL;
    }
    cur = first;
    prev = NULL;
    while(cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    printf("Item deleted %d", cur->info);
    free(cur);
    prev->link = NULL;
    return first;
}
void display(NODE first)
{
    NODE cur;
    if(first == NULL)
    {
        printf("List is empty \n");
        return;
    }
    cur = first;
    printf("The contents of the list are: \n");
    while(cur != NULL)
    {
        printf("%d \n", cur->info);
        cur = cur->link;
    }
}

void main()
{
    int choice, item;
    NODE first = NULL;
    for(;;)
    {
        printf("Enter 1.Insert_front 2.Delete_front 3.Insert_rear 4.Delete_rear 5.Display and 6.Exit: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter the item: ");
                    scanf("%d", &item);
                    first = insert_front(item,first);
                    break;
            case 2:first = delete_front(first);
                    break;
            case 3:printf("Enter the item: ");
                    scanf("%d", &item);
                    first = insert_rear(item, first);
                    break;
            case 4:first = delete_rear(first);
                    break;
            case 5:display(first);
                    break;
            default:return;
        }
    }
}