#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "screenSystemShow.h"

/** \brief recibe y valida el ingreso de un **SHORT INT** por parte del usuario
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

int getUserInputShortInt(short int *userInput, short int min, short int max, char *msgFirstTime, char *msgError, int maxTries)
{
    int ret = 0;
    short int flagFirstInput = 0;
    short int validUserInput;
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
            flagFirstInput = 1;
        }
        else
        {
            printf("%s",msgError);
        }

        validUserInput = scanf("%hi", userInput);

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
            erradicateStdin();
            return ret;
        }
        erradicateStdin();
    }
    while(tryCount < maxTries);
    return ret;
}

/** \brief recibe y valida el ingreso de un **INT** por parte del usuario
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
    short int flagFirstInput = 0;
    short int validUserInput;
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
            flagFirstInput = 1;
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
            erradicateStdin();
            return ret;
        }
        erradicateStdin();
    }
    while(tryCount < maxTries);
    return ret;
}

/** \brief recibe y valida el ingreso de un **LONG INT** por parte del usuario
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

int getUserInputLongInt(long int *userInput, long int min, long int max, char *msgFirstTime, char *msgError, int maxTries)
{
    int ret = 0;
    short int flagFirstInput = 0;
    short int validUserInput;
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
            flagFirstInput = 1;
        }
        else
        {
            printf("%s",msgError);
        }

        validUserInput = scanf("%ld", userInput);

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
            erradicateStdin();
            return ret;
        }
        erradicateStdin();
    }
    while(tryCount < maxTries);
    return ret;
}

/** \brief recibe y valida el ingreso de un **FLOAT** por parte del usuario
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

int getUserInputFloat(float *userInput, float min, float max, char *msgFirstTime, char *msgError, int maxTries)
{
    int ret = 0;
    short int flagFirstInput = 0;
    short int validUserInput;
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
            flagFirstInput = 1;
        }
        else
        {
            printf("%s",msgError);
        }

        validUserInput = scanf("%f", userInput);

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
            erradicateStdin();
            return ret;
        }
        erradicateStdin();
    }
    while(tryCount < maxTries);
    return ret;
}

/** \brief recibe y valida el ingreso de un **DOUBLE** por parte del usuario
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

int getUserInputDouble(double *userInput, double min, double max, char *msgFirstTime, char *msgError, int maxTries)
{
    int ret = 0;
    short int flagFirstInput = 0;
    short int validUserInput;
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
            flagFirstInput = 1;
        }
        else
        {
            printf("%s",msgError);
        }

        validUserInput = scanf("%lf", userInput);

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
            erradicateStdin();
            return ret;
        }
        erradicateStdin();
    }
    while(tryCount < maxTries);
    return ret;
}

/** \brief recibe y valida el ingreso de un **CHAR** por parte del usuario
 *
 * \param (userinput) direccion de memoria de la variable donde guardar el dato ingresado por el usuario
 * \param (msgFirstTime) mensaje que se le muestra al usuario en el primer intento
 * \param (msgError) mensaje que se le muestra al usuario a partir del segundo intento
 * \param (maxTries) cantidad maxima de intentos, el parametro 0 da infinitos intentos
 *
 * \return (0 = dato correcto dentro del rango | -1 = dato incorrecto)
 *
 */

int getUserInputChar(char *userInput, char *msgFirstTime, char *msgError, int maxTries)
{
    int ret = 0;
    short int flagFirstInput = 0;
    short int validUserInput;
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
            flagFirstInput = 1;
        }
        else
        {
            printf("%s",msgError);
        }

        validUserInput = scanf("%c", userInput);

        if(validUserInput == 0)
        {
            ret = -1;    //el usuario no ingreso un caracter
        }
        else
        {
            ret = 0;    // la funcion indica que el usuario ingreso un caracter
            erradicateStdin();
            return ret;
        }
        erradicateStdin();
    }
    while(tryCount < maxTries);
    return ret;
}

