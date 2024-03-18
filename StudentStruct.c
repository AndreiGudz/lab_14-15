//
// Created by Андрей и Витя on 29.02.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StudentStruct.h"

const char names[10][20] = {
        "Natasha",
        "Masha",
        "Ilya",
        "Artem",
        "Sasha",
        "Valya",
        "Vasya",
        "Kuzya",
        "Buzya",
        "Misha"
};

const char last_names[10][20] = {
        "Igov",
        "Brown",
        "Ilyanov",
        "Artemov",
        "Lomov",
        "Val",
        "Tarasov",
        "Kuznezov",
        "Romanov",
        "Gromov"
};

void* studentPrint(void*);
void* studentPrintInList(void*);

void* studentInit(void* _student){
    Student* student = _student;
    strcpy(student->name,names[rand()%10]);
    strcpy(student->last_name, last_names[rand() % 10]);
    student->gender = 'M';
    student->age = rand() % 5 + 16;
    strcpy(student->group,"ISP-204");
    student->mathematics_grade = rand() % 4 + 2;
    student->chemistry_grade = rand() % 4 + 2;
    student->physics_grade = rand() % 4 + 2;
    student->print = studentPrint;
    return NULL;
}

void* studentPrint(void* _student){
    Student* student = _student;
    printf("\t Student %s %s ", student->name, student->last_name);
    printf("Grade %d\n", student->mathematics_grade);
    return NULL;
}

void* topTenInMath(void* _list){
    List* list = _list;
    int top_in_math;
    if (list->size > 10)
        top_in_math = 10;
    else
        top_in_math = list->size;

    int position_in_top = 1;
    for (
            int max_grade = 5;
            (position_in_top <= top_in_math) && (max_grade > 1);
            max_grade--)
        for (Node* cur_elem = list->head;
             cur_elem != NULL;
             cur_elem = cur_elem->next){
            if (
                    (cur_elem->student.mathematics_grade == max_grade)
                    && (position_in_top <= top_in_math)
                    ){
                printf("Top position %d\n", position_in_top);
                cur_elem->student.print(&(cur_elem->student));
                position_in_top += 1;
            }
        }
    return NULL;
}

