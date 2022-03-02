#include <stdio.h>

struct Account
{

    char name[20];

    int acc_num;

    float bal_amt;
};

void setdetails(struct Account user[10], int m)

{

    printf("ENTER DETAILS OF %d PEOPLE \n", m);

    for (int i = 0; i < m; i++)

    {

        printf("%d) ENTER THE NAME OF THE ACCOUNT HOLDER :", i);

        scanf("%s", &user[i].name);
        printf("\n");

        printf("%d) ENTER THE ACCOUNT NUMBER :", i);

        scanf("%d", &user[i].acc_num);
        printf("\n");

        printf("%d) ENTER THE BALANCE :", i);

        scanf("%f", &user[i].bal_amt);

        printf("\n");
    }
}

void getdetails(struct Account user[10], int m)

{
    for (int i = 0; i < m; i++)

    {

        printf("DETAILS OF PERSON %d  : \n", i + 1);

        printf("ACCOUNT HOLDER : %s \n", user[i].name);

        printf("ACCOUNT NUMBER : %d \n", user[i].acc_num);

        printf("BALANCE : %f \n", user[i].bal_amt);
    }
}

void depositmoney(struct Account user[10], int deposit)

{
    int userNum;
    printf("Enter user number: ");
    scanf("%d", &userNum);

    user[userNum].bal_amt = user[userNum].bal_amt + deposit;

    printf("MONEY DEPOSITED \n ");

    printf("YOUR Updated BALANCE IS %f \n", user[userNum].bal_amt);
}

void withdrawmoney(struct Account user[10], int withdraw)

{
    int userNum;
    printf("Enter user number: ");
    scanf("%d", &userNum);

    user[userNum].bal_amt = user[userNum].bal_amt - withdraw;

    printf("MONEY Withdrawn \n");

    printf("YOUR Updated BALANCE IS %f \n", user[userNum].bal_amt);
}

int main()

{
    int j;
    int x;
    int dep;
    int wid;

    printf("Number of accounts : ");

    scanf("%d", &j);

    //struct Account k[j];
    struct Account user[10];
    setdetails(user, j);

    printf("\nType '1' to get all records\n");
    printf("\nType '2' to deposit money\n");
    printf("\nType '3' to withdraw money\n");
    printf("\nType '0' to get all records\n");

    scanf("%d", &x);
    switch (x)
    {
    case 1:
        /* code */ //get
        getdetails(user, j);
        break;
    case 2:
        /* code */ //deposit
        printf("Enter money to deposit: ");
        scanf("%d", &dep);
        depositmoney(user, dep);
        break;
    case 3:
        /* code */ //withdraw
        printf("Enter money to withdraw: ");
        scanf("%d", &wid);
        withdrawmoney(user, wid);
        break;

    default:
        break;
    }

    //getdetails(k, j);

    return 0;
}