//
// Created by Андрей и Витя on 14.03.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "StudentStruct.h"
#include "CreateLoadStudents.h"
#include "ListStruct.h"

#define SRandom srand(time(NULL))

void* (SaveStudents)(void*);

void* (CreateStudents)(void*){
    SRandom;
    TopArgs* _args = malloc(sizeof(struct TopArgs) );
    _args->list = list(NULL);

    printf("How many students create (max 20): ");
    scanf("%d",&(_args->count));
    printf("\n");
    if (_args->count > 20)
        _args->count = 20;


    for (int i = 0; i < _args->count; i++)
        _args->list->append(_args->list);

    printf("сохранить новых студентов?(y/N): ");
    char save_file = 'n';
    scanf(&save_file);
    printf("\n");

    if (save_file != 'y'){
        SaveStudents(_args->list);
    }
    return _args;
}

void* (LoadStudents)(void*){
    TopArgs* _args = malloc(sizeof(struct TopArgs) );
    _args->list = list(NULL);


    return _args;
}

void* (SaveStudents)(void*){
    return NULL;
};









