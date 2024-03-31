#include <stdio.h>

int gcd(int m, int n)
{
    if(m==n)
        return m;
    if(m>n)
        return gcd(m-n,n);
    if(m<n)
        return gcd(m,n-m);
}

int main()
{
    int m, n, res;
    printf("Enter two elements: ");
    scanf("%d %d", &m, &n);
    res = gcd(m,n);
    printf("%d", res);
}