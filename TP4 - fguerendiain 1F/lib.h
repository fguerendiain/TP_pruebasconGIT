#include "arrayList.h"

#ifndef __LIB
#define __LIB

typedef struct
{
    char* title; //nombre de nota
    char* textBox; //cuerpo de nota
    int priority; // 1 al 10

}Memo;


int runFunctionMenu(int menuOption,ArrayList *pNotesList, Memo* Note);     /**< Excecute option menu */

int addNote(ArrayList *pNotesList, Memo* Note,int userMenuOption);  /**< add new Note on spcified index or last index */

int importDB(ArrayList *pNotesList, Memo* Note);  /**< Import DataBase from archive to memory */

int exportToDataBaseFile(ArrayList *pNotesList, Memo* Note);    /**< Export DataBase from memory to archive */


#endif // __LIB
