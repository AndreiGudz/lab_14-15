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
    FILE* my_file = fopen("students_file.txt", "r");
    if(my_file == NULL){
        printf("Файл students_file.txt не существует!\n");
        exit(-1);
    }

#define test

#ifdef test
    char *boof = malloc(3);
    fgets(boof, 3, my_file);
    int max = (int) strtol(boof, NULL, 10);
//    printf("%d ", (int) strtol(boof, NULL, 10));

    for (int i = 0; i < max ; i++) {
        char *my_string = calloc(20, sizeof(char));
        fgets(my_string, 21, my_file);
        printf("%s ", my_string);
        fgets(my_string, 21, my_file);
        printf("%s ", my_string);
        fgets(my_string, 2, my_file);
        printf("%s ", my_string);
        fgets(boof, 3, my_file);
        printf("%d ", (int) strtol(boof, NULL, 10));
        fgets(my_string, 9, my_file);
        printf("%8s ", my_string);
        fgets(boof, 2, my_file);
        printf("%d ", (int) strtol(boof, NULL, 10));
        fgets(boof, 2, my_file);
        printf("%d ", (int) strtol(boof, NULL, 10));
        fgets(boof, 2, my_file);
        printf("%d\n", (int) strtol(boof, NULL, 10));
    }
    free(boof);
    fclose(my_file);
#endif

#ifndef test
    char *boof = malloc(3);
    fgets(boof, 3, my_file);
    int max = (int) strtol(boof, NULL, 10);
    for (int i = 0; i < max ; i++){
        Node* student = malloc(sizeof(Node));
        student->_student = malloc(sizeof(Student));

        fgets(student->_student->name, 21, my_file);
        fgets(student->_student->last_name, 21, my_file);
        fgets(&(student->_student->gender), 2, my_file);
        fgets(boof, 2, my_file);
        student->_student->age = (int) strtol(boof, NULL, 10);
        fgets(student->_student->group, 9, my_file);
        fgets(boof, 2, my_file);
        student->_student->mathematics_grade = (int) strtol(boof, NULL, 10);
        fgets(boof, 2, my_file);
        student->_student->chemistry_grade = (int) strtol(boof, NULL, 10);
        fgets(boof, 2, my_file);
        student->_student->physics_grade = (int) strtol(boof, NULL, 10);

        /*fscanf(my_file, "%20s%20s%c%2d%s%1d%1d%1d",
                student->_student->name,
                student->_student->last_name,
                &(student->_student->gender),
                &(student->_student->age),
                student->_student->group,
                &(student->_student->mathematics_grade),
                &(student->_student->chemistry_grade),
                &(student->_student->physics_grade));*/
//        fseek(my_file, 1, SEEK_CUR);
        student->next = NULL;

        if(list->size == 0){
            list->head = student;
            list->tail = list->head;
        } else{
            list->tail->next = student;
            list->tail = student;
        }
        list->size++;
    }

    fclose(my_file);

    list->printAll(list);

    return list;
#endif
}

void* (SaveStudents)(void* _list){
    List* list = _list;
    FILE* my_file = fopen("students_file.txt", "w");
    if(my_file == NULL){
        printf("Файл students_file.txt не существует!\n");
        exit(-1);
    }

//    int i = 0;
    fprintf(my_file, "%2d", list->size);
    for (
            Node* cur_elem = list->head;
            cur_elem != NULL;
            cur_elem = cur_elem->next
            ){
        Student* student = cur_elem->_student;
            fprintf(my_file, "%20s%20s%c%2d%8s%1d%1d%1d",
                student->name,
                student->last_name,
                student->gender,
                student->age,
                student->group,
                student->mathematics_grade,
                student->chemistry_grade,
                student->physics_grade);
//        i++;
//            if (i != list->size){
//                fprintf(my_file, "\n");
//            }
    }
    fclose(my_file);
    return NULL;
}

