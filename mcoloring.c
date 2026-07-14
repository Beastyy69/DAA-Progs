#include<stdio.h>

int graph[20][20];
int color[20];
int n, m;

// Check if color can be assigned
int safe(int v, int c)
{
    for(int i=0;i<n;i++)
    {
        if(graph[v][i] && color[i]==c)
            return 0;
    }
    return 1;
}

// Recursive function
void mColoring(int v)
{
    if(v==n)
    {
        printf("Solution: ");
        for(int i=0;i<n;i++)
            printf("%d ",color[i]);
        printf("\n");
        return;
    }

    for(int c=1;c<=m;c++)
    {
        if(safe(v,c))
        {
            color[v]=c;
            mColoring(v+1);
            color[v]=0;
        }
    }
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
    }

    printf("Enter number of colors: ");
    scanf("%d",&m);

    mColoring(0);

    return 0;
}