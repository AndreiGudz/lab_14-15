//
// Created by Андрей и Витя on 14.03.2024.
//

#ifndef PR13_STUDENTSTRUCT_H
#define PR13_STUDENTSTRUCT_H

struct Student{
    char name[20];
    char last_name[20];
    char gender;
    int age;
    char group[8];
    int mathematics_grade;
    int physics_grade;
    int chemistry_grade;
    void* (*print)(void* );
};

struct Node{
    struct Student student;
    struct Node* next;
};

struct TopArgs{
    struct List* list;
    int count;
};

struct List{
    struct Node* head;
    struct Node* tail;
    unsigned int size;
//    void (*insert)(struct List*, int index);
//    void (*erase)(struct List*, int index);
    void* (*append)(void* );
//    bool (*swap)(struct List*, int first_index, int second_index);
    void* (*print)(void*);
};

void* (listInit)();
void* studentInit(void*);
void* topTenInMath(void*);

#endif //PR13_STUDENTSTRUCT_H
