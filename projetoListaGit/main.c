#include "list.h"
#include "listAllegro.h"

/**FUNCAO PRINCIPAL*/
int main()
{
    /**INICIALIZA LISTA**/
    LGEN *list = initList();
    addRec(&list,2,2,7,8,122,12,22,1);
    addRec(&list,5,9,37,81,0,12,255,3);
    addCir(&list,0,0,24,255,255,0,1);
    addRec(&list,12,24,7,8,122,12,22,1);

    printListGen(list);

    freeMemoryRec(list);
    return 0;
}
