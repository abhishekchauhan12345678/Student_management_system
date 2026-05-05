
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "insert.h"
#include "struct.h"
#include "assign_roll.h"
void save_list_to_file(struct student *head);
struct student *insert_student(struct student *head, char name[], char fname[], char gender[], char course[], char bloodgroup[], int sem, long long contactno) // for inserting data;

{
    struct student *ptr, *temp, *second_last, *roll;
    roll = head;
    int rn = 1;
    int key = -1;
    ptr = (struct student *)malloc(sizeof(struct student));
    name[strcspn(name, "\n")] = 0;
    strcpy(ptr->name, name);

    fname[strcspn(fname, "\n")] = 0;
    strcpy(ptr->fname, fname);

    gender[strcspn(gender, "\n")] = 0;
    strcpy(ptr->gender, gender);

    course[strcspn(course, "\n")] = 0;
    strcpy(ptr->course, course);

    bloodgroup[strcspn(bloodgroup, "\n")] = 0;
    strcpy(ptr->bloodgroup, bloodgroup);

    ptr->sem = sem;
    ptr->contactno = contactno;

    temp = head;
    if (head == NULL)
    {
        ptr->prev = NULL;
        ptr->next = NULL;
        ptr->rolln = rn;
        head = ptr;
        printf(" >> Student is successfully added.\n");
        save_list_to_file(head);

        return head;
    }
    else if (head->next == NULL)
    {
        if (strcmp(temp->name, ptr->name) > 0)
        {

            ptr->next = head;
            head->prev = ptr;
            ptr->prev = NULL;
            head = ptr;
            roll = head;
            assign_roll(head);

            printf(" >> Student is successfully added.\n");
            save_list_to_file(head);

            return head;
        }
        else
        {
            ptr->next = NULL;
            ptr->prev = head;
            head->next = ptr;
            assign_roll(head);

            printf(" >> Student is successfully added.\n");
            save_list_to_file(head);

            return head;
        }
    }

    else
    {
        if (head == temp && strcmp(temp->name, ptr->name) > 0)

        {
            ptr->next = head;
            head->prev = ptr;
            ptr->prev = NULL;
            head = ptr;
            roll = head;
            assign_roll(head);
            printf(" >> Student is successfully added.\n");
            save_list_to_file(head);

            return head;
        }
        else
        {
            while (temp != NULL)
            {
                if (strcmp(temp->name, ptr->name) > 0)
                {
                    key = 1;
                    ptr->next = temp;
                    ptr->prev = temp->prev;
                    temp->prev->next = ptr;
                    temp->prev = ptr;
                    assign_roll(head);
                    printf(" >> Student is successfully added.\n");
                    save_list_to_file(head);

                    return head;
                }
                second_last = temp;
                temp = temp->next; // iammweaverfitness
            }
        }
        if (key == -1) // key is used to find that we have find the bigger node or not
        {

            ptr->next = NULL;
            ptr->prev = second_last;
            second_last->next = ptr;
            assign_roll(head);
            printf(" >> Student is successfully added.\n");
            save_list_to_file(head);
            return head;
        }
    }
    return head;
}
void save_list_to_file(struct student *head)
{
    FILE *fp = fopen("students.txt", "w"); // overwrite file
    if (fp != NULL)
    {
        struct student *temp = head;
        while (temp != NULL)
        {
           fprintf(fp, "Roll No: %d | Name: %s | FName: %s | Gender: %s | Course: %s | BloodGroup: %s | Sem: %d | Contact: %lld\n",
                    temp->rolln,
                    temp->name,
                    temp->fname,
                    temp->gender,
                    temp->course,
                    temp->bloodgroup,
                    temp->sem,
                    temp->contactno);
            temp = temp->next;
        }
        fclose(fp);
    }
    else
    {
        perror("Error opening file");
    }
}
