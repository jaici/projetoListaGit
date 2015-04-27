#include "list.h"
//#include "listAllegro.h"

/**FUNCAO PRINCIPAL*/
int main()
{
    Lst *lista = NULL; /** INICIALIZA LISTA **/

    /** INSERE DADOS NA LISTA **/
    insertList2(&lista,235);
    insertList2(&lista,91);
    insertOrder(&lista,11);
    insertOrder(&lista,56);
    insertOrder(&lista,111);
    printList(lista);

    removeList(lista,56);
    printList(lista);
    freeMemory(lista);
    return 0;
}
