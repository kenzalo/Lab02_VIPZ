#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define n 50
struct student {
    char name[50];
    char surname[50];
    int day, month, year;
    int s1, s2, s3, s4, s5;
    struct student* next;
};
void printflist(struct student* start);
void deleteInside(struct student** pH, struct student** temp);
void deleteStart(struct student** pstart);
int lessthan35(struct student* list);
int AddToBeg(struct student** pstart, struct student* pElem);
int AddToEnd(struct student* start, struct student* pElem);
void deleteLast(struct student** start);
void FreeList(struct student** pstart);
void includeToList(struct student** start);
void DeleteLessAverage(struct student** start);



#endif