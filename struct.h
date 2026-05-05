#ifndef STUDENT_H
#define STUDENT_H

struct student {
    int rolln;
    char name[50];
    char fname[50];
    char gender[10];
    char course[50];
    char bloodgroup[10];
    int sem;
    long long contactno;
    struct student *next;
    struct student *prev;
};

#endif
