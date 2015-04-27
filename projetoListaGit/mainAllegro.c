//#include "list.h"
#include "listAllegro.h"

/**FUNCAO PRINCIPAL*/
int main()
{
    int width = 640;
	int height = 480;
    ALLEGRO_DISPLAY *display = NULL; /**Inicializa ponteiro**/
    if(!al_init())	//initialize Allegro
		return -1;
	display = al_create_display(width, height);			//create our display object
	if(!display)										//test display object
		return -1;

    /**INICIALIZA LISTA**/
    LGEN *list = initList();
    addRec(&list,2,2,7,8,122,12,22,1);
    addRec(&list,5,9,37,81,0,12,255,3);
    addRec(&list,45,25,117,118,122,12,22,1);
    addCir(&list,66,79,122,12,255,34,3);
    addCir(&list,300,450,24,255,255,0,1);
    addRec(&list,120,240,70,80,122,12,22,1);
    addRec(&list,15,15,30,60,255,255,22,5);
    /**monta buffer para desenhar na tela**/
    desenha(list,preenchimentoRedondo);
    //desenha(list,contorno);

    printListGen(list);
    al_flip_display();
	al_rest(5.0);
	al_destroy_display(display);
    freeMemoryRec(list);
    return 0;
}
