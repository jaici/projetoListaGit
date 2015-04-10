//https://sites.google.com/a/liesenberg.biz/cjogos/home/software/ambiente-code-blocks-allegro-5 (TUTORIAL)
#ifndef LISTALLEGRO_H_INCLUDED
#define LISTALLEGRO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>

#define RET 0
#define TRI 1
#define CIR 2

typedef struct background RGB;
typedef struct rectangle REC;
typedef struct circle CIRC;
typedef struct listGen LGEN;

enum{ret, cir};

enum{contornoRedondo, contorno, preenchimentoRedondo, preenchimento};
/**DEFINICAO DAS ESTRUTURAS LISTA ALLEGRO**/
struct background{
    float r,g,b;
};
struct rectangle{
    float x1,y1,x2,y2;
    float thicknes;
    RGB color;
};

struct circle{
    float x1,y1,raio;
    float thicknes;
    RGB color;
};

struct listGen{
    int tipo;
    void *info;
    LGEN* next;
};

/**DEFINICAO DAS FUNCOES LISTA ALLEGRO**/
void insertRec(LGEN** lst, REC* rec);
void freeMemoryRec(LGEN* lst);
void printListGen(LGEN* lst);
LGEN* initList (void);
void addRec(LGEN** lst, float x1,float y1, float x2, float y2, float r,float g, float b, float thicknes);
void addCir(LGEN** lst, float x1,float y1, float raio, float r,float g, float b, float thicknes);
void calcArea(LGEN* lst);
void desenha(LGEN* lst, char padrao);
#endif // LISTALLEGRO_H_INCLUDED
