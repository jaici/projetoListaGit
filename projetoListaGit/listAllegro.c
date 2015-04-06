#include "listAllegro.h"

/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 16/03/2015
* @Description : Libera espaço da memória ocuplado pela lista
* @Parameters  : LR* lst
********************************************************************************/
void freeMemoryRec(LGEN* lst)
{
    LGEN* p = lst;
    while(p!=NULL){
        LGEN* t = p->next;   /** GUARDA REFERENCIA PARA O PROXIMO BLOCO **/
        free(p);            /** LIBERA MEMORIA DESTA LISTA             **/
        p = t;              /** FAZ COM QUE P APONTE PARA O PROXIMO    **/
    }
}
/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 16/03/2015
* @Description : Inicializa Lista
* @Return      : NULL
********************************************************************************/
LGEN* initList (void)
{
    return NULL;
}
/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 06/04/2015
* @Description : imprime os dados da lista
* @Parameters  : Lista* lst
********************************************************************************/
void printListGen(LGEN* lst)
{
    LGEN* aux = lst;
    REC *r = (REC*) aux->info;
    CIRC *c = (CIRC*) aux->info;
    int i=0;
    printf("----------------------------------------------------------\n");
    while(aux != NULL){
        i++;
        switch(aux->tipo){
        case ret:
            printf("I: %d \tP1(%03.0f,%03.0f)\tP2(%03.0f,%03.0f)\tCor(%03.0f,%03.0f,%03.0f)\n", i, r->x1,r->y1,r->x2,r->y2, r->color.r, r->color.g,r->color.b);
            break;
        case cir:
            printf("I: %d \tP1(%03.0f,%03.0f)\tRaio:%03.0f\tCor(%03.0f,%03.0f,%03.0f)\n", i, c->x1,c->y1,c->raio, c->color.r, c->color.g,c->color.b);
            break;
        default:
            printf("\n\nERRO - Tipo não Identificado.\n\n");
            break;
        }
        aux = aux->next;
    }
}
/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 06/04/2015
* @Description : Adiciona a lista heterogenea o retangulo
* @Parameters  : LGEN* lst, REC* rec
********************************************************************************/
void addRec(LGEN** lst, float x1,float y1, float x2, float y2, float r,float g, float b, float thicknes)
{
    /**Aloca espaço do retangulo**/
    REC* newRec = (REC*) malloc(sizeof(REC));
    if(newRec == NULL) exit(EXIT_FAILURE); /** Retorna msg caso de falha **/
    newRec->x1 = x1;
    newRec->x2 = x2;
    newRec->y1 = y1;
    newRec->y2 = y2;
    newRec->color.r = r;
    newRec->color.g = g;
    newRec->color.b = b;
    newRec->thicknes = thicknes;

    /**Aloca espaço para lista**/
    LGEN* newList = (LGEN*) malloc(sizeof(LGEN));
    if(newList == NULL) exit(EXIT_FAILURE); /** Retorna msg caso de falha **/
    newList->info = newRec;
    newList->tipo = ret;
    newList->next = *lst;
    *lst = newList;
}
/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 06/04/2015
* @Description : Adiciona a lista heterogenea o circulo
* @Parameters  : LGEN* lst, ponto, raio, cor e tamanho da borda
********************************************************************************/
void addCir(LGEN** lst, float x1,float y1, float raio, float r,float g, float b, float thicknes)
{
    /**Aloca espaço do retangulo**/
    CIRC* newCirc = (CIRC*) malloc(sizeof(CIRC));
    if(newCirc == NULL) exit(EXIT_FAILURE); /** Retorna msg caso de falha **/
    newCirc->x1 = x1;
    newCirc->y1 = y1;
    newCirc->raio = raio;
    newCirc->color.r = r;
    newCirc->color.g = g;
    newCirc->color.b = b;
    newCirc->thicknes = thicknes;

    /**Aloca espaço para lista**/
    LGEN* newList = (LGEN*) malloc(sizeof(LGEN));
    if(newList == NULL) exit(EXIT_FAILURE); /** Retorna msg caso de falha **/
    newList->info = newCirc;
    newList->tipo = cir;
    newList->next = *lst;
    *lst = newList;
}
