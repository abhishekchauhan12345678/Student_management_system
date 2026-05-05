#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "login.h"
#include "insert.h"
#include "display.h"
#include "assign_roll.h"
#include "del_student.h"

// for deleting student info;
// struct student *del_student_byname(struct student *head, char name[]);

int main()
{

    printf("x=======================================x");
    printf("\n WELCOME TO STUDENT MANAGEMENT SYSTEM \n");
    printf("x=======================================x\n");

    int check;
    check = login();

    if (check == 0)
    {
        struct student *head = NULL;
        int f;

        char name[50];
        char fname[50];
        char gender[50];
        char course[10];
        int sem;
        long long contactno;
        char bloodgroup[10];
        do
        {

            printf("Press 1 for Add student.\n");
            printf("press 2 for Delete student.\n");
            printf("press 3 for attendence mark.\n");
            printf("press 4 for attendence view");
            printf("press 5 for entering marks");
            printf("press 6 for update marks");
            printf("press 5 for all student data.\n");
            printf("Choose : ");
            scanf("%d", &f);
            getchar();
            switch (f)
            {
            case 1:
            {
                int confirm;
                printf("You chose Add Student. Do you want to continue? (1 = Yes, 2 = No): ");
                scanf("%d", &confirm);
                getchar();

                if (confirm == 1)
                {
                    int z = 0;
                    while (z != 2)
                    {
                        printf("Enter the name of the student: "); // student name
                        fgets(name, sizeof(name), stdin);

                        printf("Enter Students father name : ");
                        fgets(fname, sizeof(fname), stdin);

                        printf("Enter gender : ");
                        fgets(gender, sizeof(gender), stdin);

                        printf("Enter bloodgroup: ");
                        fgets(bloodgroup, sizeof(bloodgroup), stdin);

                        printf("Enter course: ");
                        fgets(course, sizeof(course), stdin);

                        printf("enter semester : ");
                        scanf("%d", &sem);

                        printf("enter contact no : ");
                        scanf("%lld", &contactno);
                        getchar();

                        head = insert_student(head, name, fname, gender, course, bloodgroup, sem, contactno);

                        printf("Press 2 to exit adding, or any other number to add another: ");
                        scanf("%d", &z);
                        getchar();
                    }
                }
                else
                {
                    printf("Cancelled adding student.\n");
                }
                break;
            }
            case 2:
            {
                int roll;
                printf("enter rollno of student to delete");
                scanf("%d", &roll);
                getchar();
                head = del_student_byroll(head, roll);
                break;
            }
            case 3:
            {

                break;
            }
            case 10:
                display_all_data(head);
                break;
            default:
                break;
            }
        } while (f != 10);
    }
}
