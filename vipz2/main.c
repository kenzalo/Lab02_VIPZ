#include"Header.h"
int main()
{
    FILE* input = fopen("input.bin", "rb");
    struct student* start = ReadStudents(input);
    printflist(start);
    includeToList(start);
    printflist(start);
    printf("\nThe average score is above 3.5\n");
    DeleteLessAverage(start);
    printflist(start);
    FreeList(&start);
}