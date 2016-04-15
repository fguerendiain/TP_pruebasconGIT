#include <stdio.h>

/** \brief Imprime el menu
 * \return void Imprime menu en pantalla
 */
void printAwesomeMenu(char *menu)   /**< Imprime el menu */
{
    printf("%s",menu);
}
/*---------------------------------------------------------------------------------------------*/
/** \brief Consume todo el stdin hasta encontrar un EOF o un "\n", se utiliza en reemplazo del fflush().
 * \return void
 */
void erradicateStdin()
{
    char stdinBuffer;
    while((stdinBuffer = getchar()) != '\n' && stdinBuffer != EOF);

    return;
}
/*---------------------------------------------------------------------------------------------*/
/** \brief Pausa el programa hasta que se presiona Enter.
 * \return void
 */
void pauseScreen()  /**< Pausa el programa hasta que se presiona Enter */
{
    printf("\nPresione Enter para continuar: ... ");
    while ( getchar() != '\n');
}
