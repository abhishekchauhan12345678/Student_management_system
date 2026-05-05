

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"
int login() // for login
{

    while (1)
    {

        char username[20];
        char password[20];
        printf("Enter username : ");
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = 0;
        printf("Enter password : ");

        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = 0;

        // login
        if (strcmp(username, "admin") == 0 && strcmp(password, "abhi") == 0)
        {   printf("*-------*-----------*----------*\n");
            printf(" >> successfully logged in << \n");
            printf("*-------*-----------*----------*\n");
            return 0;
        }
        else
        {   printf("*-------------*-------------*--------------*\n");
            printf(">> invalid username or password try again...\n");
            printf("*-------------*-------------*--------------*\n");

        }
    }
}