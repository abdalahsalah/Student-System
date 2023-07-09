#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#define MAX_STUDENTS 100

typedef struct student_data
{
    int totalGrade, ID, age;
    char *name, *password, *gender;
} st;

st *students[MAX_STUDENTS];

// Function declarations
void add_newStudent();
void remove_student();
void view_studentRecord();
void view_allRecords();
void edit_adminPass();
void edit_studentGrade();

#endif // ADMIN_H_INCLUDED
