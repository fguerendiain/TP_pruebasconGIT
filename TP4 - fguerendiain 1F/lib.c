#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userInputOutput.h"
#include "arrayList.h"
#include "screenSystemShow.h"
#include "lib.h"

#define DB_FILE "notesDatabase.bin"
#define BKP_COMFILE "bakNotesComplete.txt"
#define BKP_PARTFILE "bakNotesPartial.txt"

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
            removeNote(pNotesList);
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
            printf("%d notas cargadas en el sistema\n\n",pNotesList->len(pNotesList)+1);
            pauseScreen();
        }
        break;

        case BUSCAR :
        {
            cleanScreen();
            printAwesomeMenu("1) Indice\n2) Titulo\n\n");
            getUserInputInt(&menuOption,1,2,"Elija una opcion del menu:\n\n","Por favor ingrese una opcion valida:\n\n",0);
            seekNote(pNotesList,menuOption);
            pauseScreen();
        }
        break;

        case EXPORTAR :
        {
            cleanScreen();
            printAwesomeMenu("1) Completo\n2) Parcial\n\n");
            getUserInputInt(&menuOption,1,2,"Elija una opcion del menu:\n\n","Por favor ingrese una opcion valida:\n\n",0);
            exportBakupToFile(pNotesList,menuOption);
            pauseScreen();
        }
        break;

        case SALIR :
        {
            pNotesList->deleteArrayList(pNotesList);
   //         exportToDataBaseFile(pNotesList);
            return 0;
        }
        break;
    }
    return 1;
}

/** \brief export Notes to txt file, complete or parcial
 * \param (menuOption) int with user selection
 * \param (pNotesList) ArrayList
 * \return
 */
int exportBakupToFile(ArrayList *pNotesList,int userMenuOption)
{
    if(pNotesList == NULL)return -1;
    if(userMenuOption != 1 && userMenuOption != 2)return -1;

    FILE *bkpFile;
    ArrayList* pNotesBkp = NULL;
    Memo *AuxNote = NULL;
    int to = 0;
    int from = 0;
    int i;

    if(pNotesList->isEmpty(pNotesList)!=0)
    {
        printf("No existen notas cargadas\n\n");
        pauseScreen();
        return -1;
    }

    if(userMenuOption == 1)
    {
        pNotesBkp = pNotesList->clone(pNotesList);
    }
    else
    {
        getUserInputInt(&to,0,pNotesList->size,"Ingrese el indice desde:\n\n","Por favor ingrese un indice valido:\n\n",0);
        getUserInputInt(&from,to,pNotesList->size,"Ingrese el indice hasta:\n\n","Por favor ingrese un indice valido:\n\n",0);
        pNotesBkp = pNotesList->subList(pNotesList);
    }

    bkpFile = fopen(BKP_COMFILE, "w");

    if(bkpFile == NULL)
    {
        printf("Error al intentar escribir en la base de datos\n");
        return -1;
    }

    //el quilombo esta apartir de aca//////////////////////////////////////////////////////////
    for(i=0 ; i<pNotesBkp->size ; i++)
    {
        AuxNote = pNotesBkp->pElements[i];
        fwrite(AuxNote, sizeof(Memo),pNotesBkp->size-1,bkpFile);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////
    fclose(bkpFile);

    return 0;
}

/** \brief Search Note by index or title
 * \param (menuOption) int with user selection
 * \param (pNotesList) ArrayList
 * \return
 */
int seekNote(ArrayList *pNotesList, int userMenuOption)
{
    if(pNotesList == NULL)return -1;
    if(userMenuOption != 1 && userMenuOption != 2)return -1;

    int auxIndex;
    char auxTitle[15];
    int i;

    Memo* AuxNote;

    if(pNotesList->isEmpty!=0)
    {
        if(userMenuOption == 1)//a) Indice //b) Titulo
        {
            getUserInputInt(&auxIndex,0,pNotesList->size,"Ingrese el indice de la Nota a buscar:\n\n","Por favor ingrese un indice valido:\n\n",0);
        }
        else
        {
            getUserInputString(auxTitle,1,15,"Ingrese el titulo de la nota a buscar:\n\n","Por favor, ingrese un titulo valido:\n\n",4000,0);
            for(i=0 ; i < pNotesList->size ; i++)
            {
                AuxNote = pNotesList->pElements[i];
                if(strcmp(AuxNote->title,auxTitle)==0);
                {
                    auxIndex = pNotesList->indexOf(pNotesList,AuxNote);
                    break;
                }
            }
        }

        AuxNote = pNotesList->pElements[auxIndex];

        if(AuxNote!=NULL)
        {
            stringSetCase(AuxNote->title,3);
            stringSetCase(AuxNote->textBox,3);
            cleanScreen();
            printf("Nota %d\t%s\n\n\t%s\n\n",auxIndex,AuxNote->title,AuxNote->textBox);
        }
        else
        {
            printf("La nota no existe");
        }

    }
    return 0;
}

/** \brief remove Note on spcified index
 * \param (menuOption) int with user selection
 * \return
 */
int removeNote(ArrayList *pNotesList)
{
    if(pNotesList == NULL)return -1;

    int auxIndex = 0;
    void* ret= NULL;

    if(pNotesList->isEmpty(pNotesList) != 1)
    {
        getUserInputInt(&auxIndex,0,pNotesList->size,"Ingrese el indice de la Nota a eliminar:\n\n","Por favor ingrese un indice valido:\n\n",0);
        ret = pNotesList->pop(pNotesList,auxIndex);
        if(ret == NULL)
        {
            printf("Indice invalido, la nota no fue eliminada\n\n");
        }
        else
        {
            printf("La nota fue eliminada con exito\n\n");
        }
    }
    else
    {
        printf("No existen notas cargadas\n\n");
    }
    return 0;
}

/** \brief modify Note on spcified index
 * \param (menuOption) int with user selection
 * \param (Note) struct Memo type
 * \return
 */
int modifyNote(ArrayList *pNotesList, Memo* Note)
{
    if(pNotesList == NULL)return -1;
    if(Note == NULL)return -1;

    char auxTitle[15]; //nombre de nota
    char auxTextBox[2500]; //cuerpo de nota
    int auxIndex = 0;

    if(pNotesList->isEmpty(pNotesList) !=0)
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
        if(ret != 0 && pNotesList->isEmpty(pNotesList) !=0)
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
int exportToDataBaseFile(ArrayList *pNotesList)
{
    if(pNotesList == NULL)return -1;

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
