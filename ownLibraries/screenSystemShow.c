#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"

#define LIMPIARPANTALLA "cls" // "cls" para windows | "clear" para linux

/** \brief Imprime el menu
 * \param (menu) recibe el texto a imprimir
 */
void printAwesomeMenu(char *menu)
{
    cleanScreen();
    printf("%s",menu);
}

/** \brief Consume todo el stdin hasta encontrar un EOF o un "\n", se utiliza en reemplazo del fflush().
 *
 */
void erradicateStdin()
{
    char stdinBuffer;
    while((stdinBuffer = getchar()) != '\n' && stdinBuffer != EOF);

    return;
}

/** \brief Pausa el programa hasta que se presiona Enter.
 *
 */
void pauseScreen()
{
    printf("\nPresione Enter para continuar: ... ");
    while ( getchar() != '\n');
}

/** \brief Limpia la pantalla
 *
 */

void cleanScreen()
{
    system(LIMPIARPANTALLA);
}

/** \brief convirte a mayuscula una cadena de caracteres
 * \param (stringToConvert) cadena de caracter a convertir
 *
 */

void stringToUpperCase(char *stringToConvert)
{
    long int i;

    for(i=0; stringToConvert[i]!='\0'; i++)
    {
        stringToConvert[i] = toupper(stringToConvert[i]);
    }
}
