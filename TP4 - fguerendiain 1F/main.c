#include <stdio.h>
#include <stdlib.h>
#include "screenSystemShow.h"
#include "userInputOutput.h"
#include "lib.h"
#include "arrayList.h"


int main()
{
    int exit = 1;
    int userMenuOption = 0;

    ArrayList* pNotesList;
    pNotesList = al_newArrayList();

    Memo* Note;
    Note = (Memo*)malloc(sizeof(Memo)*1);

 //   importDB(pNotesList,Note);

    do
    {
        printAwesomeMenu("\tNOTE MANNAGER 2016\n\n"
                         "1 - AGREGAR NOTA\n\t[1.1] Indice\n\t[1.2] Automatico\n" //Utiliza: add | push
                         "2 - MODIFICAR NOTA\n" //Utiliza: set | is_Empty
                         "3 - ELIMINAR NOTA\n" //Utiliza: pop->remove->contract | is_Empty
                         "4 - ELIMINAR CUADERNO\n" //Utiliza: clear
                         "5 - CANTIDAD DE NOTAS\n" //Utiliza: len
                         "6 - BUSCAR NOTA\n\t[1.1] Indice\n\t[1.2] Titulo\n" //Utiliza: indexOf | is_Empty
                         "7 - EXPORTAR NOTAS A TXT\n\t[1.1] Completo\n\t[1.2] Parcial\n" //Utiliza: ***sort // al_clone // al_sublist //al_is_Empty
                         "8 - SALIR\n\n"); //Utiliza: //fopen wr //al_clear

        getUserInputInt(&userMenuOption,1,8,"Elija una opcion del menu:\n\n","Por favor ingrese una opcion valida:\n\n",0);
        exit = runFunctionMenu(userMenuOption,pNotesList,Note);
    }
    while(exit);

    return exit;
}
