//Will work only for graphs with no self loops

#include <stdio.h>

void bfs(int n, int a[20][20], int source, int visited[20], int e[20][2])
{
    int f=0, r=-1, q[20];
    int u, v, k = 1;
    visited[source] = 1;
    r += 1;
    q[r] = source;
    while(f<=r)
    {
        u = q[f];
        f = f+1;
        for(v=1; v<=n; v++)
        {
            if(a[u][v]==1 && visited[v]==0)
            {
                visited[v] = 1;
                r += 1;
                q[r] = v;
                e[k][1] = u;
                e[k][2] = v;
                k = k+1;
            }
        }     
    }

}

void dfs(int n, int a[20][20], int u, int visited[20], int e[20][2])
{
    int v;
    static int k = 1;
    visited[u] = 1;
    for(v=1; v<=n; v++)
    {
        if(a[u][v] == 1 && visited[v] == 0)
        {
            e[k][1] = u;
            e[k][2] = v;
            k = k+1;
            dfs(n,a,v,visited,e);
        }
    }
}

int main()
{
    int i, j, n, visited[20], a[20][20], source, flag=0, choice, e[20][2];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix: \n");
    for(i = 1; i<=n; i++)
    {
        for(j = 1; j<=n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the source node: ");
    scanf("%d", &source);
    for(i=1; i<=n; i++)
    {
        visited[i] = 0;
    }

    printf("Enter 1.BFS 2.DFS: ");
    scanf("%d", &choice);
    if(choice == 1)
        bfs(n, a, source, visited, e);
    else
        dfs(n, a, source, visited,e);
    
    for(i=1; i<=n; i++)
    {
        if(visited[i] == 0)
        {
            flag = 1;
            printf("%d is not reachable.\n",i);
        }
        else
            printf("%d is reachable.\n", i);
    }
    if(flag == 1)
    {
        printf("Graph is not connected.\n");
    }
    else
    {
        printf("It is a connected graph.\n");
        printf("The Spanning tree is: \n");
        for(i = 1; i<=n-1; i++)
            printf("%d to %d\n",e[i][1],e[i][2]);
    }
    return 0 ;
}