#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "validations.h"

#define OPERATOR1 1
#define OPERATOR2 2
#define ADD 3
#define SUBTRACT 4
#define DIVISION 5
#define MULTIPLICATION 6
#define FACTORIAL 7
#define ALLOPERATIONS 8
#define EXIT 9
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief Ejecuta la operacion seleccionada por el usuario
 *
 * \param userMenuInput recibe un int con la opcion del menu que elijio el usuario
 * \param valueA direccion de memoria del primer operando
 * \param valueB direccion de memoria del segundo operando
 * \param userWillToContinue direccion de memoria de la variable que determina el fin del programa
 * \return void imprime en pantalla el resultado de la operacion solicitada
 *
 */
void runFunction(int userMenuInput,float *valueA,float *valueB, int *userWillToContinue)   /**< Ejecuta la operacion seleccionada por el usuario */
{
    float result = 0;
    long resultFactorial = 0;

    switch(userMenuInput)
    {
        case OPERATOR1 :
            *valueA = getUserNumberInput(1);
        break;

        case OPERATOR2 :
            *valueB = getUserNumberInput(2);
        break;

        case ADD :
            cleanScreen();
            result = addFloat(valueA,valueB);
            printf("%.2f + %.2f = %.2f\n\n",*valueA, *valueB, result);
            pauseScreen();
        break;

        case SUBTRACT :
            cleanScreen();
            result = subtractFloat(valueA,valueB);
            printf("%.2f - %.2f = %.2f\n\n",*valueA, *valueB, result);
            pauseScreen();
        break;

        case DIVISION :
            cleanScreen();
            if(*valueB != 0)
            {
                result = divideFloat(valueA,valueB);
                printf("%.2f / %.2f = %.2f\n\n",*valueA, *valueB, result);
            }
            else
            {
                printf("Por favor ingrese un divisor distinto de 0\n");
            }
            pauseScreen();
       break;

        case MULTIPLICATION :
            cleanScreen();
            result = multiplyFloat(valueA,valueB);
            printf("%.2f x %.2f = %.2f\n\n",*valueA, *valueB, result);
            pauseScreen();
        break;

        case FACTORIAL :
            cleanScreen();
            resultFactorial = factorialFloat(valueA);
            printf("%.2f! = %.2ld\n\n",*valueA, resultFactorial);
            pauseScreen();
        break;

        case ALLOPERATIONS :
            cleanScreen();
            result = addFloat(valueA,valueB);
            printf("%.2f + %.2f = %.2f\n\n",*valueA, *valueB, result);
            result = subtractFloat(valueA,valueB);
            printf("%.2f - %.2f = %.2f\n\n",*valueA, *valueB, result);
            if(*valueB != 0)
            {
                result = divideFloat(valueA,valueB);
                printf("%.2f / %.2f = %.2f\n\n",*valueA, *valueB, result);
            }
            else
            {
                printf("No se puede realizar la division por 0\n\n");
            }
            result = multiplyFloat(valueA,valueB);
            printf("%.2f x %.2f = %.2f\n\n",*valueA, *valueB, result);
            resultFactorial = factorialFloat(valueA);
            printf("%.2f! = %.2ld\n\n",*valueA, resultFactorial);
            pauseScreen();
        break;

        case EXIT :
            *userWillToContinue = 0;
            return;
        break;
    }
    *userWillToContinue = 1;
}
/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief Realiza la suma de dos numeros
 *
 * \param operator1 recibe el primer operador
 * \param operator2 recibe el segundo operador
 * \return result devuelve el resultado de la suma
 *
 */
float addFloat(float *operator1, float *operator2)    /**< Realiza la suma de dos numeros */
{
    float result = *operator1 + *operator2;
    return result;
}
/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief Realiza la resta de dos numeros
 *
 * \param operator1 recibe el primer operador
 * \param operator2 recibe el segundo operador
 * \return result devuelve la resta de dos numeros
 *
 */
float subtractFloat(float *operator1, float *operator2)   /**< Realiza la resta de dos numeros */
{
    float result = *operator1 - *operator2;
    return result;
}
/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief Realiza la multiplicacion de dos numeros
 *
 * \param operator1 recibe el primer operador
 * \param operator2 recibe el segundo operador
 * \return result devuelve la multiplicacion de dos numeros
 *
 */
float multiplyFloat(float *operator1, float *operator2)   /**< Realiza la multiplicacion de dos numeros*/
{
    float result = *operator1 * *operator2;
    return result;
}
/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief Realiza la division de dos numeros, excepto cuando *operator2 sea igual a 0
 *
 * \param operator1 recibe el primer operador
 * \param operator2 recibe el segundo operador
 * \return La división de operator1 sobre operator2 o '0' cuando operator2 es igual a 0
 *
 */
float divideFloat(float *operator1, float *operator2) /**<  Realiza la division de dos numeros, excepto cuando *operator2 sea igual a 0*/
{
    if(*operator2!=0)
    {
        float result = *operator1 / *operator2;
        return result;
    }
        else
    {
        return 0;
    }
}
/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief Calcula el factorial de un numero
 *
 * \param operator1 recibe un operador
 * \return result devuelve el factorial de un numero
 *
 */
long factorialFloat (float *operator1)  /**< Calcula el factorial de un numero */
{
    int counter;
    int operInt1 = (int)*operator1; // SE CASTEA EL FLOAT INGRESADO POR EL USUARIO A UN INT PARA SER EVALUADO POR LA FUNCION
    long result = 1; // POR CONVENCION, 0! = 1
    for (counter = 1; counter<= operInt1 ; counter++){
        result*=counter;
    }
    return result;
}
