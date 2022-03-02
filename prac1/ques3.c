#include <stdio.h>

void main()
{
    int value, sum = 0, i = 0;
    printf("Enter the any number N < 100 = ");
    scanf("%d", &value);
    printf(" \n Every third Integer between 0 to %d are", value);
    while (i <= value)
    {
        printf("\n %d", i);
        if (i % 5 == 0)
        {
            sum = sum + i;
        }
        i = i + 3;
    }
    printf("\nsum of above integers that are evenly divisible by 5 = %d", sum);
}