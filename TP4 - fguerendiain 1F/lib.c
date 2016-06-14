#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userInputOutput.h"
#include "arrayList.h"
#include "screenSystemShow.h"
#include "lib.h"

#define DB_FILE "notesDatabase.bin"
#define BKP_COMFILE "bakNotesComplete.txt"

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
int runFunctionMenu(int menuOption,ArrayList *pNotesList)
{
    switch(menuOption)
    {
        case AGREGAR :
        {
            cleanScreen();
            printAwesomeMenu("1) Indice\n2) Automatico\n\n");
            getUserInputInt(&menuOption,1,2,"Elija una opcion del menu:\n\n","Por favor ingrese una opcion valida:\n\n",0);
            addNote(pNotesList,menuOption);
            pauseScreen();
        }
        break;

        case MODIFICAR :
        {
            cleanScreen();
            modifyNote(pNotesList);
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
            deleteAllNotes(pNotesList);
            pauseScreen();
        }
        break;

        case CANTNOTAS :
        {
            cleanScreen();
            showHowManyNotes(pNotesList);
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
            return 0;
        }
        break;
    }
    return 1;
}

/** \brief Create a new Note
 * \return Memo* Return pointer to Note
 *
 */
Memo* newNote()
{
    Memo* auxNote = NULL;
    Memo* Note = malloc(sizeof(Memo));

    auxNote = Note;

    return auxNote;

}

/** \brief delete All Notes
 * \param (pNotesList) ArrayList
 * \return
 */
int deleteAllNotes(ArrayList *pNotesList)
{
    if(pNotesList==NULL)return -1;

    if(pNotesList->isEmpty(pNotesList)!=0)
    {
        printf("No existen notas cargadas\n\n");
    }
    else
    {
        pNotesList->clear(pNotesList);
        printf("Se eliminaron todas las notas\n\n");
    }
    return 0;
}

/** \brief show how many Notes exist
 * \param (pNotesList) ArrayList
 * \return
 */
