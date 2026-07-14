#include<stdio.h>

int graph[10][10];
int visited[10];
int queue[20];
int front = 0, rear = 0;
int n;

void BFS(int start)
{
    visited[start] = 1;
    queue[rear++] = start;

    while(front < rear)
    {
        int v = queue[front++];
        printf("%d ", v);

        for(int i = 0; i < n; i++)
        {
            if(graph[v][i] == 1 && visited[i] == 0) // Agar edge exist karta hai aur visited nahi hai to queue me add karo
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}
void DFS(int start)
{
    visited[start] = 1;
    printf("%d ", start);

    for(int i = 0; i < n; i++)
    {
        if(graph[start][i] == 1 && visited[i]!=1) // Agar edge exist karta hai aur visited nahi hai to recursive call karo
        {
            DFS(i);
        }
    }
}
int main()
{
        

    printf("BFS Traversal: ");
    BFS(3);

    printf("\nDFS Traversal: ");
    for(int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    DFS(3);

    return 0;
}