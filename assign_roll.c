#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "assign_roll.h"
#include "struct.h"

struct student *assign_roll(struct student *head){
struct student *roll;
int rn =1 ;
    roll = head;
while(roll != NULL)
            {
                roll->rolln = rn;
                rn++;
                roll = roll->next;
            }

  }

