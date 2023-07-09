#include <stdio.h>
#include <string.h>
#include "..\Admin\admin.h"
#include "student.h"


// Function to view student record
void view_record()
{
    int id=0, j=0;
    printf("Enter student ID : ");
    scanf("%d",&id);

    for (j = 0; j < 100; j++)
    {
        if(students[j]->ID == id)
        {
            puts("The data of this student is: \n");
            printf("Name : %s\n", &students[j]->name);
            printf("Age : %d\n", students[j]->age);
            printf("Gender : %s\n", &students[j]->gender);
            printf("Total Grade : %d\n\n", students[j]->totalGrade);
            printf("thank you \n\n");

            break;
        }

    }
  if(j==100)
    {
        puts("ID isnot found! try again.\n");
        view_record();
    }
}

// Function to edit student password
void edit_password()
{
  int id=0, i=0;
    printf("Enter student ID : ");
    scanf("%d",&id);
    for (i = 0; i < 100; i++)
    {
        if(students[i]->ID == id)
        {
      printf("Please, enter your new password: \n");
      scanf(" %[^\n]s", &students[i]->password);
      printf("student/s password edited successfully.\n\n");
      break;
    }
  }
  if(i==100)
    {
        puts("ID isnot found! try again.\n");
        edit_password();
    }
}

void edit_name()
{
  int id=0, i=0;
    printf("Enter student ID : ");
    scanf("%d",&id);
    for (i = 0; i < 100; i++)
    {
        if(students[i]->ID == id)
        {
      printf("Please, enter your new name: \n");
      scanf(" %[^\n]s", &students[i]->name);
      printf("The name has been updated");
      printf("student/s name edited successfully.\n\n");
      break;
    }
  }
  if(i==100)
    {
        puts("ID isnot found! try again.\n");
        edit_name();
    }
}


/*// Function to view student record
void view_record(int std_id)
{
    int std=0;

    for(int j=0; j<10; j++)
    {
        if(students[j]->ID==std_id)
            std = j;
        break;
    }
    puts("This is your record: \n");
    printf("Name : %s\n", &students[std]->name);
    printf("Age : %d\n", students[std]->age);
    printf("Gender : %s\n", &students[std]->gender);
    printf("Total Grade : %d\n\n", students[std]->totalGrade);

}

// Function to edit student password
void edit_password(int std_id)
{
    int std=0;

    for(int j=0; j<10; j++)
    {
        if(students[j]->ID==std_id)
            std = j;
        break;
    }

    printf("enter your new password: \n");
    scanf(" %[^\n]s", &students[std]->password);
}

void edit_name(int std_id)
{
     int std=0;

    for(int j=0; j<10; j++)
    {
        if(students[j]->ID==std_id)
            std = j;
        break;
    }
    printf("Please, enter your new name: \n");
    scanf(" %[^\n]s", &students[std]->name);
    printf("The name has been updated");
}*/
