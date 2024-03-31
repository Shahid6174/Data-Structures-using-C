#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct  node* llink;
    struct node* rlink;
};

typedef struct node* NODE;

NODE insert_node(int item, NODE root)
{
    NODE temp;
    NODE cur, prev;
    temp =  (NODE)malloc(sizeof(struct node));
    temp->info = item;
    temp->llink = temp->rlink = NULL;

    if(root == NULL)
        return temp;
    prev = NULL;
    cur = root;
    while(cur != NULL)
    {
        prev = cur;
        if(item<cur->info)
        {
            cur=cur->llink;
        }
        else
        {
            cur=cur->rlink;
        }
    }
    if(item<prev->info)
        prev->llink = temp;
    else
        prev->rlink = temp;
    return root;
}

void inorder(NODE root)
{
    if(root==NULL)
        return;
    inorder(root->llink);
    printf("%d ", root->info);
    inorder(root->rlink);
}

void preorder(NODE root)
{
    if(root==NULL)
        return;
    printf("%d ", root->info);
    preorder(root->llink);
    preorder(root->rlink);
}

void postorder(NODE root)
{
    if(root==NULL)
        return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d ", root->info);
}

NODE search_node(int item, NODE root)
{
    if(root==NULL || root->info == item)
        return root;
    if(item<root->info)
        return search_node(item, root->llink);
    return search_node(item, root->rlink);
}

int main()
{
    int choice, item;
    NODE root = NULL;

    for(;;)
    {
        printf("Enter 1.INSERT  2.DISPLAY   3.SEARCH    4.EXIT: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("\nEnter the item: ");
                    scanf("%d", &item);
                    root = insert_node(item, root);
                    break;
            case 2:printf("Inorder\n");
                    inorder(root);
                    printf("Preorder\n");
                    preorder(root);
                    printf("Postorder\n");
                    postorder(root);
                    break;
            case 3:printf("\nEnter the item to search: ");
                    scanf("%d", &item);
                    NODE temp;
                    temp = search_node(item, root);
                    if(temp == NULL)
                        printf("Key item not present,\n");
                    else
                        printf("Key element found: %d\n", temp->info);
                    break;
            default: return 0;
        }
    }
}
