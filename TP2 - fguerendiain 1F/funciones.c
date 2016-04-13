#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "validations.h"
#include "funciones.h"


/** \brief Imprime el menu
 * \return void Imprime menu en pantalla
 */
void printMenu() /**< Imprime el menu */
{
    printf(
        "1- Agregar persona\n"
        "2- Borrar persona\n"
        "3- Imprimir lista ordenada por  nombre\n"
        "4- Imprimir grafico de edades\n"
        "5- Salir\n"
       );
}
/*--------------------------------------------------------------------------------*/
/** \brief Ejecuta la opcion elegida por el usuario
 * \param opcion recibe un int con la opcion ingresada por el usuario
 * \return luego de ejecutar la opcion devuelve el valor par continuar o no
 */
int runFunctionMenu(int opcion) /**< Ejecuta la opcion elegida por el usuario */
{
    int seguir = 1;
    switch(opcion)
    {
        case 1:
        break;
        case 2:
        break;
        case 3:
        break;
        case 4:
        break;
        case 5:
            seguir = 0;
        break;
    }
    return seguir;
}
/*--------------------------------------------------------------------------------*/
/** \brief Consume todo el stdin hasta encontrar un EOF o un "\n", se utiliza en reemplazo del fflush().
 * \return void
 */

void erradicateStdin()
{
    char stdinBuffer;
    while((stdinBuffer = getchar()) != '\n' && stdinBuffer != EOF);

    return;
}
