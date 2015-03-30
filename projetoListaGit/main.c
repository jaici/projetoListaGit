#include "list.h"

/**FUNCAO PRINCIPAL*/
int main()
{
    Lst *list = init();
    //char nameFile[] = "lista.txt";

    //printf("Tamanho do elemento: %d\n", sizeof(list));

    insertOrder(&list,61);
    insertOrder(&list,27);
    insertOrder(&list,123);
    insertOrder(&list,43);
    insertOrder(&list,25);
    insertOrder(&list,6);
    insertOrder(&list,7);
    insertOrder(&list,3);
    insertOrder(&list,4);
    insertOrder(&list,5);

    printList(list);

    printRecursive(list);

    /**Inserir dados a partir de um arquivo**/
    //list = leArquivo(nameFile, list);
    //imprime(list);
    /**Buscar valor**/
    // printf("Valor Pesquisado: 18\tPosicao: %p\n",searchList(list,18));
    /**Remover valor do array**/
    //removeList(list,121);
    //printList(list);
    /**Inserir ordenado**/
    //insertOrder();

    freeMemory(list);
    return 0;
}
