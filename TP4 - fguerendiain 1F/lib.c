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
            cleanScreen();
            printf( "*******************************************************\n"
                    "**  PRESIONE [ENTER] PARA CERRAR NOTE MANNAGER 2016  **\n"
                    "***************  GRACIAS POR ELEGIRNOS  ***************\n"
                    "*******************************************************\n");
            return 0;
        }
        break;
    }
    return 1;
}

/** \brief Create a new Note
 * \return Memo* Return pointer to Note
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
 * \return [-1] parameter is a Null pointer [0] if ok
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
 * \return [-1] parameter is a Null pointer [0] if ok
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
        showNotesIndexAndTitle(pNotesList);
        printf("\n\n%d notas cargadas en el sistema\n",pNotesList->len(pNotesList));
    }
    return 0;
}

/** \brief export Notes to txt file, complete or parcial
 * \param (menuOption) int with user selection
 * \param (pNotesList) ArrayList
 * \return [-2]cant open file [-1] parameter is a Null pointer [0] if ok
 */
int exportBakupToFile(ArrayList *pNotesList,int userMenuOption)
{

    if(pNotesList == NULL)return -1;
    if(userMenuOption != 1 && userMenuOption != 2)return -1;

    FILE *bkpFile;
    int toIndex = 0;
    int fromIndex = 0;
    int i;
    ArrayList* pNotesBkp = al_newArrayList();
    Memo* Note = NULL;

    if(pNotesList->isEmpty(pNotesList)!=0)
    {
        cleanScreen();
        printf("No existen notas cargadas\n\n");
        return 0;
    }

    pNotesList->sort(pNotesList,compareNotes,1);

    if(userMenuOption == 1)
    {
        pNotesBkp = pNotesList->clone(pNotesList);
        toIndex = pNotesBkp->len(pNotesBkp);
    }
    else
    {

        showNotesIndexAndTitle(pNotesList);

        getUserInputInt(&fromIndex,0,pNotesList->len(pNotesList)-1,"\n\nIngrese el indice desde donde desea exportar:\n\n","Por favor ingrese un indice valido:\n\n",0);
        getUserInputInt(&toIndex,fromIndex,pNotesList->len(pNotesList)-1,"Ingrese el indice hasta donde desea exportar:\n\n","Por favor ingrese un indice valido:\n\n",0);
        pNotesBkp = pNotesList->subList(pNotesList,fromIndex,toIndex);
    }

    bkpFile = fopen(BKP_COMFILE, "w");

    if(bkpFile == NULL)
    {
        printf("Error al intentar escribir en la base de datos\n");
        return -2;
    }

    for(i=0 ; i<pNotesBkp->len(pNotesBkp) ; i++)
    {
        if(pNotesBkp->get(pNotesBkp,i)!=NULL)
        {
            Note = pNotesBkp->get(pNotesBkp,i);
            stringSetCase(Note->title,1);
            fprintf(bkpFile,"Titulo: --%s--\n",Note->title);
            fprintf(bkpFile,"  Nota: %s\n",Note->textBox);
            fprintf(bkpFile,"\n------------------------------------------\n\n");
        }
    }
    cleanScreen();
    printf("Se exportaron las notas correctamente en "BKP_COMFILE"\n\n");
    fclose(bkpFile);
    return 0;
}

/** \brief Search Note by index or title
 * \param (menuOption) int with user selection
 * \param (pNotesList) ArrayList
 * \return [-1] parameter is a Null pointer or userOption out of range [0] if ok
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
        return 0;
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
            stringSetCase(AuxNote->title,1);
            stringSetCase(auxTitle,1);
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
 * \return [-1] parameter is a Null pointer [0] if ok
 */
int removeNote(ArrayList *pNotesList)
{
    if(pNotesList == NULL)return -1;

    int auxIndex = 0;

    if(pNotesList->isEmpty(pNotesList)!=0)
    {
        cleanScreen();
        printf("No existen notas cargadas\n\n");
        return 0;
    }

    showNotesIndexAndTitle(pNotesList);

    getUserInputInt(&auxIndex,0,pNotesList->len(pNotesList),"\n\nIngrese el indice de la Nota a eliminar:\n\n","Por favor ingrese un indice valido:\n\n",0);
    pNotesList->pop(pNotesList,auxIndex);
    printf("La nota fue eliminada con exito\n\n");

    return 0;
}

/** \brief modify Note on spcified index
 * \param (menuOption) int with user selection
 * \param (Note) struct Memo type
 * \return [-1] parameter is a Null pointer [0] if ok
 */
