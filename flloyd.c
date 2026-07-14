#include<stdio.h>

#define INF 999

int main()
{
    freopen("graph.txt","r",stdin);

    int n;
    scanf("%d",&n);

    int dist[20][20];

    // Read adjacency matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&dist[i][j]);
        }
    }

    // Floyd Warshall
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][k]+dist[k][j] < dist[i][j]) // Agar i se j tak ka distance k ke through kam hai to update karo
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }

    printf("Shortest Distance Matrix:\n");

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