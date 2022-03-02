// Merge sort

#include <stdio.h>

void merge(int arr[], int p, int q, int r)
{

    int i, j, k;
    int part1 = q - p + 1;
    int part2 = r - q;

    int L[part1], M[part2];

    for (i = 0; i < part1; i++)
        L[i] = arr[p + i];
    for (j = 0; j < part2; j++)
        M[j] = arr[q + 1 + j];

    i = 0;
    j = 0;
    k = p;

    while (i < part1 && j < part2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < part1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < part2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int count;
    printf("Enter number of elements you want in the array: ");
    scanf("%d", &count);
    int arr[count];
    int size = sizeof(arr) / sizeof(arr[0]);
    int i;
    printf("\nEnter the elements : ");
    for (i = 0; i < count; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("Unsorted array: \n"); // before merge sorting
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    printf("Sorted array: \n"); // after merge sorting
    printArray(arr, size);
}