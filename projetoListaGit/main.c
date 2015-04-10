#include "list.h"
#include "listAllegro.h"

/**FUNCAO PRINCIPAL*/
int main()
{
    DL *listaDupla = NULL; /** INICIALIZA LISTA **/

    /** INSERE DADOS NA LISTA **/
    insertDuoList(&listaDupla,5);
    insertDuoList(&listaDupla,9);
    insertDuoList(&listaDupla,11);
    insertDuoList(&listaDupla,56);
    insertDuoList(&listaDupla,111);
    printDuoList(listaDupla);

    removeDuoList(&listaDupla,11);

    printDuoList(listaDupla);
    freeMemoryDuoList(listaDupla);
    return 0;
}
