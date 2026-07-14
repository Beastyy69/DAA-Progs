#include<stdio.h>

#define INF 9999

int main()
{
    freopen("graph.txt","r",stdin);

    int n;
    scanf("%d",&n);

    int graph[20][20];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);

            if(graph[i][j]==0 && i!=j)
                graph[i][j]=INF;
        }
    }

    int dist[20];

    // Source = 0
    for(int i=0;i<n;i++)
        dist[i]=INF;

    dist[0]=0;

    // Relax edges n-1 times
    for(int k=1;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(graph[i][j]!=INF && dist[i]!=INF) // Agar edge exist karta hai aur source se i tak ka distance INF nahi hai
                {
                    if(dist[i]+graph[i][j] < dist[j]) // Agar source se j tak ka distance i ke through kam hai to update karo
                    {
                        dist[j]=dist[i]+graph[i][j];
                    }
                }
            }
        }
    }

    printf("Shortest Distance from Vertex 0:\n");

    for(int i=0;i<n;i++)
        printf("0 -> %d = %d\n",i,dist[i]);

    return 0;
}