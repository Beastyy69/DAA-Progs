#include <stdio.h>

int a[20], max, min;

void maxmin(int l, int h)
{
    int mid, max1, min1;

    if(l == h)                 // One element
        max = min = a[l];

    else if(l + 1 == h)        // Two elements
    {
        if(a[l] > a[h])
            max = a[l], min = a[h];
        else
            max = a[h], min = a[l];
    }

    else
    {
        mid = (l + h) / 2;     // Divide array

        maxmin(l, mid);        // Left half
        max1 = max;
        min1 = min;

        maxmin(mid + 1, h);    // Right half

        if(max1 > max)         // Compare maximum
            max = max1;

        if(min1 < min)         // Compare minimum
            min = min1;
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)   // Input array
        scanf("%d", &a[i]);

    maxmin(0, n - 1);            // Function call

    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);

    return 0;
}
