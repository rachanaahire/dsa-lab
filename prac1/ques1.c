#include <stdio.h>
#include <conio.h>
int main()
{
    // defined variables
    char name[25];
    int age;
    unsigned long leapSeconds = 0;
    unsigned long seconds= 0;
    unsigned long sec = 0;
    int leap = 0;

    // assigning values by taking input from user
    printf("What is your name? ");
    scanf("%[^\n]*c", name);
    printf("Hello %s !!! What is your age? ", name);
    scanf("%d", &age);

    //to calculate leap years
    for (int i = 0; i <= age; i++)
    {
        if (i % 4 == 0)
        {
            leapSeconds += 366*24*60*60;
        } else {
            seconds += 365*24*60*60;
        }
    }
    sec = leapSeconds +seconds;

    printf("\n Your name is %s \n", name);
    printf("Your age is %d \n", age);
    printf("You lived for %lu seconds", sec);

    return 0;
}