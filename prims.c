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

            if(graph[i][j]==0) // Agar edge exist nahi karta hai to INF assign karo
                graph[i][j]=INF;
        }
    }

    int visited[20]={0};

    visited[0]=1;      // Start from vertex 0

    int edge=0;
    int cost=0;

    printf("Edges in MST:\n");

    while(edge<n-1) // Jab tak edge n-1 na ho jaye
    {
        int min=INF;
        int a=0,b=0;

        for(int i=0;i<n;i++)
        {
            if(visited[i]) //Agar Nahi Visited Ho Toh Nahi Jayega
            {
                for(int j=0;j<n;j++)
                {
                    if(!visited[j] && graph[i][j]<min) // Agar visited nahi hai aur edge ka weight minimum hai to update karo
                    {
                        min=graph[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }

        printf("%d -- %d = %d\n",a+1,b,min);

        cost+=min;
        visited[b]=1;
        edge++;
    }

    printf("Minimum Cost = %d\n",cost);

    return 0;
}