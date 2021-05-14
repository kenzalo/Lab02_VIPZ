#include"Header.h"
int main()
{
    FILE* input = NULL;
    input = fopen("input.bin", "rb");
    if (!input)
    {
        printf("File hasn't opened");
    }
    struct student* start = (struct student*)malloc(sizeof(struct student));
    struct student* p = start;
    struct student* pTemp = NULL;
    while (!feof(input))
    {
        fread(p->name, sizeof(char), 50, input);
        if (!feof(input))
        {
            fread(p->surname, sizeof(char), 50, input);
            fread(&(p->day), sizeof(int), 1, input);
            fread(&(p->month), sizeof(int), 1, input);
            fread(&(p->year), sizeof(int), 1, input);
            fread(&(p->s1), sizeof(int), 1, input);
            fread(&(p->s2), sizeof(int), 1, input);
            fread(&(p->s3), sizeof(int), 1, input);
            fread(&(p->s4), sizeof(int), 1, input);
            fread(&(p->s5), sizeof(int), 1, input);
            p->next = (struct student*)calloc(1, sizeof(struct student));
            p = p->next;
            p->next = NULL;
        }

    }
    printflist(start);
    includeToList(start);
    printflist(start);
    printf("\nThe average score is above 3.5\n");
    DeleteLessAverage(start);
    printflist(start);
    FreeList(&start);
}