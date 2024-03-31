#include <stdio.h>
int acker(int m, int n)
{
    if (m==0)
        return n+1;
    if (n==0)
        return acker(m-1,1);
    return acker(m-1, acker(m,n-1));
}
int main()
{
    int m, n;
    printf("Enter two elements: \n");
    scanf("%d %d", &m, &n);
    int res = acker(m,n);
    printf("%d", res); 
}
