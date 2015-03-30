#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct lst Lst;

struct lst{
    int info;
    Lst *next;
};

/**DEFINICAO DAS FUNCOES*/
Lst* init (void);
Lst* insertList(int data, Lst* lst);
Lst* fileReader(char fileName[], Lst* lst);
void insertList2(Lst** lst, int data);
Lst* searchList(Lst* lst, int data);
void printList(Lst* lst);
void removeList(Lst* lst, int data);
void freeMemory(Lst* lst);
void insertOrder(Lst** lst, int data);
void printRecursive(Lst* lst);

#endif // LIST_H_INCLUDED
