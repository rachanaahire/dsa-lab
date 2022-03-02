#include <stdio.h>
#include <stdlib.h>

int arr[20] = {1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1}; //
int h = 0;
int c = 0;

int main()
{
    int i;
    for (i = 0; i < 20; i++)
    {
        if (arr[i] == 1)
        {
            c++;
        }
        else
        {
            if (h < c)
            {
                h = c;
            }
            c = 0;
        }
    }

    if (h < c)
    {
        h = c;
    }

    printf("Highest = %d", h);

    return 0;
}
