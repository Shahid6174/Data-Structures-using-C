#include <stdio.h>

int main()
{
    int n, a[10][10], p[10][10], i, j, k;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix: \n");
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
            p[i][j] = a[i][j];
        }
    }
    printf("The final path matrix is: \n");
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(p[i][j]==0)
                {
                    if(p[i][k]==1 && p[k][j]==1)
                    {
                        p[i][j] = 1;
                    }
                }
            }
        }
    }

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    
} 