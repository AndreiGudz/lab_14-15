//
// Created by Андрей и Витя on 18.03.2024.
//

#include <malloc.h>
#include "ListStruct.h"

void* appendStudent(void*);
void* studentPrintInList(void*);

void* (listInit)(void*){
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->print = studentPrintInList;
    list->append = appendStudent;
    return (void*) list;
}

void* appendStudent(void* _list){
    List* list = _list;
    Node* student = malloc(sizeof(Node));
    student(&(student->student));
    student->next = NULL;

    if(list->size == 0){
        list->head = student;
        list->tail = list->head;
    } else{
        list->tail->next = student;
        list->tail = student;
    }
    list->size++;
    return NULL;
}

void* studentPrintInList(void* _args){
    TopArgs* args = _args;
    if (args->count < 0 || args->count >= args->list->size)
        return NULL;

    int i = 0;
    for(
            Node* cur_elem = args->list->head;
            cur_elem != NULL;
            cur_elem = cur_elem->next
            ){
        if(i == args->count){
            cur_elem->student.print(&(cur_elem->student));
        }
        i++;
    }
    return NULL;
}
