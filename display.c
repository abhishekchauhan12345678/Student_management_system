#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
#include "struct.h"

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
