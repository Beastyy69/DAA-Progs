#include <stdio.h>

// Merge function - do sorted parts ko merge karta hai
void merge(int a[], int l, int mid, int r)
{
    int temp[100];             // Temporary array
    int i = l;                 // Left subarray ka starting index
    int j = mid + 1;           // Right subarray ka starting index
    int k = l;                 // Temp array ka index

    // Dono subarrays compare karke chhota element temp me store karo
    while(i <= mid && j <= r)
    {
        if(a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    // Left subarray ke bache hue elements copy karo
    while(i <= mid)
        temp[k++] = a[i++];

    // Right subarray ke bache hue elements copy karo
    while(j <= r)
        temp[k++] = a[j++];

    // Temp array ko original array me copy karo
    for(i = l; i <= r; i++)
        a[i] = temp[i];
}

// Recursive Merge Sort function
void mergeSort(int a[], int l, int r)
{
    // Agar sirf ek element nahi hai tabhi divide karo
    if(l < r)
    {
        int mid = (l + r) / 2;     // Middle index nikalo

        mergeSort(a, l, mid);      // Left half sort karo

        mergeSort(a, mid + 1, r);  // Right half sort karo

        merge(a, l, mid, r);       // Dono sorted halves ko merge karo
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[100];

    printf("Enter elements:\n");

    // Array input
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Merge Sort call
    mergeSort(a, 0, n - 1);

    printf("Sorted Array:\n");

    // Sorted array print
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
