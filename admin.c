#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\..\Application\main.h"
#include "admin.h"

static int num_students = 0;
int admin_pass=1234;

void add_newStudent()
{
    int temp_ID=0;
    //char firstName[20], secondName[20], lastName[20];
    students[num_students] = (st*)malloc(sizeof(st));

    printf("\nEnter the data of the new student: \n\n");

    printf("Name : ");
    scanf("%s",&students[num_students]->name);

    /*printf("Second name : ");
    scanf("%s",secondName);

    printf("Last name : ");
    scanf("%s",lastName);*/

    /*strcpy(students[num_students]->name, firstName);
    strcat(students[num_students]->name, " ");
    strcat(students[num_students]->name, secondName);
    strcat(students[num_students]->name, " ");
    strcat(students[num_students]->name, lastName);*/

    //Handling input buffer to read name safely
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    printf("Age : ");
    scanf("%d",&students[num_students]->age);

    printf("Gender : ");
    scanf("%s",&students[num_students]->gender);

Enter_ID_Again: // when admin enter ID for new student and it is taken by another
    printf("ID : ");
    scanf("%d",&temp_ID);
    for (int j = 0; j < num_students; j++)
    {
        if(students[j]->ID == temp_ID)
        {
            puts("This ID is taken by another student.");
            goto Enter_ID_Again;
        }
    }
    students[num_students]->ID=temp_ID;

    printf("Password : ");
    scanf("%s",&students[num_students]->password);

    printf("Total Grade : ");
    scanf("%d",&students[num_students]->totalGrade);

    num_students++;

    //To add another student
    int yes_no = 0;
    puts("\nDo you want to add another student? \n 1.Yes \n 2.No \n");
    printf("My choice : ");
    scanf("%d",&yes_no);
    if(yes_no == 1)
        add_newStudent();
    else if(yes_no == 2)
        printf("student/s added successfully.\n\n");
    else
        printf("Enter valid choice (1 or 2 ).\n\n");
}

void remove_student()
{
    int id=0, j=0; //lastCase=0;
    printf("Enter student ID : ");
    scanf("%d",&id);

    for (j = 0; j < num_students; j++)
    {
        if(students[j] != NULL && students[j]->ID == id)
        {
            free(students[j]);
            students[j] = NULL;
            /*if (j==num_students-1)
            {
                lastCase = num_students
            }*/
            num_students--;
            //rahl
            for(int k=j ; k<num_students ; k++)
            {
                students[k] = students[k+1];
            }
            students[num_students] = NULL;
            printf("Student with ID %d has been removed.\n\n", id);
            return;
            // break;
        }
    }
    puts("ID isnot found! try again.");
    remove_student();
    /*if(j==num_students)
    {
        puts("ID isnot found! try again.");
        remove_student();
    }*/
}

void view_studentRecord()
{
    int id=0,j=0;
    printf("Enter student ID : ");
    scanf("%d",&id);

    for (j = 0; j < num_students; j++)
    {
        if(students[j]->ID == id)
        {
            puts("The data of this student is: \n");
            printf("Name : %s\n", &students[j]->name);
            printf("Age : %d\n", students[j]->age);
            printf("Gender : %s\n", &students[j]->gender);
            printf("Total Grade : %d\n\n", students[j]->totalGrade);

            break;
        }
    }
    if(j==num_students)
    {
        puts("ID isnot found! try again.\n");
        view_studentRecord();
    }

    //To view another student record
    int yes_no = 0;
    puts("\nDo you want to view another student record? \n 1.Yes \n 2.No \n");
    printf("My choice : ");
    scanf("%d",&yes_no);
    if(yes_no == 1)
        view_studentRecord();
    else if(yes_no == 2)
        puts("");
    else
        printf("Enter valid choice (1 or 2 ).\n\n");
}

void view_allRecords()
{
    for(int i = 0; i<num_students; i++)
    {
        printf("\nThe data of the student number %d is: \n",i+1);
        printf("Name : %s\n", &students[i]->name);
        printf("Age : %d\n", students[i]->age);
        printf("Gender : %s\n", &students[i]->gender);
        printf("Total Grade : %d\n\n", students[i]->totalGrade);
    }
}

void edit_adminPass()
{
    int temp=0;
    printf("Enter new password : ");
    scanf("%d",&temp);
    admin_pass = temp;
    printf("your password changed successfully.\n\n ");
}

void edit_studentGrade()
{
    int id=0, j=0;
    printf("Enter student ID : ");
    scanf("%d",&id);

    for (j = 0; j < num_students; j++)
    {
        if(students[j]->ID == id)
        {
            printf("The current total grade of this student is %d\n",students[j]->totalGrade);
            printf("Enter the new grade : ");
            scanf("%d",&students[j]->totalGrade);
            printf("The new total grade of this student is %d\n",students[j]->totalGrade);

            break;
        }
    }
    if(j==num_students)
    {
        puts("ID isnot found! try again.");
        edit_studentGrade();
    }
}

