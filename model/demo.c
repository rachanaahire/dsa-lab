// Quick sort in C

#include <stdio.h>

// struct array to store the PIVOT VALUES
struct pArray
{
    int arr[2];
};

// function to swap elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// function to print array elements
void printArray(int array[], int f, int size)
{
    int i;
    for (i = f; i < size; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

struct pArray partition(int array[], int leftmostIndex, int rightmostIndex)
{
    struct pArray y;
    int pivot = array[rightmostIndex]; // rightmost element as pivot
    int i = -1;                        // index for the leftmost largest element
    int low = 0;
    int high = rightmostIndex;

    while (low < high)
    {
        if (array[low] < pivot)
        {
            low++;
        }
        else if (array[low] > pivot)
        {
            high--;
            swap(&array[high], &array[low]);
        }
        else
        {
            i++;
            swap(&array[i], &array[low]);
            if (array[i] == pivot)
            {
                low++;
            }
        }
    }
    printf("\nBefore : ");
    printArray(array, leftmostIndex, rightmostIndex + 1);
    low--;
    swap(&array[rightmostIndex], &array[high++]);
    if (i != -1)
    {
        int a;
        for (a = 0; a <= i; a++)
        {
            swap(&array[a], &array[low]);
            low--;
        }
    }
    printf("\nAfter : ");
    printArray(array, leftmostIndex, rightmostIndex + 1);
    printf("\nPivot value : %d\n", pivot);
    y.arr[0] = low;
    y.arr[1] = high;
    return y;
}

void quickSort(int array[], int leftmostIndex, int rightmostIndex)
{
    if (leftmostIndex < rightmostIndex)
    {
        struct pArray x = partition(array, leftmostIndex, rightmostIndex); // to get pivot index
        printf("Index Left to Pivot : %d \nIndex Right to Pivot : %d", x.arr[0], x.arr[1]);
        printf("\n=======================================\n");
        quickSort(array, leftmostIndex, x.arr[0]);
        quickSort(array, x.arr[1], rightmostIndex);
    }
}

int main()
{
    int count;
    int arr[] = {5, 7, 4, 1, 5, 6, 4, 8, 5, 0, 5}; //{7, 4, 5, 1, 9, 5};
    // printf("Enter number of elements you want in the array: ");
    // scanf("%d", &count);
    // int arr[count];
    int n = sizeof(arr) / sizeof(arr[0]);
    // int i;
    // printf("\nEnter the elements : ");
    // for (i = 0; i < count; i++)
    // {
    //     scanf("%d", &arr[i]);
    // }

    printf("\nUnsorted Array : ");
    printArray(arr, 0, n);
    printf("\n=======================================\n");

    quickSort(arr, 0, n - 1);

    printf("\nSorted array in ascending order: ");
    printArray(arr, 0, n);
}

// {5, 7, 4, 1, 5, 6, 4, 8, 5, 0, 5}

// {7, 4, 5, 1, 9, 5}