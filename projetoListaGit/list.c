#include "list.h"

/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 16/03/2015
* @Description : Inicializa Lista
* @Return      : Lst*
********************************************************************************/
Lst* init (void)
{
    return NULL;
}

/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 16/03/2015
* @Description : Insere dados na lista
* @Parameters  : int dado, Lista* lst
* @Return      : Lista*
********************************************************************************/
Lst* insertList(int data, Lst* lst)
{
    Lst* newLst = (Lst*) malloc(sizeof(Lst));
    if(newLst == NULL) exit(EXIT_FAILURE); /** Retorna msg caso de falha **/
    newLst->info = data;
    newLst->next = lst;
    return newLst;
    /** O retorno ira quebrar a ligacao do primeiro ponteiro com
        o NULL pois irá armazenar o endereço do dado inserido.**/
}
/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 16/03/2015
* @Description : le dados do arquivo e insere na lista
* @Parameters  : char nomeArquivo, Lista* lst
* @Return      : Lista*
********************************************************************************/
Lst* fileReader(char fileName[], Lst* lst)
{
    int data = 0;
    FILE *fp = fopen(fileName,"r");

    if(fp == NULL){
       printf("ERRO ao abrir arquivo.");
       exit(1);
    }else{
        while(!feof(fp)){
          fscanf(fp,"%d",&data);
          lst = insertList(data,lst);
        //  imprime(lst);
        }
    }
    return lst;
}
/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 21/03/2015
* @Description : inserir dados na lista sem precisar de retorno.
* @Parameters  : Lista*
********************************************************************************/
void insertList2(Lst** lst, int data)
{
    Lst* newLst = (Lst*) malloc(sizeof(Lst));
    if(newLst == NULL) exit(EXIT_FAILURE); /** Retorna msg caso de falha **/
    newLst->info = data;
    newLst->next = (*lst);
    (*lst) = newLst;
}
/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 20/03/2015
* @Description : Busca um dado na lista, retorna seu endereço
* @Parameters  : Lista* lst, int valor
* @Return      : Lista* lst ou Null caso nao encontrado elemento
********************************************************************************/
Lst* searchList(Lst* lst, int data)
{
    Lst* aux;
    for(aux=lst;aux!= NULL;aux=aux->next){
        if(aux->info == data){
            return aux;
        }

    }
    return NULL; /** SE NAO ENCONTROU ELEMENTO **/
}
/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 16/03/2015
* @Description : imprime os dados da lista
* @Parameters  : Lista* lst
********************************************************************************/
void printList(Lst* lst)
{
    Lst* aux = lst;
    int i=0;
    printf("---------------------------\n");
    while(aux != NULL){
        i++;
        printf("Indice: %d \tEndereco: %p Dado: %d \tProximo: %p\n", i, aux, aux->info, aux->next);
        aux = aux->next;
    }
}
/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 21/03/2015
* @Description : remover e liberar a memoria do ponteiro da lista encontrada
* @Parameters  : Lista*, int data
********************************************************************************/
void removeList(Lst* lst, int data)
{
    Lst* aux = lst;
    Lst* prev;

    while (aux!= NULL && aux->info != data){
         prev = aux;
         aux  = aux->next;
    }
    /** SE NAO ENCONTROU O ELEMENTO A REMOVER, LISTA CONTINUA COMPLETA **/
    if(prev == NULL)
        lst = aux->next;
    else
        prev->next = aux->next;   /** SE ENCONTROU O ELEMENTO A REMOVER,
                                      ELEMENTO ANTERIOR APONTA PARA O PROXIMO ELEMENTO DO ENCONTRADO **/

    free(aux); /** LIBERA MEMÓRIA **/
}
/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 16/03/2015
* @Description : Libera espaço da memória ocupado pela lista
* @Parameters  : Lista* lst
********************************************************************************/
void freeMemory(Lst* lst)
{
    Lst* p = lst;
    while(p!=NULL){
        Lst* t = p->next;   /** GUARDA REFERENCIA PARA O PROXIMO BLOCO **/
        free(p);            /** LIBERA MEMORIA DESTA LISTA             **/
        p = t;              /** FAZ COM QUE P APONTE PARA O PROXIMO    **/
    }
}

