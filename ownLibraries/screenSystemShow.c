#include <stdio.h>
#include <stdlib.h>

#define LIMPIARPANTALLA "clear" // "cls" para windows | "clear" para linux

/** \brief Imprime el menu
 * \return void Imprime menu en pantalla
 */
void printAwesomeMenu(char *menu)
{
    cleanScreen();
    printf("%s",menu);
}

/** \brief Consume todo el stdin hasta encontrar un EOF o un "\n", se utiliza en reemplazo del fflush().
 * \return void
 */
void erradicateStdin()
{
    char stdinBuffer;
    while((stdinBuffer = getchar()) != '\n' && stdinBuffer != EOF);

    return;
}

/** \brief Pausa el programa hasta que se presiona Enter.
 * \return void
 */
void pauseScreen()
{
    printf("\nPresione Enter para continuar: ... ");
    while ( getchar() != '\n');
}

/** \brief Limpia la pantalla
 *
 * \return void
 *
 */

void cleanScreen()
{
    system(LIMPIARPANTALLA);
}
