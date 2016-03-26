/*
*   Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
*
*   1. Ingresar 1er operando (A=x)
*   2. Ingresar 2do operando (B=y)
*   3. Calcular la suma (A+B)
*   4. Calcular la resta (A-B)
*   5. Calcular la division (A/B)
*   6. Calcular la multiplicacion (A*B)
*   7. Calcular el factorial (A!)
*   8. Calcular todas las operaciones
*   9. Salir
*
*   • Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
*     que contenga las funciones para realizar las 4 operaciones.
*
*   • En el menú deberán aparecer los valores actuales cargados en los operandos A y B
*     (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
*
*   • Deberán contemplarse los casos de error (división por cero, etc)
*
*   • Documentar todas las funciones!!
*
*/
/*-------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "validations.h"
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
void main(void)
{
    float valueA = 10;
    float valueB = 5;
    int userMenuInput = 0;
    int userWillToContinue = 0;

    do
    {
        printMenu(valueA, valueB);
        userMenuInput = getMenuUserInput();  //REVISAR POR QUE LOOPEA LA FUNCION CUANDO SE INGRESA ALGO QUE NO SEA UN INT
        runFunction(userMenuInput, &valueA, &valueB);
        userWillToContinue = getUserConfirmToContinue(); //REVISAR POR QUE LOOPEA LA FUNCION CUANDO SE INGRESA ALGO QUE NO SEA UN INT
    }
    while(userWillToContinue == 1);
    return;
}
