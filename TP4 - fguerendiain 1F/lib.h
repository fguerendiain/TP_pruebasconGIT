#include "arrayList.h"

#ifndef __LIB
#define __LIB

typedef struct
{
    char* title; //nombre de nota
    char* textBox; //cuerpo de nota

}Memo;


int runFunctionMenu(int menuOption,ArrayList *pNotesList, Memo* Note);     /**< Excecute option menu */


int removeNote(ArrayList *pNotesList, Memo* Note);  /**< remove Note on spcified index */

int modifyNote(ArrayList *pNotesList, Memo* Note);  /**< modify Note on spcified index */

int addNote(ArrayList *pNotesList, Memo* Note,int userMenuOption);  /**< add new Note on spcified index or last index */

int importDB(ArrayList *pNotesList, Memo* Note);  /**< Import DataBase from archive to memory */

int exportToDataBaseFile(ArrayList *pNotesList, Memo* Note);    /**< Export DataBase from memory to archive */


#endif // __LIB
