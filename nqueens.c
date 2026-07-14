#include<stdio.h>

int x[20], n;

// Check if queen can be placed
int place(int k, int i)
{
    for(int j=1;j<k;j++)
    {
        if(x[j]==i || abs(x[j]-i)==abs(j-k)) // Same column or diagonal
            return 0;
    }
    return 1;
}

// Print solution
void print()
{
    for(int i=1;i<=n;i++)
        printf("%d ",x[i]);

    printf("\n");
}

// Recursive function
void queen(int k)
{
    for(int i=1;i<=n;i++)
    {
        if(place(k,i)) // Check if queen can be placed
        {
            x[k]=i;

            if(k==n) // All queens placed, print solution
                print();
            else
                queen(k+1);
        }
    }
}

int main()
{
    printf("Enter number of queens: ");
    scanf("%d",&n);

    queen(1);

    return 0;
}