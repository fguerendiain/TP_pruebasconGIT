#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void printMenu(); /**< Imprime el menu */

int runFunctionMenu(int opcion); /**< Ejecuta la opcion elegida por el usuario */

void erradicateStdin();  /**<Consume todo el stdin hasta encontrar un EOF o un "\n", se utiliza en reemplazo del fflush().*/

#endif // FUNCIONES_H_INCLUDED


