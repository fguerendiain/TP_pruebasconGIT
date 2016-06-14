/**************************************************************************************************************
***************************************************************************************************************
****    LABORATORIO I
****    DIVISION 1#F
****    ALUMNO: GUERENDIAIN, FRANCO JAVIER
****
****    TRABAJO PRACTICO #4
****
****    FECHA DE ENTREGA - 15/06/2016
****
***************************************************************************************************************
****
****     Etapa 1:
****             Se deberá desarrollar una biblioteca ArrayList.c y ArrayList.h la cual contendrá el tipo
****             de dato ArrayList, tal que cumpla con la especificación del documento, con las funciones
****             mínimas requeridas.
****
****     Etapa 2:
****             Realizar una aplicación que dé uso del ArrayList (usando todas las funciones) y que
****             permita interactuar con estructuras de datos almacenadas en archivos.
****
***************************************************************************************************************/


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


    importDB(pNotesList);

    do
    {
        printAwesomeMenu("*****************************************************\n"
                         "****************  NOTE MANNAGER 2016  ***************\n"
                         "*****************************************************\n\n"
                         "\t[1] - AGREGAR NOTA\n\t\t[1.1] Indice\n\t\t[1.2] Automatico\n" //Utiliza: add | push
                         "\t[2] - MODIFICAR NOTA\n" //Utiliza: set | is_Empty
                         "\t[3] - ELIMINAR NOTA\n" //Utiliza: pop->remove->contract | is_Empty
                         "\t[4] - ELIMINAR CUADERNO\n" //Utiliza: clear
                         "\t[5] - CANTIDAD DE NOTAS\n" //Utiliza: len
                         "\t[6] - BUSCAR NOTA\n\t\t[6.1] Indice\n\t\t[6.2] Titulo\n" //Utiliza: indexOf | is_Empty
                         "\t[7] - ORDENAR ALFABETICAMENTE Y EXPORTAR NOTAS A TXT\n\t\t[7.1] Completo\n\t\t[7.2] Parcial\n" //Utiliza: ***sort // al_clone // al_sublist //al_is_Empty
                         "\t[8] - SALIR\n\n");

        getUserInputInt(&userMenuOption,1,8,"Elija una opcion del menu:\n\n","Por favor ingrese una opcion valida:\n\n",0);
        exit = runFunctionMenu(userMenuOption,pNotesList);
    }
    while(exit);

    pNotesList->deleteArrayList(pNotesList);
    exportToDataBaseFile(pNotesList);

    return exit;
}


/*******************************************************************************************************
*****   DETALLE DE FUNCIONES DEL ARRAYLIST UTILIZADAS SEGUN MENU Y CORRESPONDIENTE FUNCION  ************
*****
*****   MAIN :
*****   [al_newArrayList - deleteArrayList]
*****
*****   AGREGAR :   addNote(pNotesList,menuOption);
*****   [isEmpty - len - add - push]
*****
*****   MODIFICAR : modifyNote(pNotesList);
*****   [isEmpty - len - set]
*****
*****   ELIMINAR NOTA : removeNote(pNotesList);
*****   [isEmpty - len - pop]
*****
*****   ELIMINAR CUADERNO : deleteAllNotes(pNotesList);
*****   [isEmpty - clear]
*****
*****   CANTIDAD DE NOTAS : showHowManyNotes(pNotesList);
*****   [isEmpty - len]
*****
*****   BUSCAR : seekNote(pNotesList,menuOption);
*****   [isEmpty - len - get - indexOf]
*****
*****   EXPORTAR :  exportBakupToFile(pNotesList,menuOption);
*****   [isEmpty - sort - clone - len - sublist - get]
*****
************************************************************************************************************
*****
*****   al_newArrayList
*****   deleteArrayList
*****   isEmpty
*****   len
*****   add
*****   push
*****   set
*****   pop
*****   clear
*****   get
*****   indexOf
*****   sort
*****   clone
*****   sublist
