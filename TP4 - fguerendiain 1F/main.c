#include <stdio.h>
#include <stdlib.h>
#include "userInputOutput.h"
#include "lib.h"
#include "arrayList.h"


int main()
{
    int exit = 1;
    int userMenuOption = 0;
    ArrayList* pNotesList;
    Memo* Note[1];

    pNotesList = al_newArrayList();

    importDB(pNotesList,Note);

    do
    {
        printAwesomeMenu("\tNOTE MANNAGER 2016\n\n"
                         "1 - AGREGAR NOTA\n\ta) Indice\n\tb) Automatico\n" //al_add // push //sort //verificar si el indice esta vacio y preguntar para continuar //nota = pelement
                         "2 - MODIFICAR NOTA\n" //al_set //al_is_Empty //sort
                         "3 - ELIMINAR NOTA\n" //al_pop //al_remove //al_is_Empty
                         "4 - ELIMINAR CUADERNO\n" //al_delete //cuaderno == array list
                         "5 - CANTIDAD DE NOTAS\n" //al_len
                         "6 - BUSCAR NOTA\n\ta) Indice\n\tb) Titulo\n" //sort //al_get //al_contains //indexOf //al_is_Empty
                         "7 - EXPORTAR NOTAS A TXT\n\ta) Completo\n\tb) Parcial\n" //sort // al_clone // al_sublist //al_is_Empty //fopen backup.dat
                         "8 - SALIR\n\n" //exit=0 //fopen wr //al_clear
                         );

        getUserInputInt(&userMenuOption,1,8,"Elija una opcion del menu\n","Por favor ingrese una opcion valida\n",0);
        exit = runFunctionMenu(userMenuOption,pNotesList,Note);
    }
    while(exit);

    return exit;
}
