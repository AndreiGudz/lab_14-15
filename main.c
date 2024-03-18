#include <stdio.h>
#include "StudentStruct.h"
#include "CreateLoadStudents.h"

int main()
{
    printf("Загрузить существующих студентов или создать новых?(y/N): ");
    char create_file = 'n';
    scanf(&create_file);
    printf("\n");

    TopArgs* args;

    if (create_file == 'y')
        args = CreateStudents(NULL);
    else
        args = LoadStudents(NULL);

    for (args->count = 0 ; args->count < args->list->size; args->count++) {
        args->list->print(args);
    }

    MathTop(args);
    return 0;
}



