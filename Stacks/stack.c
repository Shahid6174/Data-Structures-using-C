#include <stdio.h>
#define stacksize 6

int push(int item, int *top, int s[])
{   
    if(*top == stacksize-1)
    {
        printf("Stack overflow.\n");
        return 0;
    }
    *top = *top + 1;
    s[*top] = item;
}

int pop(int *top, int s[])
{
    int item;
    if(*top == -1)
    {
        return -1;
    }
    item = s[*top];
    *top = *top-1;
    return(item);
}

void display(int top,int s[stacksize])
{
    int i;
    if(top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }
    for(i=0;i<=top;i++)
    {
        printf("%d\n", s[i]);
    }
}

int main()
{
    int top=-1, item, choice, s[stacksize], y;


    for(;;)
    {
        printf("Enter 1.Push 2.Pop 3.Display 4.Exit: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: printf("Enter item: ");
                    scanf("%d", &item);
                    push(item, &top, s);
                    break;
            case 2: y = pop(&top, s);
                    if(y == -1)
                    {
                        printf("Stack underflow \n");
                    }
                    else
                    {
                        printf("Item deleted = %d\n", y);
                    }
                    break;
            case 3: display(top, s);
                    break;
            default: return 0;
        }
    }
    return 0;
}