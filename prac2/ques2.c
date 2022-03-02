#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

int ids[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
char *names[] = {"A", "B", "C", "D", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T"};
char *genders[] = {"F", "F", "M", "F", "M", "M", "M", "F", "M", "F", "M", "M", "F", "M", "M", "M", "M", "F", "M"};
int sem1marks[MAX][2] = {{5, 6}, {6, 9}, {4, 0}, {8, 8}, {7, 6}, {9, 10}, {10, 10}, {6, 10}, {4, 0}, {4, 8}, {7, 5}, {9, 10}, {5, 6}, {6, 9}, {4, 0}, {9, 8}, {7, 6}, {9, 10}, {7, 9}};
int sem2marks[MAX][2] = {{5, 4}, {6, 9}, {4, 0}, {9, 8}, {7, 6}, {9, 10}, {10, 9}, {6, 9}, {4, 7}, {4, 8}, {7, 5}, {9, 9}, {5, 6}, {6, 9}, {4, 0}, {7, 8}, {7, 6}, {9, 10}, {7, 9}};
int midscores[MAX] = {44, 43, 50, 50, 34, 34, 45, 12, 43, 33, 43, 43, 12, 32, 33, 38, 48, 29, 40};
int finalscores[MAX] = {44, 43, 50, 50, 34, 34, 45, 12, 43, 33, 43, 43, 12, 32, 33, 38, 48, 29, 40};
int totalscores[MAX];
char string[2];

struct semQuiz
{
	int quiz1;
	int quiz2;
};

struct Students
{
	int id;
	char *name;
	char *gender;
	struct semQuiz sem1Quiz;
	struct semQuiz sem2Quiz;
	int midscore;
	int finalscore;
	int totalscore;
};

void setData(struct Students stud[MAX])
{
	int i, j;
	for (i = 0; i < MAX; i++)
	{
		stud[i].id = ids[i];
		stud[i].name = names[i];
		stud[i].gender = genders[i];
		for (j = 0; j < 2; j++)
		{
			if (j == 0)
			{
				stud[i].sem1Quiz.quiz1 = sem1marks[i][j];
				stud[i].sem2Quiz.quiz1 = sem2marks[i][j];
			}
			else if (j == 1)
			{
				stud[i].sem1Quiz.quiz2 = sem1marks[i][j];
				stud[i].sem2Quiz.quiz2 = sem2marks[i][j];
			}
		};
		stud[i].midscore = midscores[i];
		stud[i].finalscore = finalscores[i];
		stud[i].totalscore = totalscores[i];
	}
}

void viewStudentInfo(struct Students stud[MAX])
{
	int i;
	printf("\nID\t");
	printf("NAME\t");
	printf("GENDER\t");
	printf("S1Q1\t");
	printf("S1Q2\t");
	printf("S2Q1\t");
	printf("S2Q2\t");
	printf("MS\t");
	printf("FS\t");
	printf("TS\t\t");
	// while (stud[i].id != 0)
	// {
	// 	printf("\n%d\t", stud[i].id);
	// 	(i == 19) ? printf("%s\t", &stud[i].name) : printf("%s\t", stud[i].name);
	// 	(i == 19) ? printf("%s\t", &stud[i].gender) : printf("%s\t", stud[i].gender);
	// 	//printf("%s\t", stud[i].gender);
	// 	printf("%d\t", stud[i].sem1Quiz.quiz1);
	// 	printf("%d\t", stud[i].sem1Quiz.quiz2);
	// 	printf("%d\t", stud[i].sem2Quiz.quiz1);
	// 	printf("%d\t", stud[i].sem2Quiz.quiz2);
	// 	printf("%d\t", stud[i].midscore);
	// 	printf("%d\t", stud[i].finalscore);
	// 	printf("%d", stud[i].totalscore);
	// 	i++;
	// }

	
	for (i = 0; i < MAX; i++)
	{
		printf("\n%d\t", stud[i].id);
		(i == 19) ? printf("%s\t", &stud[i].name) : printf("%s\t", stud[i].name);
		(i == 19) ? printf("%s\t", &stud[i].gender) : printf("%s\t", stud[i].gender);
		//printf("%s\t", stud[i].gender);
		printf("%d\t", stud[i].sem1Quiz.quiz1);
		printf("%d\t", stud[i].sem1Quiz.quiz2);
		printf("%d\t", stud[i].sem2Quiz.quiz1);
		printf("%d\t", stud[i].sem2Quiz.quiz2);
		printf("%d\t", stud[i].midscore);
		printf("%d\t", stud[i].finalscore);
		printf("%d", stud[i].totalscore);
	}
};

void addStudent(struct Students stud[MAX])
{
	/* int num,i;
	printf("\n How many students do you want to add ");
	scanf("%d",&num); */
	if (stud[19].id != 0)
	{
		printf("ONLY 20 STUDENTS IN ONE CLASS, THE CLASS IS FULL\n");
	}
	else
	{
		printf(" \n Enter the ID of the student: ");
		scanf("%d", &stud[19].id);
		printf(" \n Enter the name of the student: ");
		scanf("%s", &stud[19].name);
		printf("\n Enter the gender of the student: ");
		scanf("%s", &stud[19].gender);
		printf("\n Enter the SEM1 marks for quiz1 and quiz2: ");
		scanf("%d %d", &stud[19].sem1Quiz.quiz1, &stud[19].sem1Quiz.quiz2);
		printf("\n Enter the SEM2 marks for quiz1 and quiz 2: ");
		scanf("%d %d", &stud[19].sem2Quiz.quiz1, &stud[19].sem2Quiz.quiz2);
		printf("\n Enter the mid term score of the student: ");
		scanf("%d", &stud[19].midscore);
		printf("\n Enter the final score of the student: ");
		scanf("%d", &stud[19].finalscore);
		stud[19].totalscore = stud[19].midscore + stud[19].finalscore + stud[19].sem1Quiz.quiz1 + stud[19].sem1Quiz.quiz2 + stud[19].sem2Quiz.quiz1 + stud[19].sem2Quiz.quiz2;
		printf("Record Added Successfully !!!\n");
		int x;
		printf("Press 1 to view Student Info\n ");
		printf("Press 0 to exit\n ");
		scanf("%d", &x);
		if (x == 1)
		{
			viewStudentInfo(stud);
		}
	}
}

void deleteStudent(struct Students stud[MAX])
{
	int x, i;
	printf("\n Enter the id of the student whose record needs to be deleted ");
	scanf("%d", &x);
	for (i = 0; i < MAX; i++)
	{
		if (stud[i].id == x)
		{
			printf("\n%d %s", stud[i].id, stud[i].name);
			//--n;
			int j;
			for (j = i; j < MAX; j++)
			{
				stud[j].id = stud[j + 1].id;
				stud[j].name = stud[j + 1].name;
				stud[j].gender = stud[j + 1].gender;
				// strcpy(stud[j].name, stud[j + 1].name);
				// strcpy(stud[j].gender, stud[j + 1].gender);
				stud[j].sem1Quiz.quiz1 = stud[j + 1].sem1Quiz.quiz1;
				stud[j].sem1Quiz.quiz2 = stud[j + 1].sem1Quiz.quiz2;
				stud[j].sem2Quiz.quiz1 = stud[j + 1].sem2Quiz.quiz1;
				stud[j].sem2Quiz.quiz2 = stud[j + 1].sem2Quiz.quiz2;
				stud[j].midscore = stud[j + 1].midscore;
				stud[j].finalscore = stud[j + 1].finalscore;
				stud[j].totalscore = stud[j + 1].totalscore;
			}
			printf("\n Record deleted successfully ");
		}
	}
}

void updateStudent(struct Students stud[MAX])
{
	int x, z;
	printf("Enter the Student id to Update");
	scanf("%d", &x);

	do
	{
		int data, i;
		char *p;
		printf("\nType 1 to update ID");
		printf("\nType 2 to update name");
		printf("\nType 3 to update gender");
		printf("\nType 4 to update Sem1 quiz1 marks");
		printf("\nType 5 to update Sem1 quiz2 marks");
		printf("\nType 6 to update Sem2 quiz1 marks");
		printf("\nType 7 to update Sem2 quiz2 marks");
		printf("\nType 8 to update mid Score marks");
		printf("\nType 9 to update Final Score marks");
		printf("\nType 0 to exit\n");
		scanf("%d", &z);
		switch (z)
		{
		case 1:
			printf("\nEnter Updated ID :");
			scanf("%d", &data);
			for (i = 0; i < MAX; i++)
			{
				if (stud[i].id == x)
				{
					stud[i].id = data;
				}
			}
			break;
		case 2:
			printf("\nEnter Updated Name :");
			scanf("%s", &p);
			for (i = 0; i < MAX; i++)
			{
				if (stud[i].id == x)
				{
					stud[i].name = p;
				}
			}
			break;
		case 3:
			printf("\nEnter Updated Gender :");
			scanf("%s", &p);
			for (i = 0; i < MAX; i++)
			{
				if (stud[i].id == x)
				{
					stud[i].name = p;
				}
			}
			break;
		case 4:
			printf("\nEnter Updated Sem1 quiz1 marks :");
			scanf("%d", &data);
			for (i = 0; i < MAX; i++)
			{
				if (stud[i].id == x)
				{
					stud[i].id = data;
				}
			}
			break;
		case 5:
			printf("\nEnter Updated Sem1 quiz2 marks :");
			scanf("%d", &data);
			for (i = 0; i < MAX; i++)
			{
				if (stud[i].id == x)
				{
					stud[i].id = data;
				}
			}
			break;
		case 6:
			printf("\nEnter Updated Sem2 quiz1 marks :");
			scanf("%d", &data);
			for (i = 0; i < MAX; i++)
			{
				if (stud[i].id == x)
				{
					stud[i].id = data;
				}
			}
			break;
		case 7:
			printf("\nEnter Updated Sem2 quiz2 marks :");
			scanf("%d", &data);
			for (i = 0; i < MAX; i++)
			{
				if (stud[i].id == x)
				{
					stud[i].id = data;
				}
			}
			break;
		case 8:
			printf("\nEnter Updated mid score marks :");
			scanf("%d", &data);
			for (i = 0; i < MAX; i++)
			{
				if (stud[i].id == x)
				{
					stud[i].id = data;
				}
			}
			break;
		case 9:
			printf("\nEnter Updated final score marks :");
			scanf("%d", &data);
			for (i = 0; i < MAX; i++)
			{
				if (stud[i].id == x)
				{
					stud[i].id = data;
				}
			}
			break;

		default:
			break;
		}
	} while (z != 0);
}

void avg(struct Students stud[MAX])
{
	int x, i, sum;
	printf("\nType 1 to get Sem1 Quiz1 Average Score");
	printf("\nType 2 to get Sem1 Quiz2 Average Score");
	printf("\nType 3 to get Sem2 Quiz1 Average Score");
	printf("\nType 4 to get Sem1 Quiz1 Average Score");
	printf("\nType 5 to get Mid exam Average Score");
	printf("\nType 6 to get final exam Average Score");
	printf("\nType 0 to exit\n");
	scanf("%d", &x);

	switch (x)
	{
	case 1:
		/* code */
		for (i = 0; i < MAX; i++)
		{
			sum += stud[i].sem1Quiz.quiz1;
		}
		printf("The average Sem1 Quiz1 Score is : %d out of 10\n", sum / i);
		break;
	case 2:
		/* code */
		for (i = 0; i < MAX; i++)
		{
			sum += stud[i].sem1Quiz.quiz2;
		}
		printf("The average Sem1 Quiz2 Score is : %d out of 10\n", sum / i);
		break;
	case 3:
		/* code */
		for (i = 0; i < MAX; i++)
		{
			sum += stud[i].sem2Quiz.quiz1;
		}
		printf("The average Sem2 Quiz1 Score is : %d out of 10\n", sum / i);
		break;
	case 4:
		/* code */
		for (i = 0; i < MAX; i++)
		{
			sum += stud[i].sem2Quiz.quiz2;
		}
		printf("The average Sem2 Quiz2 Score is : %d out of 10\n", sum / i);
		break;
	case 5:
		/* code */
		for (i = 0; i < MAX; i++)
		{
			sum += stud[i].midscore;
		}
		printf("The average Mid Score is : %d out of 50\n", sum / i);
		break;
	case 6:
		/* code */
		for (i = 0; i < MAX; i++)
		{
			sum += stud[i].finalscore;
		}
		printf("The average Final Score is : %d out of 50\n", sum / i);
		break;

	default:
		break;
	}
}

void max()
{
	int i;
	int max = totalscores[0];
	for (i = 1; i < MAX; i++)
	{
		if (totalscores[i] > max)
		{
			max = totalscores[i];
		}
	}
	printf("MAXIMUM Student Total Score is %d\n", max);
}

void min()
{
	int i;
	int min = totalscores[0];
	for (i = 1; i < MAX - 1; i++)
	{
		if (totalscores[i] < min)
		{
			min = totalscores[i];
		}
	}
	printf("MINIMUM Student Total Score is %d\n", min);
}

void sort(struct Students stud[MAX], int s)
{
	int i, j;
	struct Students temp;

	for (i = 0; i < s - 1; i++)
	{
		for (j = 0; j < (s - 1 - i); j++)
		{
			if (stud[j].totalscore < stud[j + 1].totalscore)
			{
				temp = stud[j];
				stud[j] = stud[j + 1];
				stud[j + 1] = temp;
			}
		}
	}
	viewStudentInfo(stud);
}

void findStudentById(int iden, struct Students stud[MAX])
{
	printf("\nID: %d", stud[iden - 1].id);
	printf("\nNAME: %s", stud[iden - 1].name);
	printf("\nGENDER: %s", stud[iden - 1].gender);
	printf("\nSEM1 QUIZ1 MARKS: %d", stud[iden - 1].sem1Quiz.quiz1);
	printf("\nSEM1 QUIZ2 MARKS: %d", stud[iden - 1].sem1Quiz.quiz2);
	printf("\nSEM2 QUIZ1 MARKS: %d", stud[iden - 1].sem2Quiz.quiz1);
	printf("\nSEM2 QUIZ2 MARKS: %d", stud[iden - 1].sem2Quiz.quiz2);
	printf("\nMidterm Scores %d", stud[iden - 1].midscore);
	printf("\nFinal term Score %d", stud[iden - 1].finalscore);
	printf("\nTotal Score %d", stud[iden - 1].totalscore);
}

int main()
{
	int x, i, j;
	int iden;
	struct Students stud[MAX];

	for (i = 0; i < MAX; i++)
	{
		totalscores[i] = midscores[i] + finalscores[i] + sem1marks[i][0] + sem1marks[i][1] + sem2marks[i][0] + sem2marks[i][1];
	};
	setData(stud);

	do
	{
		printf("\nType '1' to add student\n");
		printf("\nType '2' to delete student\n");
		printf("\nType '3' to update student\n");
		printf("\nType '4' to view all records\n");
		printf("\nType '5' to calculate average of selected students scores\n");
		printf("\nType '6' to show student with max total\n");
		printf("\nType '7' to show student with min total\n");
		printf("\nType '8' to get student by id\n");
		printf("\nType '9' to sort records by total scores\n");
		printf("\nType '0' to exit\n");

		scanf("%d", &x);
		switch (x)
		{
		case 1:
			addStudent(stud);
			break;
		case 2:
			deleteStudent(stud);
			break;
		case 3:
			updateStudent(stud);
			/* code */
			break;
		case 4:
			viewStudentInfo(stud);
			break;
		case 5:
			avg(stud);
			break;
		case 6:
			max();
			break;
		case 7:
			min();
			break;
		case 8:
			printf("Enter student id: ");
			scanf("%d", &iden);
			findStudentById(iden, stud);
			break;
		case 9:
			sort(stud, MAX);
			setData(stud);
			break;
		default:
			break;
		};

	} while (x != 0);
}