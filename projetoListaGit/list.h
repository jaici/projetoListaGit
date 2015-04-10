#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct lst Lst;
typedef struct duoList DL;

/**DEFINICAO DAS ESTRUTURAS**/
struct lst{
    int info;
    Lst *next;
};
struct duoList{
    int info;
    DL *prev;
    DL *next;
};

/**DEFINICAO DAS FUNCOES LISTA DE DADOS**/
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
/**DEFINICAO DE FUNCAO DE LISTA DUPLA DE DADOS**/
void freeMemoryDuoList(DL*);
void insertDuoList(DL** dl, int data);
DL* searchDuoList(DL* dl, int data);
void removeDuoList(DL** dl, int data);
void printDuoList(DL* dl);

#endif // LIST_H_INCLUDED
