#include<stdio.h>

#define INF 999

int main()
{
    freopen("graph.txt","r",stdin);   // graph.txt se input lo

    int n;
    scanf("%d",&n);                   // Number of vertices

    int dist[20][20];

    // Adjacency matrix input
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&dist[i][j]);
        }
    }

    // Floyd-Warshall Algorithm
    for(int k=0;k<n;k++)              // Intermediate vertex
    {
        for(int i=0;i<n;i++)          // Source vertex
        {
            for(int j=0;j<n;j++)      // Destination vertex
            {
                // Agar k ke through distance chhota hai to update karo
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("Shortest Distance Matrix:\n");

    // Final shortest distance matrix print
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%4d ",dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
