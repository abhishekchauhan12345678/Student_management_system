#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "del_student.h"
#include "assign_roll.h"
#include "display.h"
#include "database.h"

struct student *del_student_byroll(struct student *head, int rollno)
{
    struct student *ptr;
    ptr = head;
    if (ptr == NULL)   // for no element present
    {  
        printf("THERE IS NO STUDENT ENROLLED TILL NOW");
        save_list_to_file(head);
        return head;
    }
    else if(ptr->rolln==rollno && ptr->next==NULL){
        free(ptr);
        head=NULL;
        printf("*---------*------------*-----------*\n");
        printf(" >>Student successfully deleted <<\n");
        printf("*---------*------------*-----------*\n");
        save_list_to_file(head);
        return NULL;
    }
    else
    {
        while (ptr != NULL)
        {
            if (ptr->rolln == rollno && ptr == head) // when first element is a key
            {
                ptr->next->prev = NULL;
                head = ptr->next;
                free(ptr); 
                break;
            }
            else if (ptr->rolln == rollno && ptr->next == NULL) //for last element
            {
                ptr->prev->next = NULL;
                free(ptr);
                break;
            }

            else if(ptr->rolln==rollno)
            {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                free(ptr);
                break;
                
            }
            
            else{
            ptr = ptr->next;
            }
        
            
        }
        ptr=head;
        assign_roll(head);
        display_all_data(head);
        save_list_to_file(head);
        printf("*--------------------------------*\n");
        printf(" >>Student successfully deleted <<\n");
        printf("*--------------------------------\n");
        save_list_to_file(head);

        return head;
    }
}