int modifyNote(ArrayList *pNotesList)
{
    if(pNotesList == NULL)return -1;

    char auxTitle[15]; //nombre de nota
    char auxTextBox[2500]; //cuerpo de nota
    int auxIndex = 0;

    Memo* Note = newNote();

    if(pNotesList->isEmpty(pNotesList)!=0)
    {
        cleanScreen();
        printf("No existen notas cargadas\n\n");
        return 0;
    }

    showNotesIndexAndTitle(pNotesList);

    printf("\n\n");
    getUserInputInt(&auxIndex,0,pNotesList->len(pNotesList)-1,"Ingrese el indice de la nueva Nota:\n\n","Por favor ingrese un indice valido:\n\n",0);
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
 * \return [-1] parameter is a Null pointer or userOption out of range [0] if ok
 */
int addNote(ArrayList *pNotesList, int userMenuOption)
{
    if(pNotesList == NULL)return -1;
    if(userMenuOption != 1 && userMenuOption != 2)return -1;

    char auxTitle[15];
    char auxTextBox[2500];
    int auxIndex = -1;
    int i;

    Memo* Note = newNote();
    if(Note == NULL)return -1;

    if(userMenuOption == 1)
    {
        if(pNotesList->isEmpty(pNotesList)!=0)
        {
        cleanScreen();
        printf("No se puede ingresar por indice debido a que no existen notas cargadas\nSu nota se guardara en el indice 0\n");
        userMenuOption =2;
        pauseScreen();
        }

        else
        {
            showNotesIndexAndTitle(pNotesList);
            printf("\n\n");
            getUserInputInt(&auxIndex,0,pNotesList->len(pNotesList)-1,"Ingrese el indice de la nueva Nota:\n\n","Por favor ingrese un indice valido:\n\n",0);
        }
    }

    cleanScreen();

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
        pNotesList->push(pNotesList,auxIndex,Note);
    }

    return 0;
}

/** \brief Import DataBase from archive to memory
 * \param (pNotesList) ArrayList
 * \param (Note) struct Memo type
 * \return [-2]cant open file [-1] parameter is a Null pointer [0] if ok
 */
int importDB(ArrayList *pNotesList)
{
    if(pNotesList == NULL)return -1;

    Memo* Note;
    FILE* dataBaseFile;
    int memoCount = -1;
    int i;

    dataBaseFile = fopen(DB_FILE, "rb");
    if(dataBaseFile == NULL)return -2;

    fread(&memoCount, sizeof(int), 1, dataBaseFile);

    if(memoCount == 0)return 0; //en caso que la cantidad de notas sean 0

    for(i=0 ; i<memoCount; i++)
    {
        Note = newNote();
        fread(Note, sizeof(Memo),1,dataBaseFile);
        pNotesList->add(pNotesList,Note);
    }
    fclose(dataBaseFile);
    return 0;
}

/** \brief Export DataBase from memory to archive
 * \param (pNotesList) ArrayList
 * \param (Note) struct Memo type
 * \return [-2]cant open file [-1] parameter is a Null pointer [0] if ok
 */
int exportToDataBaseFile(ArrayList *pNotesList)
{
    if(pNotesList == NULL)return -1;

    FILE *dataBaseFile;
    int memoCount = pNotesList->len(pNotesList);
    int i;

    dataBaseFile = fopen(DB_FILE, "wb");

    if(dataBaseFile == NULL)
    {
        printf("Error al intentar escribir en la base de datos\n");
        return -1;
    }

    fwrite(&memoCount,sizeof(int),1,dataBaseFile);
    for(i=0;i<memoCount;i++)
    {
        fwrite(pNotesList->get(pNotesList,i), sizeof(Memo),1,dataBaseFile);
    }
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

/** \brief List Index and Title of Notes
 * \param (pNotesList) ArrayList
 * \return [-1] parameter is a Null pointer [0] if ok
 */
int showNotesIndexAndTitle(ArrayList *pNotesList)
{
    if(pNotesList==NULL)return -1;
    int i;
    int printedNotes = 5;
    Memo* Note = NULL;

    cleanScreen();
    printf("NOTAS\n");
    for(i=0;i<pNotesList->len(pNotesList);i++)
    {
        Note = pNotesList->get(pNotesList,i);
        if(Note!=NULL)
        {
            stringSetCase(Note->title,3);
            printf("%d - %s | ",i,Note->title);
            if(i==printedNotes)
            {
                printf("\n");   //realiza un salto de linea luego de imprimir 5 notas
                printedNotes+=5;
            }
        }
        Note =newNote();
    }
    return 0;
}
