#ifndef INSERT_H
#define INSERT_H
struct student
{
    struct student *prev;
    struct student *next;
    char name[50];
    char fname[50];
    char gender[10];
    char course[10];
    int sem;
    long long contactno;
    char bloodgroup[10];
    int rolln;
};

struct student *insert_student(struct student *head, char name[], char fname[], char gender[], char course[], char bloodgroup[], int sem, long long contactno); // for inserting data;
#endif