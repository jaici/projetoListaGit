#include "list.h"
//#include "listAllegro.h"

/**FUNCAO PRINCIPAL*/
int main()
{
    DL *listaDupla = NULL; /** INICIALIZA LISTA **/
    DL *listSearch = NULL;

    /** INSERE DADOS NA LISTA **/
    insertDuoList(&listaDupla,5);
    insertDuoList(&listaDupla,9);
    insertDuoList(&listaDupla,11);
    insertDuoList(&listaDupla,56);
    insertDuoList(&listaDupla,111);
    printDuoList(listaDupla);


    listSearch = searchDuoList(listaDupla,11);
    removeDuoList(&listSearch,11);
    printDuoList(listSearch);
    freeMemoryDuoList(listaDupla);
    freeMemoryDuoList(listSearch);
    return 0;
}
