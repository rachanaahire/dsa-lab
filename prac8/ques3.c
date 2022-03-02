// Radix Sort

#include <stdio.h>

int getMaximum(int array[], int n)
{
    int i;
    int max = array[0];
    for (i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

void countingSort(int array[], int size, int place)
{
    int i;
    int output[size + 1];
    int max = (array[0] / place) % 10;

    for (i = 1; i < size; i++)
    {
        if (((array[i] / place) % 10) > max)
            max = array[i];
    }
    int count[max + 1];

    for (i = 0; i < max; ++i)
        count[i] = 0;

    // Calculate count of elements
    for (i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;

    // Calculate cumulative count
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Place the elements in sorted order
    for (i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];
}

void radixsort(int array[], int size)
{
    int place;
    int max = getMaximum(array, size); // max element

    for (place = 1; max / place > 0; place *= 10)
        countingSort(array, size, place);
}

// Print an array
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

    radixsort(arr, n);

    printf("Sorted array (RADIX SORT): \n");
    printArray(arr, n);
}