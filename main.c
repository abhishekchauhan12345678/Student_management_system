#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "login.h"
#include "login.h"
struct student
{
    struct student *prev;
    struct student *next;
    char name[50];
    char fname[50];
    char gender[10];
    char course[10];
    int sem;
    long long contactno;
    char bloodgroup[10];
    int rolln;
};

struct student *insert_student(struct student *head, char name[], char fname[], char gender[], char course[], char bloodgroup[], int sem, long long contactno); // for inserting data;
struct student *del_student_byroll(struct student *head, int rollno);                                                                                           // for deleting student info;
// struct student *del_student_byname(struct student *head, char name[]);

void display_all_data(struct student *head); // for displaying all data

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
                int input;
                printf("press 1 for deleting student by there roll no and press 2 for delete student by there name");
                scanf("%d", &input);
                getchar();

                if (input == 1)
                {
                    int roll;
                    printf("enter rollno of student to delete");
                    scanf("%d", &roll);
                    getchar();
                    head = del_student_byroll(head, roll);
                }
                else if (input == 2)
                {
                    printf("enter full name of student");
                    fgets(name, sizeof(name), stdin);
                    // del_student_byname(head, name);
                }
                else
                {
                    printf("wrong input");
                }

                break;
            }
            case 4:
                display_all_data(head);
                break;
            default:
                break;
            }
        } while (f != 10);
    }
}
// for inserting student in database

void display_all_data(struct student *head)
{
    printf("\n>> ALL STUDENT DATA\n");
    struct student *trev = head; // for traversing
    while (trev != NULL)
    {
        printf("ROLL NO : %d || Name - %s || father name - %s || gender - %s || course - %s || bloodgroup - %s || current semester - %d || contact no -%lld  \n ", trev->rolln, trev->name, trev->fname, trev->gender, trev->course, trev->bloodgroup, trev->sem, trev->contactno);
        trev = trev->next;
    }
}
struct node *delete(struct student *head)
{
    if (head == NULL)
    {
        printf("CURRENTLY NO STUDENT IS ENROLLED");
    }
    else
    {
    }
}

struct student *del_student_byroll(struct student *head, int rollno)
{
    struct student *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->rolln == rollno && ptr == head)
        {
            ptr->next->prev = NULL;
            head = ptr->next;
            free(ptr);
            display_all_data(head);
            return head;
        }
        else if (ptr->rolln == rollno && ptr->next == NULL)
        {
            ptr->prev->next = NULL;
            ptr->prev = NULL;
            free(ptr);
            display_all_data(head);
            return head;
        }

        else
        {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
            display_all_data(head);
            return head;
        }

        ptr = ptr->next;
    }
    display_all_data(head);
    return head;
}
// struct student *del_student_byname(struct student *head, char name[]);