int showHowManyNotes(ArrayList *pNotesList)
{
    if(pNotesList==NULL)return -1;

    if(pNotesList->isEmpty(pNotesList)!=0)
    {
        printf("No existen notas cargadas\n\n");
    }
    else
    {
        printf("%d notas cargadas en el sistema\n\n",pNotesList->len(pNotesList));
    }
    return 0;
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
    int to = 0;
    int from = 0;
    int i;
    ArrayList* pNotesBkp;
    pNotesBkp = al_newArrayList();
    Memo* Note = NULL;

    if(pNotesList->isEmpty(pNotesList)!=0)
    {
        cleanScreen();
        printf("No existen notas cargadas\n\n");
        return -1;
    }

    if(userMenuOption == 1)
    {
        pNotesBkp = pNotesList->clone(pNotesList);
        to = pNotesBkp->len(pNotesBkp);
    }
    else
    {
        cleanScreen();
        getUserInputInt(&from,0,pNotesList->len(pNotesList)-1,"Ingrese el indice desde:\n\n","Por favor ingrese un indice valido:\n\n",0);
        getUserInputInt(&to,from,pNotesList->len(pNotesList)-1,"Ingrese el indice hasta:\n\n","Por favor ingrese un indice valido:\n\n",0);
        pNotesBkp = pNotesList->subList(pNotesList,from,to);
    }

    bkpFile = fopen(BKP_COMFILE, "w");

    if(bkpFile == NULL)
    {
        printf("Error al intentar escribir en la base de datos\n");
        return -1;
    }

    pNotesBkp->sort(pNotesBkp,compareNotes(pNotesBkp->pElements,pNotesBkp->pElements),1);


    for(i=0 ; i<pNotesBkp->len(pNotesBkp) ; i++)
    {
        if(pNotesBkp->get(pNotesBkp,i)!=NULL)
        {
            Note = pNotesBkp->get(pNotesBkp,i);
            stringSetCase(Note->title,1);
            stringSetCase(Note->textBox,3);
            fprintf(bkpFile,"Titulo: --%s--\n",Note->title);
            fprintf(bkpFile,"  Nota: %s\n",Note->textBox);
            fprintf(bkpFile,"\n------------------------------------------\n\n");
        }
    }
    printf("Se exportaron las notas correctamente en "BKP_COMFILE"\n\n");
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

    int auxIndex=-1;
    char auxTitle[15];
    int i;

    Memo* AuxNote = NULL;

    if(pNotesList->isEmpty(pNotesList)!=0)
    {
    cleanScreen();
    printf("No existen notas cargadas\n\n");
    return -1;
    }

    if(userMenuOption == 1)//a) Indice //b) Titulo
    {
        getUserInputInt(&auxIndex,0,pNotesList->len(pNotesList),"Ingrese el indice de la Nota a buscar:\n\n","Por favor ingrese un indice valido:\n\n",0);
    }
    else
    {
        getUserInputString(auxTitle,1,15,"Ingrese el titulo de la nota a buscar:\n\n","Por favor, ingrese un titulo valido:\n\n",4000,0);
        for(i=0 ; i < pNotesList->len(pNotesList) ; i++)
        {
            AuxNote = pNotesList->get(pNotesList,i);
            if(strcmp(AuxNote->title,auxTitle)==0)
            {
                auxIndex = pNotesList->indexOf(pNotesList,AuxNote);
                break;
            }
        }
    }

    AuxNote = pNotesList->get(pNotesList,auxIndex);

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
        getUserInputInt(&auxIndex,0,pNotesList->len(pNotesList),"Ingrese el indice de la Nota a eliminar:\n\n","Por favor ingrese un indice valido:\n\n",0);
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
int modifyNote(ArrayList *pNotesList)
{
    if(pNotesList == NULL)return -1;

    char auxTitle[15]; //nombre de nota
    char auxTextBox[2500]; //cuerpo de nota
    int auxIndex = 0;

    Memo* Note;
    Note = (Memo*)malloc(sizeof(Memo));


    if(pNotesList->isEmpty(pNotesList)!=0)
    {
    cleanScreen();
    printf("No existen notas cargadas\n\n");
    return -1;
    }

    getUserInputInt(&auxIndex,0,pNotesList->len(pNotesList),"Ingrese el indice de la nueva Nota:\n\n","Por favor ingrese un indice valido:\n\n",0);
    getUserInputString(auxTitle,1,15,"Ingrese el nuevo titulo de la nota:\n\n","Por favor, ingrese un titulo valido:\n\n",4000,0);
    getUserInputString(auxTextBox,1,2500,"Escriba su nota:\n\n","Ingrese una nota valida:\n\n",4000,0);

    strcpy(Note->title,auxTitle);
    strcpy(Note->textBox,auxTextBox);

    pNotesList->set(pNotesList,auxIndex,Note);

    return 0;
}

/** \brief add new Note on spcified index or last index
 * \param (menuOption) int with user selection
 * \param (pNotesList) ArrayList
 * \param (Note) struct Memo type
 * \return
 *
 */
int addNote(ArrayList *pNotesList, int userMenuOption)
{
    if(pNotesList == NULL)return -1;
    if(userMenuOption != 1 && userMenuOption != 2)return -1;

    char auxTitle[15]; //nombre de nota
    char auxTextBox[2500]; //cuerpo de nota
    int auxIndex = 0;

    Memo* Note = newNote();
    if(Note == NULL)return -1;

    getUserInputString(auxTitle,1,15,"Ingrese el titulo de la nota:\n\n","Por favor, ingrese un titulo valido:\n\n",4000,0);
    getUserInputString(auxTextBox,1,2500,"Escriba su nota:\n\n","Ingrese una nota valida:\n\n",4000,0);

    strcpy(Note->title,auxTitle);
    strcpy(Note->textBox,auxTextBox);

    if(userMenuOption == 2)
    {
        pNotesList->add(pNotesList,Note);
    }
    if(userMenuOption == 1)
    {
        getUserInputInt(&auxIndex,0,pNotesList->len(pNotesList)-1,"Ingrese el indice de la nueva Nota:\n\n","Por favor ingrese un indice valido:\n\n",0);
        if(auxIndex < pNotesList->len(pNotesList))
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
int importDB(ArrayList *pNotesList)
{
    if(pNotesList == NULL)return -1;

    Memo* Note = newNote();
    FILE* dataBaseFile;
    int memoCount = -1;
    int i=0;

    dataBaseFile = fopen(DB_FILE, "rb");
    if(dataBaseFile == NULL)return -1;

    fread(&memoCount, sizeof(int), 1, dataBaseFile);

    if(memoCount == 0)return 0; //en caso que se hallan guardado 0 notas

//    if(memoCount==0)return 0;

/*  int memosToRead = 4;
    Memo memoBuffer[memosToRead];
    int batch = 0;

    while (memosToRead * batch <= memoCount){
        fread(&memoBuffer, sizeof(Memo), memosToRead, dataBaseFile);
        batch++;

        pNotesList->addAll(memoBuffer);
    }

    int memosLeft = memoCount - memosToRead * batch;
    fread(&memoBuffer, sizeof(Memo), memosLeft, dataBaseFile);
    pNotesList->addAll(memoBuffer);*/


    while(i<memoCount)
    {
        fread(Note, sizeof(Memo),1,dataBaseFile);
        pNotesList->add(pNotesList,Note);
        i++;
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
    int memoCount = pNotesList->len(pNotesList);

    dataBaseFile = fopen(DB_FILE, "wb");

    if(dataBaseFile == NULL)
    {
        printf("Error al intentar escribir en la base de datos\n");
        return -1;
    }

    fwrite(&memoCount,sizeof(int),1,dataBaseFile);
    fwrite(pNotesList->pElements, sizeof(Memo),memoCount,dataBaseFile);
    fclose(dataBaseFile);

    return 0;
}

/** \brief Compare Notes
 * \param Note
 * \param (Note) struct Memo type
 * \return [0] equals elements [-1] Note1 bigger [1] Note2 Bigger [-2]Null pointers
 */
int compareNotes(void* Note1, void* Note2)
{
    if(Note1 == NULL)return -2;
    if(Note2 == NULL)return -2;

    if(strcmp(Note1,Note2)==0)
    {
        return 0;
    }
    if(strcmp(Note1,Note2)<0)
    {
        return -1;
    }
    else
    {
        return 1;
    }

}
