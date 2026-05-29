#include <stdio.h>
#include "struct.h"
#include "marks.h"

void enter_marks(struct student *head) {
    if (head == NULL) {
        printf("No students enrolled yet.\n");
        return;
    }

    int roll;
    printf("Enter roll number to assign marks: ");
    scanf("%d", &roll);

    struct student *temp = head;
    while (temp != NULL) {
        if (temp->rolln == roll) {
            if (temp->marks1 != 0 || temp->marks2 != 0 || temp->marks3 != 0) {
                printf("Marks already entered for this student. Use update instead.\n");
                return;
            }

            printf("Enter marks for Subject 1: ");
            scanf("%d", &temp->marks1);
            printf("Enter marks for Subject 2: ");
            scanf("%d", &temp->marks2);
            printf("Enter marks for Subject 3: ");
            scanf("%d", &temp->marks3);

            printf("Marks entered successfully for Roll No %d.\n", roll);
            return;
        }
        temp = temp->next;
    }
    printf("Student with Roll No %d not found.\n", roll);
}

void update_marks(struct student *head)
{
    if (head == NULL) {
        printf("No students enrolled yet.\n");
        return;
    }

    int roll;
    printf("Enter roll number to update marks: ");
    scanf("%d", &roll);

    struct student *temp = head;
    while (temp != NULL) {
        if (temp->rolln == roll) {
            printf("Current Marks: Sub1=%d, Sub2=%d, Sub3=%d\n",
                   temp->marks1, temp->marks2, temp->marks3);

            printf("Enter new marks for Subject 1: ");
            scanf("%d", &temp->marks1);
            printf("Enter new marks for Subject 2: ");
            scanf("%d", &temp->marks2);
            printf("Enter new marks for Subject 3: ");
            scanf("%d", &temp->marks3);

            printf("Marks updated successfully for Roll No %d.\n", roll);
            return;
        }
        temp = temp->next;
    }
    printf("Student with Roll No %d not found.\n", roll);
}
