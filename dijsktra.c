#include<stdio.h>

#define INF 9999

int main()
{
    freopen("graph.txt","r",stdin);

    int n;
    scanf("%d",&n);

    int graph[20][20];

    // Read graph using 1-based indexing
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&graph[i][j]);

            if(graph[i][j]==0 && i!=j)
                graph[i][j]=INF;
        }
    }

    int dist[20], visited[20];

    // Initialize
    for(int i=1;i<=n;i++)
    {
        dist[i]=graph[1][i];   // Source = Vertex 1
        visited[i]=0;
    }

    dist[1]=0;
    visited[1]=1;

    for(int count=1;count<n;count++) // Repeat n-1 times
    {
        int min=INF, u=-1;

        // Find minimum distance vertex
        for(int i=1;i<=n;i++)
        {
            if(!visited[i] && dist[i]<min) // Agar visited nahi hai aur distance minimum hai to update karo 
            {
                min=dist[i];
                u=i;
            }
        }

        visited[u]=1;

        // Update distances
        for(int v=1;v<=n;v++)
        {
            if(visited[v]==0 && dist[u]+graph[u][v] < dist[v]) //source se v tak ka distance update karna hai with u as intermediate
            {
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }

    printf("Shortest Distance from Vertex 1:\n");

    for(int i=1;i<=n;i++) // Print distances from source vertex 1
    {
        printf("1 -> %d = %d\n",i,dist[i]);
    }

    return 0;
}