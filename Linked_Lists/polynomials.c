#include <stdio.h>
#include <stdlib.h>

struct node
{
    int cf;
    int px;
    struct node* link;
};

typedef struct node* NODE;

void display(NODE head)
{
    NODE cur;
    int count = 0;
    if(head->link == head)
    {
        printf("Polynomial does not exist\n");
        return;
    }
    cur = head->link;
    while(cur != head && count >= 0)
    {
        if(cur->cf > 0)
            printf("+");
        printf("%dx^%d", cur->cf, cur->px);
        count++;
        cur = cur->link;
    }
}

NODE insert_rear(int cf, int px, NODE head)
{
    NODE temp, cur;

    temp = (NODE)malloc(sizeof(struct node));
    temp->cf=cf;
    temp->px=px;
    temp->link=temp;

    cur=head->link;
    while (cur->link != head)
    {
        cur = cur->link;
    }
    cur->link = temp;
    temp->link = head;
    return head;
}

NODE readPoly(NODE head)
{
    int n, i , cf, px;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        printf("Enter the coefficient: ");
        scanf("%d", &cf);
        printf("Enter the power: ");
        scanf("%d", &px);
        head = insert_rear(cf,px,head);
    }
    return head; // Added return statement
}

int compare(int a, int b)
{
    if(a>b)
    {
        return 1;
    }
    else if(a==b)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

NODE addPoly(NODE h1, NODE h2, NODE h3)
{
    NODE p1, p2;
    p1 = h1->link;
    p2 = h2->link;

    int sumcf;

    while(p1 != NULL && p2 != NULL)
    {
        switch (compare(p1->px, p2->px))
        {
            case 0: sumcf = p1->cf + p2->cf;
                    if(sumcf != 0)
                    {
                        h3=insert_rear(sumcf,p1->px,h3);
                    }
                    p1=p1->link;
                    p2=p2->link;
                    break;
            case 1:h3=insert_rear(p1->cf,p1->px,h3);
                    p1=p1->link;
                    break;
            case -1:h3=insert_rear(p2->cf,p2->px,h3);
                    p2=p2->link;
                    break;
        }
    }
    while(p1 != NULL)
    {
        h3 = insert_rear(p1->cf,p1->px,h3);
        p1=p1->link;
    }
    while(p2 != NULL)
    {
        h3 = insert_rear(p2->cf,p2->px,h3);
        p2=p2->link;
    }
    return h3;
}

int main() // Changed return type to int
{
    NODE h1,h2,h3;
    h1 = (NODE)malloc(sizeof(struct node));
    h3 = (NODE)malloc(sizeof(struct node));
    h2 = (NODE)malloc(sizeof(struct node));

    h1->link = h1;
    h2->link = h2;
    h3->link = h3;

    printf("Enter the first polynomial\n");
    h1=readPoly(h1);

    printf("Enter the second polynomial\n");
    h2=readPoly(h2);

    h3 = addPoly(h1,h2,h3);

    printf("The first polynomial is: ");
    display(h1);

    printf("\nThe second polynomial is: ");
    display(h2);

    printf("\nThe sum is: ");
    display(h3);

    return 0; // Added return statement
}
