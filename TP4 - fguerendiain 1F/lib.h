#include "arrayList.h"

#ifndef __LIB
#define __LIB

typedef struct
{
    char title[15]; //nombre de nota
    char textBox[2500]; //cuerpo de nota

}Memo;

int deleteAllNotes(ArrayList *pNotesList);  /**< delete All Notes */

int showHowManyNotes(ArrayList *pNotesList);    /**< show how many Notes exist */

int exportBakupToFile(ArrayList *pNotesList,int userMenuOption);  /**< export Notes to txt file, complete or parcial */

int runFunctionMenu(int menuOption,ArrayList *pNotesList);     /**< Excecute option menu */

int seekNote(ArrayList *pNotesList, int userMenuOption); /**< Search Note by index or title */

int removeNote(ArrayList *pNotesList);  /**< remove Note on spcified index */

int modifyNote(ArrayList *pNotesList);  /**< modify Note on spcified index */

int addNote(ArrayList *pNotesList,int userMenuOption);  /**< add new Note on spcified index or last index */

int importDB(ArrayList *pNotesList);  /**< Import DataBase from archive to memory */

int exportToDataBaseFile(ArrayList *pNotesList);    /**< Export DataBase from memory to archive */

Memo* newNote();  /**< Create a new Note */

int compareNotes(void* Note1, void* Note2); /**< Compare Notes */

#endif // __LIB
