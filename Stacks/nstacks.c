#include <stdio.h>
#define stacksize 100
#define maxstacks 10 
int s[stacksize];
int n;
int top[maxstacks];
int boundary[maxstacks];

void push(int i, int item)
{
    if(top[i] == boundary[i+1])
    {
        printf("Stack overflow");
        return;
    }
    top[i] += 1;
    s[top[i]] = item;

}

int pop(int i)
{
    int item;
    if(top[i] == boundary[i])
    {
        return -1;
    }
    item = s[top[i]];
    top[i] -= 1;
    return item;
}

void display(int i)
{
    int j;
    if(top[i] == boundary[i])
    {
        printf("Stack empty");
        return;
    }

    for(j=boundary[i]+1; j<= top[i]; j++)
    {
        printf("%d ", s[j]);
    }
}

int main()
{
    int choice, i, j, n, y, item;
    printf("Enter number of stacks: ");
    scanf("%d", &n);

    for(j=0; j<=n; j++)
    {
        top[j] = boundary[j] = stacksize/n*j - 1;
    }

    for(;;)
    {
        printf("Enter 1.Push 2.Pop 3.Display and 4.Exit: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter the stack number: ");
                    scanf("%d", &i);
                    printf("Enter element to insert: ");
                    scanf("%d", &item);
                    push(i, item);
                    break;
            case 2: printf("Enter the stack number: ");
                    scanf("%d", &i);
                    y = pop(i);
                    if(y==-1)
                    { 
                        printf("Stack underflow");
                        break;
                    }
                    printf("Item deleted %d", y);
                    break;
            case 3: printf("Enter the stack number: ");
                    scanf("%d", &i);
                    display(i);
                    break;
            default: return 0;
        }
    }
}