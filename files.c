#include <stdio.h>

int main()
{
    freopen("graph.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    int graph[20][20];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
return 0;
}
