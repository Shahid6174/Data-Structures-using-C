#include <stdio.h>
int fibo(int n)
{
    if (n==1)
        return 0;
    if (n==2)
        return 1;
    return fibo(n-1) + fibo(n-2);
}
int main()
{
    int m, n;
    printf("Enter number: \n");
    scanf("%d", &n);
    int res = fibo(n);
    printf("%d", res); 
}
