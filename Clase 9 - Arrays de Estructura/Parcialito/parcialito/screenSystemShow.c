#include "screenSystemShow.h"
#include "userInputOutput.h"
#include "struct.h"

void printAwesomeMenu(char *menu)
{
    printf(menu);
}
/*---------------------------------------------------------------------------------------------*/
void erradicateStdin()
{
    char stdinBuffer;
    while((stdinBuffer = getchar()) != '\n' && stdinBuffer != EOF);

    return;
}
/*---------------------------------------------------------------------------------------------*/
void pauseScreen()  /**< Pausa el programa hasta que se presiona Enter */
{
    printf("\nPresione Enter para continuar: ... ");
    while ( getchar() != '\n');
}
