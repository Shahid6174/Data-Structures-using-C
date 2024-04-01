//For infinite entry give any big number, i.e with n+1 digits...

#include <stdio.h>

int min(int a, int b)
{
    if(a<b)
    {
        return a;
    }
    return b;
}

int main()
{
    int n, a[10][10], d[10][10], i, j, k;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the weighted adjacency matrix: \n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            d[i][j] = a[i][j];
        }
    }
    printf("The final path matrix is: \n");
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    
} 