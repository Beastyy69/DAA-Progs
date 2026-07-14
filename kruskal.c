#include<stdio.h>

struct Edge
{
    int u,v,w;
} edge[100], temp;

int parent[20];

int find(int x)
{
    while(parent[x]!=x)
        x=parent[x];
    return x;
}

void uni(int a,int b)
{
    parent[a]=b;
}

int main()
{
    freopen("graph.txt","r",stdin);

    int n;
    scanf("%d",&n);

    int graph[20][20];
    int e=0;

    // Read adjacency matrix
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&graph[i][j]);

            // Take only upper triangle
            if(j>i && graph[i][j]!=0)
            {
                edge[e].u=i;
                edge[e].v=j;
                edge[e].w=graph[i][j];
                e++;
            }
        }
    }

    // Sort edges by weight
    for(int i=0;i<e-1;i++)
    {
        for(int j=0;j<e-i-1;j++)
        {
            if(edge[j].w > edge[j+1].w)
            {
                temp=edge[j];
                edge[j]=edge[j+1];
                edge[j+1]=temp;
            }
        }
    }

    // Initialize parent
    for(int i=1;i<=n;i++)
        parent[i]=i;

    int cost=0;

    printf("Edges in MST:\n");

    for(int i=0;i<e;i++)
    {
        int a=find(edge[i].u);
        int b=find(edge[i].v);

        if(a!=b)
        {
            printf("%d -- %d = %d\n",
                   edge[i].u,
                   edge[i].v,
                   edge[i].w);

            cost+=edge[i].w;
            uni(a,b);
        }
    }

    printf("Minimum Cost = %d\n",cost);

    return 0;
}