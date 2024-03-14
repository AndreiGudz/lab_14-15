#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "StudentStruct.h"

#define SRandom srand(time(NULL))
#define MathTop(value) topTenInMath(value)
#define ListFilling(count, list)        \
for (int i = 0; i < count; i++)         \
    list_of_student->append(list);

int main()
{
    SRandom;
    printf("How many students create (max 20): ");
    int count_student;
    scanf("%d",&count_student);
    if (count_student > 20)
        count_student = 20;

    struct List* list_of_student = listInit();
    ListFilling(count_student, list_of_student)

    struct TopArgs* args = malloc(sizeof(struct TopArgs) );
    args->list = list_of_student;
    for (args->count = 0; args->count < count_student; args->count++){
        list_of_student->print(args);
    }
    printf("\n");
    MathTop(args);
    return 0;
}



