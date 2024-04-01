#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int count = 0;

struct node
{
    int info;
    struct node* llink;
    struct node* rlink;
};

typedef struct node* NODE;

NODE insert_node(int item, NODE root)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->info = item;
    temp->llink = temp->rlink = NULL;

    NODE cur, prev;
    char direction[20];
    int i;

    if(root==NULL)
    {
        return temp;
    }

    printf("Give the directions: ");
    scanf("%s", direction);

    prev = NULL;
    cur = root;
    for(i=0; i<strlen(direction) && cur!=NULL; i++)
    {
        prev = cur;
        if(direction[i] == 'l')
        {
            cur=cur->llink;
        }
        else
        {
            cur = cur->rlink;
        }
    }
    if(cur!=NULL || i!=strlen(direction))
    {
        printf("Insertion not possible\n");
        free(temp);
        return root;
    }
    if(direction[i-1]=='l')
    {
        prev->llink = temp;
    }
    else
    {
        prev->rlink = temp;
    }
    return root;
}

void display(NODE root, int height) //display in the form of tree
{
    int i;
    if(root==NULL)
    {
        return;
    }
    display(root->rlink, height + 1);
    for(i=0;i<height;i++)
        printf("--");
    printf("%d\n", root->info);
    display(root->llink, height+1);
}

void level_order(NODE root) //display in levels
{
    NODE q[100], cur;
    int f=0, r=-1;

    r+=1;
    q[r] = root;

    while(f<=r)
    {
        cur = q[f];
        f += 1;
        printf("%d\t", cur->info);

        if(cur->llink != NULL)
        {
            r += 1;
            q[r] = cur->llink;
        }
        if(cur->rlink != NULL)
        {
            r += 1;
            q[r] = cur->rlink;
        }
    }
}

void count_nodes(NODE root)
{
    if(root==NULL)
    {
        return;
    }
    count_nodes(root->llink);
    count++;
    count_nodes(root->rlink);
}

int max(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}

int height(NODE root)
{
    if(root==NULL)
    {
        return 0;
    }
    return(max(height(root->llink),height(root->rlink))+1);
}

NODE copy(NODE root)
{
    NODE temp;
    if(root==NULL)
    {
        return NULL;
    }
    temp = (NODE)malloc(sizeof(struct node));
    temp->info = root->info;
    temp->llink = copy(root->llink);
    temp->llink = copy(root->rlink);

    return temp;
}

int main() {
    NODE root = NULL;
    int choice;

    for (;;) {
        printf("\n1. Insert Node\n");
        printf("2. Display Tree\n");
        printf("3. Display Level Order\n");
        printf("4. Count Nodes\n");
        printf("5. Height of Tree\n");
        printf("6. Copy Tree\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                int value;
                scanf("%d", &value);
                root = insert_node(value, root);
                break;
            case 2:
                printf("Tree in tree form:\n");
                display(root, 0);
                break;
            case 3:
                printf("Level order traversal:\n");
                level_order(root);
                printf("\n");
                break;
            case 4:
                count = 0;
                count_nodes(root);
                printf("Number of nodes: %d\n", count);
                break;
            case 5:
                printf("Height of tree: %d\n", height(root));
                break;
            case 6:
                printf("Copying tree...\n");
                NODE copied_root = copy(root);
                printf("Original tree:\n");
                display(root, height(root));
                printf("Copied tree:\n");
                display(copied_root, height(copied_root));
                break;
            case 7:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
