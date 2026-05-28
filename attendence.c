#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "attendence.h"

void attendence(struct student *head)
{
    struct student *temp = head;
    char mark;
    char date[100];

    printf("==================\n");
    printf(" MARK ATTENDANCE\n");
    printf("==================\n");

    printf("---------------------------------------\n");
    printf(" Press P for present and A for absent \n");
    printf("---------------------------------------\n");
    printf("Enter today date in dd/mm/yy order: ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = '\0';   // remove newline

    FILE *fp2 = fopen("attendance.txt", "a");
    if (fp2 == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fp2, "Date: %s\n", date);

    while (temp != NULL)
    {
        printf("ROLL NO : [%d] : ", temp->rolln);
        scanf(" %c", &mark);   // skip whitespace/newline

        fprintf(fp2, "ROLL NO : %d : %c\n", temp->rolln, mark);

        temp = temp->next;
    }

    fclose(fp2);
    printf("Attendance saved to file.\n");
}
