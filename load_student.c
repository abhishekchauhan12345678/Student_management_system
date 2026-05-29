
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "insert.h"
#include "struct.h"
#include "load_student.h"
struct student *load_list_from_file() {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        // File doesn’t exist yet, so just return empty list
        return NULL;
    }

    struct student *head = NULL, *tail = NULL;
    int rolln, sem;
    long long contactno;
    char name[50], fname[50], gender[10], course[50], bloodgroup[10];
    int marks1, marks2, marks3;  // <-- declare marks variables

    // Read each line back from file
    while (fscanf(fp,
        "Roll No: %d | Name: %49[^|] | FName: %49[^|] | Gender: %9[^|] | Course: %49[^|] | BloodGroup: %9[^|] | Sem: %d | Contact: %lld | Marks1: %d | Marks2: %d | Marks3: %d\n",
        &rolln, name, fname, gender, course, bloodgroup, &sem, &contactno,
        &marks1, &marks2, &marks3) == 11)
    {
        struct student *ptr = malloc(sizeof(struct student));
        strcpy(ptr->name, name);
        strcpy(ptr->fname, fname);
        strcpy(ptr->gender, gender);
        strcpy(ptr->course, course);
        strcpy(ptr->bloodgroup, bloodgroup);
        ptr->sem = sem;
        ptr->contactno = contactno;
        ptr->rolln = rolln;

        // restore marks
        ptr->marks1 = marks1;
        ptr->marks2 = marks2;
        ptr->marks3 = marks3;

        ptr->next = NULL;
        ptr->prev = tail;
        if (tail != NULL) tail->next = ptr;
        else head = ptr;
        tail = ptr;
    }

    fclose(fp);
    return head;
}
