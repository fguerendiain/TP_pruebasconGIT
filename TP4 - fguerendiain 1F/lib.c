#include <stdio.h>
#include <stdlib.h>
#include "userInputOutput.h"
#include "arrayList.h"
#include "screenSystemShow.h"
#include "lib.h"

#define DB_FILE "notesDatabase.bin"
#define DB_BKFILE "bakNotesDataBase.txt"

#define AGREGAR 1 //a) Indice //b) Automatico\n"
#define MODIFICAR 2
#define ELIMNOTA 3
#define ELIMCUAD 4
#define CANTNOTAS 5
#define BUSCAR 6 //a) Indice //b) Titulo
#define EXPORTAR 7 //a) Completo //b) Parcial
#define SALIR 8


/** \brief Excecute option menu
 * \param (menuOption) int with user selection
 * \param (pNotesList) ArrayList
 * \param (Note) struct Memo type
 * \return [0] case of EXIT
 */

int runFunctionMenu(int menuOption,ArrayList *pNotesList, Memo* Note)
{
    switch(menuOption)
    {
        case AGREGAR :
        {
            cleanScreen();
            printAwesomeMenu("1) Indice\n2) Automatico\n\n");
            getUserInputInt(&menuOption,1,2,"Elija una opcion del menu:\n\n","Por favor ingrese una opcion valida:\n\n",0);
            addNote(pNotesList,Note,menuOption);
            pauseScreen();
        }
        break;

        case MODIFICAR :
        {
            cleanScreen();
            modifyNote(pNotesList,Note);
            pauseScreen();
        }
        break;

        case ELIMNOTA :
        {
            cleanScreen();
            removeNote(pNotesList,Note);
            pauseScreen();
        }
        break;

        case ELIMCUAD :
        {
            cleanScreen();
            pNotesList->clear(pNotesList);
            printf("Se eliminaron todas las notas\n\n");
            pauseScreen();
        }
        break;

        case CANTNOTAS :
        {
            cleanScreen();
            printf("%d notas cargadas en el sistema\n\n",pNotesList->size);
            pauseScreen();
        }
        break;

        case BUSCAR :
        {
          cleanScreen();

          pauseScreen();
        }
        break;

        case EXPORTAR :
        {
          cleanScreen();

          pauseScreen();
        }
        break;

        case SALIR :
        {
            pNotesList->deleteArrayList(pNotesList);
            exportToDataBaseFile(pNotesList,Note);
            return 0;
        }
        break;

    }
    return 1;
}



/** \brief remove Note on spcified index
 * \param (menuOption) int with user selection
 * \param (Note) struct Memo type
 * \return
 *
 */

int removeNote(ArrayList *pNotesList, Memo* Note)
{
    if(pNotesList == NULL)return -1;
    if(Note == NULL)return -1;

    int auxIndex = 0;
    int ret= 0;

    if(pNotesList->isEmpty !=1)
    {
        getUserInputInt(&auxIndex,0,pNotesList->size,"Ingrese el indice de la Nota a eliminar:\n\n","Por favor ingrese un indice valido:\n\n",0);
        ret = pNotesList->remove(pNotesList,auxIndex);
        if(ret != 0)
        {
            printf("Indice invalido, la nota no fue eliminada\n\n");
        }
        else
        {
            printf("La nota fue eliminada con exito\n\n");
        }
    }
    return 0;
}

/** \brief modify Note on spcified index
 * \param (menuOption) int with user selection
 * \param (Note) struct Memo type
 * \return
 *
 */

int modifyNote(ArrayList *pNotesList, Memo* Note)
{
    if(pNotesList == NULL)return -1;
    if(Note == NULL)return -1;

    char auxTitle[15]; //nombre de nota
    char auxTextBox[2500]; //cuerpo de nota
    int auxIndex = 0;

    if(pNotesList->isEmpty !=0)
    {
        getUserInputInt(&auxIndex,0,pNotesList->size,"Ingrese el indice de la nueva Nota:\n\n","Por favor ingrese un indice valido:\n\n",0);
        getUserInputString(auxTitle,1,15,"Ingrese el nuevo titulo de la nota:\n\n","Por favor, ingrese un titulo valido:\n\n",4000,0);
        getUserInputString(auxTextBox,1,2500,"Escriba su nota:\n\n","Ingrese una nota valida:\n\n",4000,0);

        Note->title = auxTitle;
        Note->textBox = auxTextBox;

        pNotesList->set(pNotesList,auxIndex,Note);
    }
    return 0;
}


/** \brief add new Note on spcified index or last index
 * \param (menuOption) int with user selection
 * \param (pNotesList) ArrayList
 * \param (Note) struct Memo type
 * \return
 *
 */

int addNote(ArrayList *pNotesList, Memo* Note,int userMenuOption)
{
    if(pNotesList == NULL)return -1;
    if(Note == NULL)return -1;
    if(userMenuOption != 1 && userMenuOption != 2)return -1;

    char auxTitle[15]; //nombre de nota
    char auxTextBox[2500]; //cuerpo de nota
    int auxIndex = 0;
    int ret= 0;

    getUserInputString(auxTitle,1,15,"Ingrese el titulo de la nota:\n\n","Por favor, ingrese un titulo valido:\n\n",4000,0);
    getUserInputString(auxTextBox,1,2500,"Escriba su nota:\n\n","Ingrese una nota valida:\n\n",4000,0);

    Note->title = auxTitle;
    Note->textBox = auxTextBox;

    if(userMenuOption == 2)
    {
        pNotesList->add(pNotesList,Note);
    }
    if(userMenuOption == 1)
    {
        ret = getUserInputInt(&auxIndex,0,pNotesList->size,"Ingrese el indice de la nueva Nota:\n\n","Por favor ingrese un indice valido:\n\n",3);
        if(ret != 0 && pNotesList->isEmpty !=0)
        {
            pNotesList->add(pNotesList,Note);
        }
        else
        {
            pNotesList->push(pNotesList,auxIndex,Note);
        }
    }

    return 0;
}

/** \brief Import DataBase from archive to memory
 * \param (pNotesList) ArrayList
 * \param (Note) struct Memo type
 * \return [-1] can't import [0] succeed
 */
int importDB(ArrayList *pNotesList, Memo* Note)
{
    if(pNotesList == NULL)return -1;
    if(Note == NULL)return -1;

    FILE *dataBaseFile;

    dataBaseFile = fopen(DB_FILE, "rb");
    if(dataBaseFile == NULL)
    {
        return -1;
    }
    rewind(dataBaseFile);
    while(!feof(dataBaseFile))
    {
        fread(Note, sizeof(Memo),1,dataBaseFile);
        pNotesList->add(pNotesList,Note);
    }
    fclose(dataBaseFile);
    return 0;
}


/** \brief Export DataBase from memory to archive
 * \param (pNotesList) ArrayList
 * \param (Note) struct Memo type
 * \return [-1] can't import [0] succeed
 */
int exportToDataBaseFile(ArrayList *pNotesList, Memo* Note)
{
    if(pNotesList == NULL)return -1;
    if(Note == NULL)return -1;

    FILE *dataBaseFile;

    dataBaseFile = fopen(DB_FILE, "wb");

    if(dataBaseFile == NULL)
    {
        printf("Error al intentar escribir en la base de datos\n");
        return -1;
    }
    fwrite(pNotesList->pElements, sizeof(Memo),pNotesList->size,dataBaseFile);
    fclose(dataBaseFile);

    return 0;
}
