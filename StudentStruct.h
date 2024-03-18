//
// Created by Андрей и Витя on 14.03.2024.
//

#ifndef PR13_STUDENTSTRUCT_H
#define PR13_STUDENTSTRUCT_H

#include "ListStruct.h"

#define MathTop(value) topTenInMath(value)
#define student(var) studentInit(var)

typedef struct Student{
    char name[20];
    char last_name[20];
    char gender;
    int age;
    char group[8];
    int mathematics_grade;
    int physics_grade;
    int chemistry_grade;
    void* (*print)(void* );
} Student;

typedef struct TopArgs{
    List* list;
    int count;
} TopArgs;

void* studentInit(void*);
void* topTenInMath(void*);

#endif //PR13_STUDENTSTRUCT_H