/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 27/03/2015
* @Description : Insere os dados de forma crescente
* @Parameters  : Lista** lst, int data
********************************************************************************/
void insertOrder(Lst** lst, int data)
{
    Lst* newLst = (Lst*) malloc(sizeof(Lst));
    if(newLst == NULL) exit(EXIT_FAILURE);      /** Retorna msg caso de falha **/

    Lst* aux=*lst;                           /**PERCORRER LISTA**/
    Lst* prev = NULL;                        /**ARMAZENA ELEMENTO ANTERIOR DA LISTA**/

    newLst->info = data;
    while(aux != NULL && aux->info < data){
        prev = aux;
        aux=aux->next;
    }
    if(prev == NULL){
        newLst->next=*lst;
        *lst = newLst;
    }else{
        newLst->next = prev->next;
        prev->next = newLst;
    }
}
/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 29/03/2015
* @Description : Imprime lista recursiva
* @Parameters  : Lista* lst
********************************************************************************/
void printRecursive(Lst* lst)
{
    if(lst == NULL)
        return;
    printf("\nINFO: %d",lst->info);
    printRecursive(lst->next);
}
//------------------------------------------------------------------------------
// LISTAS DUPLAMENTE ENCADEADAS
//------------------------------------------------------------------------------
/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 10/04/2015
* @Description : Insere dado na lista dupla
* @Parameters  : DL** dl, int data
********************************************************************************/
void insertDuoList(DL** dl, int data)
{
    DL* newList = (DL*) malloc(sizeof(DL));
    if(newList == NULL) exit(EXIT_FAILURE); /** Retorna msg caso de falha **/
    newList->info = data;
    newList->next = (*dl);
    newList->prev = NULL;
    /** verifica se lista não está vazia **/
    if ((*dl) != NULL)
        (*dl)->prev= newList;

   (*dl) = newList;
}
/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 10/04/2015
* @Description : Busca dado na lista dupla
* @Parameters  : DL** dl, int data
********************************************************************************/
DL* searchDuoList(DL* dl, int data)
{
    DL* aux = NULL;
    for(aux = dl; aux!=NULL; aux = aux->next){
        if(aux->info == data){
            return aux;
        }
    }
    return NULL;
}
/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 10/04/2015
* @Description : Remove dado na lista dupla
* @Parameters  : DL** dl, int data
********************************************************************************/
void removeDuoList(DL** dl, int data)
{
   DL* aux = searchDuoList((*dl),data);
   if (aux == NULL)
          return;
   /* não achou o elemento: retorna lista inalterada */
   /* retira elemento do encadeamento */
   if ((*dl) == aux)
         (*dl) = aux->next;
   else
         aux->prev->next = aux->next;
   if (aux->next != NULL)
         aux->next->prev = aux->prev;
   free(aux);
}
/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 10/04/2015
* @Description : Imprimir dado da lista dupla
* @Parameters  : DL* dl
********************************************************************************/
void printDuoList(DL* dl)
{
    DL* aux = dl;
    int i=0;
    printf("---------------------------\n");

    if(aux == NULL){
        printf("\nLista Vazia\n");
    }
    while(aux != NULL){
        i++;
        printf("Indice: %d \tEnd: %p Dado: %3d \tAnt: %p\tProx: %p\n", i, aux, aux->info, aux->prev,aux->next);
        aux = aux->next;
    }
}
/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 10/04/2015
* @Description : Imprimir dado da lista dupla
* @Parameters  : DL* dl
********************************************************************************/
void freeMemoryDuoList(DL* dl)
{
    DL* aux = dl;
    while(aux!=NULL){
        DL* temp = aux->next;   /** GUARDA REFERENCIA PARA O PROXIMO BLOCO **/
        free(aux);              /** LIBERA MEMORIA DESTA LISTA             **/
        aux = temp;             /** FAZ COM QUE P APONTE PARA O PROXIMO    **/
    }
}
