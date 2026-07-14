#include<stdio.h>

struct Job
{
    char id;
    int deadline;
    int profit;
};

int main()
{
    struct Job j[10], temp;
    int n, slot[10] = {0};
    char ans[10];

    printf("Enter number of jobs: ");
    scanf("%d",&n);

    // Input
    for(int i=0;i<n;i++)
    {
        printf("Enter Job Deadline Profit: ");
        scanf(" %c%d%d",&j[i].id,&j[i].deadline,&j[i].profit);
    }

    // Sort by Profit
    for(int i=0;i<n-1;i++)
    {
        for(int k=i+1;k<n;k++)
        {
            if(j[i].profit < j[k].profit)
            {
                temp=j[i];
                j[i]=j[k];
                j[k]=temp;
            }
        }
    }

    int total=0;

    // Job Sequencing
    for(int i=0;i<n;i++)
    {
        for(int d=j[i].deadline-1; d>=0; d--)
        {
            if(slot[d]==0)
            {
                slot[d]=1;
                ans[d]=j[i].id;
                total+=j[i].profit;
                break;
            }
        }
    }

    printf("\nSelected Jobs: ");

    for(int i=0;i<n;i++)
    {
        if(slot[i]==1)
            printf("%c ",ans[i]);
    }

    printf("\nTotal Profit = %d",total);

    return 0;
}