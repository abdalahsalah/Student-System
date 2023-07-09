/* --------------------------------------------------------
 -Student record System project using C language programming.
 -Developers:-
    -Mahmoud Ahmed Fahmy
      -main.h
      -main.c
      -admin.c
      -admin.h
    -Adullah Salah Al-Badry
      -student.c
      -student.h
 --------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "..\User\Admin\admin.h"
#include "..\User\Student\student.h"

int main()
{
    int mode=0, task=0, temp_pass=0, attempts=3;

    puts("\n ----------------------------------------------");
    puts("|     Welcome to the student record system     |");
    puts(" ----------------------------------------------\n");

Close_Mode: //when we close any mode , come here.
    //we can make getmode function instead of coming lines before switch
    printf("choose mode : \n 1.Admin \n 2.Student \n 3.close the program \n\n");
    printf("My choice : ");
    scanf("%d",&mode);

    /* while (mode != 1 && mode != 2 && mode != 3)
     {
         puts("");
         printf("Invalid choice, please enter a valid choice (1 or 2 or 3): \n");
         printf("My choice : ");
         scanf("%d",&mode);
     } */

    switch(mode)
    {
    case 1 :
        for(int i=0; i<ALLOWED_LOGIN_ATTEMPTS; i++)
        {
            printf("Enter your password : ");
            scanf("%d",&temp_pass);
            if(admin_pass == temp_pass)
            {
                puts("\n ----------------------------------------------");
                puts("|           Welcome to the admin mode          |");
                puts(" ----------------------------------------------\n");

Function_End_Admin:  //label used when the user choose number other than 1 to 7
                printf("Select the task you want to perform : \n\n 1.Add student record."
                       "\n 2.Remove student record. \n 3.View student record. \n 4.View all records."
                       "\n 5.Edit admin passowrd. \n 6.Edit student grade. \n 7.Close admin mode.\n\n");
                printf("My choice : ");
                scanf("%d",&task);

                switch(task)
                {
                case 1 :
                    add_newStudent();
                    goto Function_End_Admin;
                    break;
                case 2 :
                    remove_student();
                    goto Function_End_Admin;
                    break;
                case 3 :
                    view_studentRecord();
                    goto Function_End_Admin;
                    break;
                case 4 :
                    view_allRecords();
                    goto Function_End_Admin;
                    break;
                case 5 :
                    edit_adminPass();
                    goto Close_Mode;
                    break;
                case 6 :
                    edit_studentGrade();
                    goto Function_End_Admin;
                    break;
                case 7 :
                    puts("");
                    goto Close_Mode;
                    break;
                default :
                    puts("Enter valid choice!\n");
                    goto Function_End_Admin;
                    break;
                }
            }
            else
            {
                puts("Password is wrong. Try again!");
                attempts--;
                if(attempts != 0)
                    printf("%d attempts left.. \n\n",attempts);
                else
                    puts("You no longer have attempts.\n");
            }
        }
        break;
    case 2 :
//ID_STD_again:  // when student enter nonexist id.
        /* printf("Enter your ID : ");
         int idSTD=0, j=0;
         scanf("%d",&idSTD);
         for (j = 0; j < 100; j++)
         {
             if(students[j]->ID == idSTD) // null case
             {*/
        puts("\n ----------------------------------------------");
        puts("|           Welcome to the student mode         |");
        puts(" ----------------------------------------------\n");

Function_End_Student :   //label used when the user choose number other than 1 to 4
        printf("Select the task you want to perform : \n 1.View your record."
               "\n 2.Edit your password. \n 3.Edit your name. \n 4.Close student mode.\n\n");
        printf("My choice : ");
        scanf("%d",&task);

        switch(task)
        {
        case 1 :
            view_record();
            goto Function_End_Student;
            break;
        case 2 :
            edit_password();
            goto Function_End_Student;
            break;
        case 3 :
            edit_name();
            goto Function_End_Student;
            break;
        case 4 :
            puts("");
            goto Close_Mode;
            break;
        default :
            puts("Enter valid choice!\n");
            goto Function_End_Student;
            break;
        }


        /*if(j==100)
        {
            puts("ID isnot found. Try again!");
            goto ID_STD_again;
        }*/
        break;
    case 3 :
        printf("Thank you and see you soon");
        break;
    default :
        puts("Enter valid choice!\n");
        goto Close_Mode;
        break;
    }
    return 0;
}
