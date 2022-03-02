#include <stdio.h>

void main()
{
    int sum= 0;
    for (int num = 1; num <= 100; num++){
        if (num % 7 == 0){
            printf("\n %d", num);
            sum += num;
        }
    }
    printf("\nsum of above integers = %d", sum);
}