/** \brief recibe y valida el ingreso de un **STRING** por parte del usuario
 *
 * \param (userinput) direccion de memoria de la variable donde guardar el dato ingresado por el usuario
 * \param (min) cantidad minima de caracteres del string a ingresar
 * \param (max) cantidad maxima de caracteres del string a ingresar
 * \param (msgFirstTime) mensaje que se le muestra al usuario en el primer intento
 * \param (msgError) mensaje que se le muestra al usuario a partir del segundo intento
 * \param (maxTries) cantidad maxima de intentos, el parametro 0 da infinitos intentos
 *
 * \return (0 = dato correcto dentro del rango | -1 = dato incorrecto | -2 dato correcto fuera de rango)
 *
 */

int getUserInputString(char *userInput, long min, long max, char *msgFirstTime, char *msgError, long bufferSize, int maxTries)
{


    int ret = 0;
    short int flagFirstInput = 0;
    int tryCount = 0;
    char auxBuffer[bufferSize];

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
            flagFirstInput = 1;
        }
        else
        {
            printf("%s",msgError);
        }

        scanf("%s",auxBuffer);

        if(strlen(auxBuffer) < min || strlen(auxBuffer) > max)
        {
            ret = -2;    // la funcion indica que el usuario ingreso un string fuera de la longitud permitida
        }
        else
        {
            strcpy(userInput, auxBuffer);
            stringSetCase(userInput,1);
            ret = 0;    // la funcion indica que el usuario ingreso un string dentro de la longitud permitida
            erradicateStdin();
            return ret;
        }
        erradicateStdin();
    }
    while(tryCount < maxTries);
    return ret;
}

/** \brief solicitud booleana de confirmacion
 *
 * \param (intYes) numero de afirmacion
 * \param (intNo) numero de negacion
 * \param (charYes) caracter de afirmacion
 * \param (charNo) caracter de negacion
 * \param (msgFirstTime) mensaje que se le muestra al usuario en el primer intento
 * \param (msgError) mensaje que se le muestra al usuario a partir del segundo intento
 * \param (charOrIntMode) setea el tipo de dato de validacion char o int
 * \param (maxTries) cantidad maxima de intentos, el parametro 0 da infinitos intentos
 *
 * \return (-2 = caracter invalido | -1 = numero invalido | 0 = sin ingreso de datos | 1 = intYes | 2 = intNo | 3 = charYes 4 = charNo )
 *
*/

int getUserConfirmToContinue(int intYes, int intNo, char charYes, char charNo, char *msgFirstTime, char *msgError,int charOrIntMode, int maxTries)
{
    int ret = 0; //el usuario salio sin ingresar un dato valido
    int userAnswerInt;
    char userAnswerChar;
    int flagFirstInput = 0;
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
            flagFirstInput = 1;
        }
        else
        {
            printf("%s",msgError);
        }

        if(charOrIntMode == 1)
        {
            scanf("%d",&userAnswerInt);

            if(userAnswerInt!=intYes && userAnswerInt!=intNo)
            {
                ret = -1;  //el usuario ingreso un numero invalido
            }
            else if (userAnswerInt==intYes)
            {
                ret = 1;     //el usuario ingreso intYes
                erradicateStdin();
                return ret;
            }
            else
            {
                ret = 2;     //el usuario ingreso intNo
                erradicateStdin();
                return ret;
            }
        }
        else
        {
            scanf("%c",&userAnswerChar);
            stringSetCase(&userAnswerChar,1);
            stringSetCase(&charYes,1);
            stringSetCase(&charNo,1);

            if(userAnswerChar!=charYes && userAnswerChar!=charNo)
            {
                ret = -2; // el usuario ingreso un caracter invalido
            }
            else if (userAnswerChar=='S')
            {
                ret = 3; //el usuario ingreso charYes
                erradicateStdin();
                return ret;
            }
            else
            {
                ret = 4;
                erradicateStdin();
                return ret;  // el usuario ingreso charNo
            }
        }
        erradicateStdin();
    }
    while(tryCount < maxTries);
    return ret;
}
