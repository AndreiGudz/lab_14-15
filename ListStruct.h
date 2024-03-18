//
// Created by Андрей и Витя on 18.03.2024.
//

#ifndef PR14_LISTSTRUCT_H
#define PR14_LISTSTRUCT_H

#include "StudentStruct.h"

#define list(var) listInit(var)

typedef struct Node{
    struct Student student;
    struct Node* next;
} Node;

typedef struct List{
    Node* head;
    Node* tail;
    unsigned int size;
//    void (*insert)(struct List*, int index);
//    void (*erase)(struct List*, int index);
    void* (*append)(void* );
//    bool (*swap)(struct List*, int first_index, int second_index);
    void* (*print)(void*);
} List;

void* (listInit)(void*);

#endif //PR14_LISTSTRUCT_H
