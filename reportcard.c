#include <stdio.h>
#include "struct.h"
#include "reportcard.h"

void generate_report_card(struct student *head, int roll) {
    if (head == NULL) {
        printf("No students enrolled yet.\n");
        return;
    }

    struct student *temp = head;
    while (temp != NULL) {
        if (temp->rolln == roll) {
            int total = temp->marks1 + temp->marks2 + temp->marks3;
            float percentage = total / 3.0;

            char grade;
            if (percentage >= 75) grade = 'A';
            else if (percentage >= 50) grade = 'B';
            else grade = 'C';

            printf("\n=====================================\n");
            printf("          REPORT CARD                \n");
            printf("=====================================\n");
            printf("Roll No     : %d\n", temp->rolln);
            printf("Name        : %s\n", temp->name);
            printf("Father Name : %s\n", temp->fname);
            printf("Course      : %s\n", temp->course);
            printf("Semester    : %d\n", temp->sem);
            printf("-------------------------------------\n");
            printf("Marks1      : %d\n", temp->marks1);
            printf("Marks2      : %d\n", temp->marks2);
            printf("Marks3      : %d\n", temp->marks3);
            printf("Total Marks : %d\n", total);
            printf("Percentage  : %.2f%%\n", percentage);
            printf("Grade       : %c\n", grade);
            printf("=====================================\n");
            return;
        }
        temp = temp->next;
    }

    printf("Student with Roll No %d not found.\n", roll);
}
