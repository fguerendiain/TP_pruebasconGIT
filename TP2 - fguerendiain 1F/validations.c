#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "validations.h"
#include "funciones.h"


/** \brief Solicita ingresar una opcion del menu validando la misma
 * \return Devuelve el int ingresado por el usuario
 */
int getMenuUserInput() /**< Solicita ingresar una opcion del menu validando la misma */
{
    int userInput = -1;
    int flagFirstInput = 0;
    int validateUserInput;

    do
    {
        if(flagFirstInput == 0)
        {
            printf("\nIngrese una opcion: ");
            flagFirstInput++;
        }
        else
        {
            printf("\nPor favor, ingrese una opcion valida: ");
        }

        validateUserInput = scanf("%d", &userInput);

        if(validateUserInput == 0 || userInput < 0 || userInput > 5)
        {
            userInput = -1;
        }

        erradicateStdin();

    }
    while(userInput == -1);
    return userInput;
}
