#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \brief recibe y valida el ingreso de un entero por parte del usuario
 *
 * \param (userinput) direccion de memoria de la variable donde guardar el dato ingresado por el usuario
 * \param (min) control de rango a validar, numero entero minimo permitido
 * \param (max) control de rango a validar, numero entero maximo permitido
 * \param (msgFirstTime) mensaje que se le muestra al usuario en el primer intento
 * \param (msgError) mensaje que se le muestra al usuario a partir del segundo intento
 * \param (maxTries) cantidad maxima de intentos, el parametro 0 da infinitos intentos
 *
 * \return (0 = dato correcto dentro del rango | -1 = dato incorrecto | -2 dato correcto fuera de rango)
 *
 */

int getUserInputInt(int *userInput, int min, int max, char *msgFirstTime, char *msgError, int maxTries)
{
    int ret = 0;
    int flagFirstInput = 0;
    int validUserInput;
    int tryCount = 0;

    do
    {
        if (maxTries != 0)
        {
            tryCount++;
        }
        else
        {
            tryCount = -1;
        }

        if(flagFirstInput == 0)
        {
            printf("%s",msgFirstTime);
            flagFirstInput++;
        }
        else
        {
            printf("%s",msgError);
        }

        validUserInput = scanf("%d", userInput);

        if(validUserInput == 0)
        {
            ret = -1;    //el usuario no ingreso un numero
        }
        else if(*userInput < min || *userInput > max)
        {
            ret = -2;    // la funcion indica que el usuario ingreso un numero fuera del rango establecido
        }
        else
        {
            ret = 0;    // la funcion indica que el usuario ingreso un numero dentro del rango establecido
            return ret;
        }
        erradicateStdin();
    }
    while(tryCount < maxTries);
    return ret;
}

/*

float getUserInputFloat(float *userInput,char *msgFirstTime, int min, int max, char *msgError)
{
    {
    int ret = -1;
    int flagFirstInput = 0;
    int validateUserInput;

    do
    {
        if(flagFirstInput == 0)
        {
            printf(msgFirstTime);
            flagFirstInput++;
        }
        else
        {
            printf(msgError);
        }

        validateUserInput = scanf("%f", userInput);

        if(validateUserInput == 0 || userInput < min || userInput > max)
        {
            return ret;
        }
        erradicateStdin();
    }
    return 0;
    }
}


char getUserInputChar(char *userInput,char *msgFirstTime, char *msgError)
{
    {
    int ret = -1;
    int flagFirstInput = 0;
    int validateUserInput;

    do
    {
        if(flagFirstInput == 0)
        {
            printf(msgFirstTime);
            flagFirstInput++;
        }
        else
        {
            printf(msgError);
        }

        validateUserInput = scanf("%c", userInput);

        if(validateUserInput == 0)
        {
            return ret;
        }
        erradicateStdin();
    }
    return 0;
    }
}


char getUserInputString(char *userImput,char *msgFirstTime, cantMinLetras,cantMaxLetras,char *msgError)
{
    printf(msgFirstTime);
    gets(userImput);

    if(strlen(userImput) > cantMaxLetras && strlen(userImput) < cantMinLetras)
    {
        ret
    }

}

*/
