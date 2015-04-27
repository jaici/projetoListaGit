#include "listAllegro.h"

/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 16/03/2015
* @Description : Libera espa�o da mem�ria ocuplado pela lista
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
    REC *r = NULL;
    CIRC *c = NULL;
    int i=0;
    printf("----------------------------------------------------------\n");
    while(aux != NULL){
        i++;
        switch(aux->tipo){
        case ret:
            r = aux->info;
            printf("I: %d \tP1(%03.0f,%03.0f)\tP2(%03.0f,%03.0f)\tCor(%03.0f,%03.0f,%03.0f)\n", i, r->x1,r->y1,r->x2,r->y2, r->color.r, r->color.g,r->color.b);
            break;
        case cir:
            c = aux->info;
            printf("I: %d \tP1(%03.0f,%03.0f)\tRaio:%03.0f\tCor(%03.0f,%03.0f,%03.0f)\n", i, c->x1,c->y1,c->raio, c->color.r, c->color.g,c->color.b);
            break;
        default:
            printf("\n\nERRO - Tipo n�o Identificado.\n\n");
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
void addRec(LGEN** lst, float x1,float y1, float x2, float y2, float r,float g, float b, float thickness)
{
    /**Aloca espa�o do retangulo**/
    REC* newRec = (REC*) malloc(sizeof(REC));
    if(newRec == NULL) exit(EXIT_FAILURE); /** Retorna msg caso de falha **/
    newRec->x1 = x1;
    newRec->x2 = x2;
    newRec->y1 = y1;
    newRec->y2 = y2;
    newRec->color.r = r;
    newRec->color.g = g;
    newRec->color.b = b;
    newRec->thickness = thickness;

    /**Aloca espa�o para lista**/
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
* @Parameters  : LGEN* lst, ponto, raio, cor e espessura da borda
********************************************************************************/
void addCir(LGEN** lst, float x1,float y1, float raio, float r,float g, float b, float thickness)
{
    /**Aloca espa�o do Circulo**/
    CIRC* newCirc = (CIRC*) malloc(sizeof(CIRC));
    if(newCirc == NULL) exit(EXIT_FAILURE); /** Retorna msg caso de falha **/
    newCirc->x1 = x1;
    newCirc->y1 = y1;
    newCirc->raio = raio;
    newCirc->color.r = r;
    newCirc->color.g = g;
    newCirc->color.b = b;
    newCirc->thickness = thickness;

    /**Aloca espa�o para lista**/
    LGEN* newList = (LGEN*) malloc(sizeof(LGEN));
    if(newList == NULL) exit(EXIT_FAILURE); /** Retorna msg caso de falha **/
    newList->info = newCirc;
    newList->tipo = cir;
    newList->next = *lst;
    *lst = newList;
}

/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 06/04/2015
* @Description : Calcula area de cada elemento da lista
* @Parameters  : LGEN* lst
********************************************************************************/
void calcArea(LGEN* lst)
{
    LGEN* aux = lst;
    REC *r = (REC*) aux->info;
    CIRC *c = (CIRC*) aux->info;
    float area;
    int i;

     while(aux != NULL){
        i++;
        switch(aux->tipo){
        case ret:
            r = aux->info;
            area = (r->x2-r->x1)*(r->y2-r->y1);
            printf("Area do elemento %d eh: %.02f",i,area);
            break;
        case cir:
            c = aux->info;
            area = 3.14*(c->raio*c->raio);
            printf("Area do elemento %d eh: %.02f",i,area);
            break;
        default:
            printf("\n\nERRO - Tipo n�o Identificado.\n\n");
            break;
        }

    }
}
/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 06/04/2015
* @Description : Desenha cada elemento da lista
* @Parameters  : LGEN* lst, char padrao
********************************************************************************/
void desenha(LGEN* lst, char padrao)
{
    LGEN* aux = lst;
    REC *r = NULL;
    CIRC *c = NULL;
    int i=0;
    printf("----------------------------------------------------------\n");
    while(aux != NULL){
        i++;
        al_init_primitives_addon();
        switch(aux->tipo){
        case ret:
            r = aux->info;
            if(padrao == contornoRedondo){
                al_draw_rectangle(r->x1, r->y1, r->x2,r->y2, al_map_rgb(r->color.r,r->color.g, r->color.b), r->thickness);
            }else if(padrao == contorno){
                al_draw_rounded_rectangle(r->x1, r->y1, r->x2,r->y2,3,3, al_map_rgb(r->color.r,r->color.g, r->color.b), r->thickness);
            }else if(padrao == preenchimentoRedondo){
                al_draw_filled_rounded_rectangle(r->x1, r->y1, r->x2,r->y2,3,3, al_map_rgb(r->color.r,r->color.g, r->color.b));
            }else{
                al_draw_filled_rectangle(r->x1, r->y1, r->x2,r->y2,al_map_rgb(r->color.r,r->color.g, r->color.b));
            }
            break;
        case cir:
            c = aux->info;
            if(padrao == contornoRedondo || padrao == contorno){
                al_draw_circle(c->x1, c->y1, c->raio, al_map_rgb(c->color.r,c->color.g, c->color.b), c->thickness);
            }else{
                al_draw_filled_circle(c->x1, c->y1, c->raio,al_map_rgb(c->color.r,c->color.g, c->color.b));
            }
            break;
        default:
            printf("\n\nERRO - Tipo n�o Identificado.\n\n");
            break;
        }
        aux = aux->next;
    }
}
