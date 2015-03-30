#include "list.h"

/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 16/03/2015
* @Description : Inicializa Lista
* @Return      : NULL
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
    /** O retorno ira quebrar a licagao do primeiro ponteiro com
        o NULL pois ir� armazenar o endere�o do dado inserido.**/
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
    FILE *fp = fopen(fileName,"r");
    int data = 0;

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
    *lst = insertList(data, *lst);
}
/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 20/03/2015
* @Description : Busca um dado na lista, retorna seu endere�o
* @Parameters  : Lista* lst, int valor
* @Return      : Lista*
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
* @Parameters  : Lista*
********************************************************************************/
void removeList(Lst* lst, int data)
{
    Lst* aux;
    Lst* prev;

    for(aux=lst;aux!= NULL;aux=aux->next){
        if(aux->info == data){
           prev->next = aux->next;
           break;
        }
        prev = aux; // lista anterior
    }
    lst = prev;
}
/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 16/03/2015
* @Description : Libera espa�o da mem�ria ocuplado pela lista
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
    Lst* prev = NULL;                           /**ARMAZENA LISTA ANTERIOR DA LISTA**/

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