#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"


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