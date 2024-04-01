#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define stacksize 50

struct node
{
    int info;
    struct node* llink;
    struct node* rlink;
};

typedef struct node* NODE;

void push(NODE item, int* top, NODE s[])
{
    if(*top == stacksize-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    *top += 1;
    s[*top] = item;
}

NODE pop(int *top, NODE s[])
{
    NODE item;
    if(*top==-1)
    {
        return NULL;
    }
    item = s[*top];
    *top -= 1;
    return(item);
}

NODE create_exp_tree(char postfix[])
{
    NODE s[stacksize], temp;
    int i, n, top = -1;
    char symbol;
    n = strlen(postfix);

    for(i=0;i<n;i++)
    {
        symbol = postfix[i];

        switch (symbol)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
        case '$':   temp = (NODE)malloc(sizeof(struct node));
                    temp->info = symbol;
                    temp->rlink = pop(&top, s);
                    temp->llink = pop(&top, s);
                    push(temp, &top, s);
                    break;
        default:    temp = (NODE)malloc(sizeof(struct node));
                    temp->info = symbol-'0';
                    temp->rlink = NULL;
                    temp->llink = NULL;
                    push(temp, &top, s);
                    break;
        }
    }
    return (pop(&top,s));
}

int evaluate(NODE root)
{
    if(root->llink==NULL && root->rlink==NULL)
    {
        return root->info;
    }
    if(root->info == '+')
    {
        return(evaluate(root->llink) + evaluate(root->rlink));
    }
    if(root->info == '-')
    {
        return(evaluate(root->llink) - evaluate(root->rlink));
    }
    if(root->info == '/')
    {
        return(evaluate(root->llink) / evaluate(root->rlink));
    }
    if(root->info == '*')
    {
        return(evaluate(root->llink) * evaluate(root->rlink));
    }
    if(root->info == '^' || root->info=='$')
    {
        return((int)pow((double)evaluate(root->llink),(double)evaluate(root->rlink)));
    }
    if(root->info == '%')
    {
        return(evaluate(root->llink) % evaluate(root->rlink));
    }
}

int main()
{
    int res;
    NODE root = NULL;
    char postfix[60];

    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    root = create_exp_tree(postfix);
    res = evaluate(root);

    printf("The value of the expression is: %d\n", res);
}