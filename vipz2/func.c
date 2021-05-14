#include"Header.h"
void deleteInside(struct student** pH, struct student** temp)
{
    (*temp)->next = (*pH)->next;
    free(*pH);
    *pH = (*temp)->next;
}
void deleteStart(struct student** pstart)
{
    struct student* pTemp = NULL;
    pTemp = (*pstart)->next;
    free(*pstart);
}
int lessthan35(struct student* list)
{
    int k = 0;
    k = (list->s1 + list->s2 + list->s3 + list->s4 + list->s5) / 5.0;
    if (k < 3.5)
        return 1;
    else
        return 0;
}
int AddToBeg(struct student** pstart, struct student* pElem)
{
    if (*pstart == NULL || pElem == NULL)
        return 1;
    pElem->next = *pstart;
    *pstart = pElem;
}
int AddToEnd(struct student** start, struct student* pNewElement)
{
    struct student* ptemp = *start;
    if (ptemp == NULL)
    {
        ptemp = pNewElement;
        *start = ptemp;
        ptemp->next = NULL;

    }
    else {
        while (ptemp->next != NULL)
        {
            ptemp = ptemp->next;
        }
        struct student* pNewtemp = pNewElement;
        ptemp->next = pNewtemp;
        pNewtemp->next = NULL;

    }
}

void printflist(struct student* start)
{
    struct student* l = start;
    while (l != NULL)
    {
        printf("%-6s ", l->name);
        printf("%-7s ", l->surname);
        printf("%d %d %d ", l->day, l->month, l->year);
        printf("%d %d %d %d %d", l->s1, l->s2, l->s3, l->s4, l->s5);
        printf("\n");
        l = l->next;

    }
}
void deleteLast(struct student** pt)
{
    (*pt)->next = NULL;
    *pt = NULL;
    free(*pt);
}
void FreeList(struct student** pstart)
{
    struct student* pTemp = *pstart;
    while (pTemp)
    {
        *pstart = pTemp->next;
        free(pTemp);
        pTemp = *pstart;
    }
    *pstart = NULL;
}
void includeToList(struct student** start)
{
    struct student* p = *start;
    struct student* NewElement1();
    struct student* NewElement = (struct student*)malloc(sizeof(struct student));

    printf("enter name\n");
    gets(NewElement->name);
    printf("enter surname\n");
    gets(NewElement->surname);
    printf("enter day of birthday\n");
    scanf("%d", &(NewElement->day));
    printf("enter month of birthday\n");
    scanf("%d", &(NewElement->month));
    printf("enter year of birthday\n");
    scanf("%d", &(NewElement->year));
    printf("enter marks\n");
    scanf("%d %d %d %d %d", &(NewElement->s1), &(NewElement->s2), &(NewElement->s3), &(NewElement->s4), &(NewElement->s5));
    p = start;
    if (NewElement->year > p->year)
        AddToBeg(&start, NewElement);
    else if (NewElement->year == p->year)
    {
        if (NewElement->month > p->month)
            AddToBeg(&start, NewElement);
        else if (NewElement->month == p->month)
        {
            if (NewElement->day > p->day)
                AddToBeg(&start, NewElement);
        }
    }
    while (p != NULL)
    {
        if (NewElement->year < p->year)
            AddToEnd(start, NewElement);
        else if (NewElement->year == p->year)
        {
            if (NewElement->month < p->month)
                AddToEnd(start, NewElement);
            else if (NewElement->month == p->month)
            {
                if (NewElement->day < p->day)
                    AddToEnd(start, NewElement);
            }
        }
        p = p->next;
    }
}
void DeleteLessAverage(struct student** start)
{
    struct student* pt = start;
    struct student* pTemp = NULL;
    pTemp = start;
    while (pt != NULL)
    {
        pTemp = start;
        if (lessthan35(pt))
        {
            if (pt == start)
            {
                deleteStart(&start);
                pt = pt->next;
            }
            else
            {
                while (pTemp->next != pt)
                {
                    pTemp = pTemp->next;
                }
                if (pt->next == NULL)
                {
                    deleteLast(&pt);
                    pTemp->next = NULL;
                }
                else
                {
                    deleteInside(&pt, &pTemp);

                }
            }
        }
        else
        {
            pt = pt->next;
        }
    }
}