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
 * \param valueA
 * \param valueB
 * \return void imprime en pantalla el resultado de la operacion solicitada
 *
 */
void runFunction(int userMenuInput,float *valueA,float *valueB)   /**< Ejecuta la operacion seleccionada por el usuario */
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
        break;

        case SUBTRACT :
            cleanScreen();
            result = subtractFloat(valueA,valueB);
            printf("%.2f - %.2f = %.2f\n\n",*valueA, *valueB, result);
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
       break;

        case MULTIPLICATION :
            cleanScreen();
            result = multiplyFloat(valueA,valueB);
            printf("%.2f x %.2f = %.2f\n\n",*valueA, *valueB, result);
        break;

        case FACTORIAL :
            cleanScreen();
            resultFactorial = factorialFloat(valueA);
            printf("%.2f! = %.2ld\n\n",*valueA, resultFactorial);
        break;

        case ALLOPERATIONS :
            cleanScreen();
            result = addFloat(valueA,valueB);
            printf("%.2f + %.2f = %.2f\n\n",*valueA, *valueB, result);
            result = subtractFloat(valueA,valueB);
            printf("%.2f - %.2f = %.2f\n\n",*valueA, *valueB, result);
            result = divideFloat(valueA,valueB);
            printf("%.2f / %.2f = %.2f\n\n",*valueA, *valueB, result);
            result = multiplyFloat(valueA,valueB);
            printf("%.2f x %.2f = %.2f\n\n",*valueA, *valueB, result);
            resultFactorial = factorialFloat(valueA);
            printf("%.2f! = %.2ld\n\n",*valueA, resultFactorial);
        break;

        case EXIT :
            exit(0);
        break;
    }
}
/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief Realiza la suma de dos numeros de tipo float
 *
 * \param operator1 recibe un operador de tipo float
 * \param operator2 recibe un operador de tipo float
 * \return result almacena y devuelve un resultado de tipo float
 *
 */
float addFloat(float *operator1, float *operator2)    /**< Realiza la suma de dos numeros de tipo float */
{
    float result = *operator1 + *operator2;
    return result;
}
/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief Realiza la resta de dos numeros de tipo float
 *
 * \param operator1 recibe un operador de tipo float
 * \param operator2 recibe un operador de tipo float
 * \return result almacena y devuelve un resultado de tipo float
 *
 */
float subtractFloat(float *operator1, float *operator2)   /**< Realiza la resta de dos numeros de tipo float */
{
    float result = *operator1 - *operator2;
    return result;
}
/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief Realiza la multiplicacion de dos numeros de tipo float
 *
 * \param operator1 recibe un operador de tipo float
 * \param operator2 recibe un operador de tipo float
 * \return result almacena y devuelve un resultado de tipo float
 *
 */
float multiplyFloat(float *operator1, float *operator2)   /**< Realiza la multiplicacion de dos numeros de tipo float */
{
    float result = *operator1 * *operator2;
    return result;
}
/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief Realiza la division de dos numeros de tipo float excepto cuando *operator2 sea igual a 0
 *
 * \param operator1 dividendo
 * \param operator2 divisor
 * \return La división de operator1 sobre operator2 o '0' cuando operator2 es igual a 0
 *
 */
float divideFloat(float *operator1, float *operator2) /**<  Realiza la division de dos numeros de tipo float excepto cuando *operator2 sea igual a 0*/
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
/** \brief Calcula el factorial de un numero de tipo float
 *
 * \param operator1 recibe un operador de tipo float
 * \return result almacena y devuelve un resultado de tipo int
 *
 */
long factorialFloat (float *operator1)  /**< Calcula el factorial de un numero de tipo float */
{
    int counter;
    int operInt1 = (int)*operator1; // SE CASTEA EL FLOAT INGRESADO POR EL USUARIO A UN INT PARA SER EVALUADO POR LA FUNCION
    long result = 1; // POR CONVENCION, 0! = 1
    for (counter = 1; counter<= operInt1 ; counter++){
        result*=counter;
    }
    return result;
}
