#include <stdio.h>
#include <string.h>
#define stacksize 10
#define urlsize 40

void push(char item[], int *top, char s[][urlsize])
{   
    if(*top == stacksize-1)
    {
        printf("URLs overflow.\n");
        return;
    }
    *top = *top + 1;
    strcpy(s[*top], item);
}
void push_bckwrd(char y[], int *top1, char a[][urlsize])
{   
    if(*top1 == stacksize-1)
    {
        printf("URLs overflow.\n");
        return;
    }
    *top1 = *top1 + 1;
    strcpy(a[*top1], y);
}

const char *pop(int *top, char s[][urlsize])
{
    char *item;
    if(*top == -1)
    
    {
        return NULL;
    }
    item =  s[*top];
    *top = *top-1;
    return(item);
}

const char *pop_frwrd(int *top1, char a[][urlsize])
{
    char *item;
    if(*top1 == -1)
    {
        return NULL;
    }
    item =  a[*top1];
    *top1 = *top1-1;
    return(item);
}

void display(int top, char s[][urlsize])
{
    int i;
    if(top == -1)
    {
        printf("No URLs to go back.\n");
        return;
    }
    for(i=0;i<=top;i++)
    {
        printf("%s\n", s[i]);
    }
}

int main()
{
    int top=-1, choice;
    char *y;
    char *z;
    int top1 = -1;
    char a[stacksize][urlsize];
    char s[stacksize][urlsize], item[urlsize];

    for(;;)
    {
        printf("Enter 1.Typing_Url  2.Forward(=>)   3.Backward(<=)  4.Display Current URLS  5.Exit: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: printf("Enter URL: ");
                    scanf("%s", item);
                    push(item, &top, s);
                    break;
            case 2: z = pop_frwrd(&top1, a);
                    if(z == NULL)
                    {
                        printf("No URLs to go forward \n");
                    }
                    else
                    {
                        push(z,&top,s);
                        printf("Going forward to %s\n", z);
                    }
                    break;
            case 3: y = pop(&top, s);
                    if(y == NULL)
                    {
                        printf("No URLS to go back\n");
                    }
                    else
                    {
                        push_bckwrd(y,&top1,a);
                        printf("Leaving %s\n", y);
                    }
                    break;
            case 4: display(top, s);
                    break;
            default: return 0;
        }
    }
    return 0;
}