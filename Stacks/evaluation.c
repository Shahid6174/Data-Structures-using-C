#include<stdio.h>
#include<string.h>
#include<math.h>

#define stacksize 70

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

int evaluate(char postfix[])
{
    int i, res;
    int n = strlen(postfix);
    char symbol;
    int op1, op2;
    int top;
    top = -1;
    int s[stacksize];
    for(i=0;i<n;i++)
    {
        symbol = postfix[i];
        switch (symbol)
        {
            case '+': op2 = pop(&top,s);
                      op1 = pop(&top,s);
                      res = op1 + op2;
                      push(&top, res, s);
                      break;

            case '-': op2 = pop(&top,s);
                      op1 = pop(&top,s);
                      res = op1 - op2;
                      push(&top, res, s);
                      break;

            case '*': op2 = pop(&top,s);
                      op1 = pop(&top,s);
                      res = op1 * op2;
                      push(&top, res, s);
                      break;

            case '/': op2 = pop(&top,s);
                      op1 = pop(&top,s);
                      res = op1 / op2;
                      push(&top, res, s);
                      break;

            case '%': op2 = pop(&top,s);
                      op1 = pop(&top,s);
                      res = op1 % op2;
                      push(&top, res, s);
                      break;

            case '^':
            case '$': op2 = pop(&top,s);
                      op1 = pop(&top,s);
                      res = (int)pow((double)op1,(double)op2);
                      push(&top, res, s);
                      break;
            default: push(&top, symbol - '0', s);
        }
    }
    return(pop(&top,s));
}

int main()
{
    int res;
    char postfix[70];

    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    res  = evaluate(postfix);
    printf("The value of the postfix expression is: %d", res);
    return 0;
}
