#ifndef VALIDATIONS_H_INCLUDED
#define VALIDATIONS_H_INCLUDED

#endif // VALIDATIONS_H_INCLUDED
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
void cleanScreen(); /**< Limpia la pantalla */

float getUserNumberInput(int order); /**< Solicita al usuario ingresar un numero de tipo float */

void printMenu(float valueA, float valueB); /**< imprime el menu en pantalla */

int getMenuUserInput(); /**< Solicita ingresar una opcion del menu validando la misma */

int getUserConfirmToContinue(); /**< Solicita al usuario ingresar dos valores para continuar o no */
