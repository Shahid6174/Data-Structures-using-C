#include<stdio.h>
#include<string.h>
#define stacksize 70

int input_precedence(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 3;
        case '^':
        case '$': return 6;
        case '(': return 9;
        case ')': return 0;
        default: return 7;
    }
}
int stack_precedence(char symbol)
{
    switch (symbol)
    {
        case '+':
        case '-': return 2;
        case '*':
        case '/':
        case '%': return 4;
        case '^':
        case '$': return 5;
        case '(': return 0;
        case '#': return-1;
        default : return 8;
    }
}

void push(int *top, int item, int s[])
{
    if(*top == stacksize - 1)
    {
        printf("Stack overflow");
        return;
    }
    *top += 1;
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
    *top -= 1;
    return item;
}
int resolve_infix(char infix[], char postfix[])
{
    int i, j = 0;
    int s[stacksize];
    char symbol;
    int top = -1;
    push(&top, '#', s);
    int n = strlen(infix);
    for(i=0;i<n;i++)
    {
        symbol = infix[i];
        while(stack_precedence(s[top])>input_precedence(symbol))
        {
            postfix[j] = pop(&top, s);
            j += 1;
        }
        if(stack_precedence(s[top]) != input_precedence(symbol))
        {
            push(&top, symbol, s);
        }
        else
        {
            pop(&top, s);
        }
    }
    while(s[top] != '#')
    {
       postfix[j] = pop(&top, s);
       j += 1;
    }
    postfix[j] = '\0';
}
int main()
{
    char infix[50], postfix[50];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    resolve_infix(infix, postfix);
    printf("The postfix expression is: %s", postfix);
    return 0;
}