#include <stdio.h>

typedef struct
{
    int weight, value;
    float ratio;
}Item;

int main()
{
    Item item[10], temp;
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter Weight and Value: ");
        scanf("%d%d", &item[i].weight, &item[i].value);

        item[i].ratio = (float)item[i].value / item[i].weight;
    }

    printf("Enter Capacity: ");
    scanf("%d", &capacity);

    // Sort according to ratio
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(item[i].ratio < item[j].ratio)
            {
                temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    float profit = 0;

    for(int i = 0; i < n; i++)
    {
        if(capacity >= item[i].weight)
        {
            profit += item[i].value;
            capacity -= item[i].weight;
        }
        else
        {
            profit += item[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum Profit = %.2f", profit);

    return 0;
}