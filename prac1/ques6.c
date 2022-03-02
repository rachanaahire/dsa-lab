#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NUMBER_OF_COLLEGES 4
#define NUMBER_OF_DEPARTMENTS 6
#define MAX_STRING_SIZE 10
char college[NUMBER_OF_COLLEGES][MAX_STRING_SIZE] = {"IISC", "NIT", "IIT", "MIT"};
char dept[NUMBER_OF_DEPARTMENTS][MAX_STRING_SIZE] = {"IT", "Biotech", "Physics", "Maths", "Chemistry", "Statistics"};
int clgIndex, deptIndex;
char preClg1[12], preClg2[12], preClg3[12], preDept1[12], preDept2[12], preDept3[12];
int vancant_seats;
int seat_matrix[4][6] = {
    {10, 11, 12, 13, 18, 24},
    {0, 15, 16, 17, 13, 21},
    {0, 6, 4, 0, 1, 1},
    {12, 4, 11, 21, 33, 54}};

void printSeatMatrix()
{
    for (int i = 0; i < NUMBER_OF_COLLEGES; i++)
    {
        for (int j = 0; j < NUMBER_OF_DEPARTMENTS; j++)
        {
            printf("%d ", seat_matrix[i][j]);
            if (j == NUMBER_OF_COLLEGES + 1)
            {
                printf("\n");
            }
        }
    }
};

int getIndex(char *preference, bool val)
{
    int length = val ? NUMBER_OF_COLLEGES : NUMBER_OF_DEPARTMENTS;
    for (int i = 0; i < length; i++)
    {
        if (val && !strcmp(preference, college[i]))
        {
            clgIndex = i;
        }
        else if (!val && !strcmp(preference, dept[i]))
        {
            deptIndex = i;
        }
    }
}

void getVacancy(char *collegeName, char *deptName)
{
    getIndex(collegeName, true);
    getIndex(deptName, false);
    vancant_seats = seat_matrix[clgIndex][deptIndex];
}

int main()
{

    char name[25];
    bool isCollege;

    printf("What is your name? ");
    scanf("%[^\n]*c", name);
    printf("Hello %s !!! \n Please enter Details for your Preference below: \n College Choice: IISC/IIT/NIT/MIT \n Department Choices: IT/Biotech/Physics/Maths/Chemistry/Statistics \n Please only choose from the above choices \n  Input College Name (Prefernce1): ", name);
    scanf("%s", preClg1);
    printf("Input Department name (Preference 1): ");
    scanf("%s", preDept1);
    printf("\n Input College Name (Prefernce 2): ");
    scanf("%s", preClg2);
    printf("Input Department name (Preference 2): ");
    scanf("%s", preDept2);
    printf("\n Input College Name (Preference 3): ");
    scanf("%s*c", preClg3);
    printf("Input Department name (Preference 3): ");
    scanf("%s", preDept3);

    getVacancy(preClg1, preDept1);

    if (vancant_seats == 0)
    {
        printf("\nNo seat available in college %s for department %s (PREFERENCE 1)", preClg1, preDept1);
        getVacancy(preClg2, preDept2);
        if (vancant_seats == 0)
        {
            printf("\nNo seat available in college %s for department %s (PREFERENCE 2)", preClg2, preDept2);
            getVacancy(preClg3, preDept3);
            if (vancant_seats == 0)
            {
                printf("\nNo seat available in college %s for department %s (PREFERENCE 3)", preClg3, preDept3);
            }
            else
            {
                seat_matrix[clgIndex][deptIndex]--;
                printf("\nThere is/are %d vacant seats in college %s for department %s", vancant_seats, preClg3, preDept3);
                printf("\nSeat Succussfully Alloted for Preference 3");
                printf("\nSeat Matrix : \n");
                printSeatMatrix();
            }
        }
        else
        {
            seat_matrix[clgIndex][deptIndex]--;
            printf("\nThere is/are %d vacant seats in college %s for department %s", vancant_seats, preClg2, preDept2);
            printf("\nSeat Succussfully Alloted for Preference 2");
            printf("\nSeat Matrix : \n");
            printSeatMatrix();
        }
    }
    else
    {
        seat_matrix[clgIndex][deptIndex]--;
        printf("There is/are %d vacant seats in college %s for department %s", vancant_seats, preClg1, preDept1);
        printf("\nSeat Succussfully Alloted for Preference 1");
        //printf("Two Dimensional array elements:\n");
        printSeatMatrix();
    }

    return 0;
}
