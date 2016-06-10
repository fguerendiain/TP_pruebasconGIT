#include "arrayList.h"

#ifndef __LIB
#define __LIB

typedef struct
{
    char* title; //nombre de nota
    char* textBox; //cuerpo de nota

}Memo;

int exportBakupToFile(ArrayList *pNotesList,int userMenuOption);  /**< export Notes to txt file, complete or parcial */

int runFunctionMenu(int menuOption,ArrayList *pNotesList, Memo* Note);     /**< Excecute option menu */

int seekNote(ArrayList *pNotesList, int userMenuOption); /**< Search Note by index or title */

int removeNote(ArrayList *pNotesList);  /**< remove Note on spcified index */

int modifyNote(ArrayList *pNotesList, Memo* Note);  /**< modify Note on spcified index */

int addNote(ArrayList *pNotesList, Memo* Note,int userMenuOption);  /**< add new Note on spcified index or last index */

int importDB(ArrayList *pNotesList, Memo* Note);  /**< Import DataBase from archive to memory */

int exportToDataBaseFile(ArrayList *pNotesList);    /**< Export DataBase from memory to archive */


#endif // __LIB
