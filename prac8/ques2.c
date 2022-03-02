// Quick sort in C

#include <stdio.h>

// function to swap elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int leftmostIndex, int rightmostIndex)
{

    int pivot = array[rightmostIndex]; // rightmost element as pivot
    int i = (leftmostIndex - 1);       // index for the leftmost largest element

    int j;
    for (j = leftmostIndex; j < rightmostIndex; j++)
    {
        if (array[j] <= pivot)
        {
            swap(&array[++i], &array[j]); // swap elements low with high
        }
    }
    swap(&array[i + 1], &array[rightmostIndex]); // swap pivot with leftmost largest number
    return (i + 1);
}

void quickSort(int array[], int leftmostIndex, int rightmostIndex)
{
    if (leftmostIndex < rightmostIndex)
    {
        int pivotIndex = partition(array, leftmostIndex, rightmostIndex); // to get pivot index
        quickSort(array, leftmostIndex, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, rightmostIndex);
    }
}

// function to print array elements
void printArray(int array[], int size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

int main()
{
    int count;
    printf("Enter number of elements you want in the array: ");
    scanf("%d", &count);
    int arr[count];
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;
    printf("\nEnter the elements : ");
    for (i = 0; i < count; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted Array\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array in ascending order: \n");
    printArray(arr, n);
}