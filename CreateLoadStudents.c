//
// Created by Андрей и Витя on 14.03.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "ListStruct.h"
#include "CreateLoadStudents.h"

#define SRandom srand(time(NULL))

void* (SaveStudents)(void*);

void* (CreateStudents)(void*){
    SRandom;
    List* list = list(NULL);
    int count = 0;

    printf("How many students create (max 20): ");
    scanf("%d", &count);
    printf("\n");
    fflush(stdin);
    if (count > 20)
        count = 20;

    for (int i = 0; i < count; i++)
        list->append(list);

    list->printAll(list);

    printf("сохранить новых студентов?(y/N): ");
    char save_file = 'n';
    scanf("%c", &save_file);
    fflush(stdin);
    printf("\n");

    if (save_file == 'y'){
        SaveStudents(list);
    }
    return list;
}

void* (LoadStudents)(void*){
    List* list = list(NULL);
    FILE* my_file = fopen("students_file.bin", "rb");
    if(my_file == NULL){
        printf("Файл students_file.bin не существует!\n");
        exit(-1);
    }

    fread(&(list->size), sizeof(int), 1, my_file);
    for (int i = 0 ; i < list->size; i++){
        Node* student = malloc(sizeof(Node) );

        fread(student->node_student, sizeof(Student), 1, my_file);
        student->next = NULL;
        student->node_student->print(student->node_student);
        if(list->size == 0){
            list->head = student;
            list->tail = list->head;
        } else{
            list->tail->next = student;
            list->tail = student;
        };
    }

    fclose(my_file);

    list->printAll(list);

    return list;
}

void* (SaveStudents)(void* _list){
    List* list = _list;
    FILE* my_file = fopen("students_file.bin", "wb");
    if(my_file == NULL){
        printf("Файл students_file.bin не существует!\n");
        exit(-1);
    }

//    int i = 0;
    fwrite(&(list->size), sizeof(int), 1, my_file);
    for (
            Node* cur_elem = list->head;
            cur_elem != NULL;
            cur_elem = cur_elem->next
            ){
        Student* student = cur_elem->node_student;
        fwrite(student, sizeof(Student), 1, my_file);

        /*fprintf(my_file, "%20s%20s%c%2d%8s%1d%1d%1d",
            student->name,
            student->last_name,
            student->gender,
            student->age,
            student->group,
            student->mathematics_grade,
            student->chemistry_grade,
            student->physics_grade);*/
    }
    fclose(my_file);
    return NULL;
}

