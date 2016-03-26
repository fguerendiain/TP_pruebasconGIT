#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

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
    float oper1 = 0;
    float oper2 = 0;

    switch(userMenuInput)
    {
        case OPERATOR1 :
            oper1 = getUserNumberInput(1);
            *valueA = oper1;
        break;

        case OPERATOR2 :
            oper2 = getUserNumberInput(2);
            *valueB = oper2;
        break;

        case ADD :
            result = addFloat(oper1,oper2);
            cleanScreen();
            printf("%2.f + %2.f = %2.f\n\n",oper1, oper2, result);
        break;

        case SUBTRACT :
            result = subtractFloat(oper1,oper2);
            cleanScreen();
            printf("%2.f - %2.f = %2.f\n\n",oper1, oper2, result);
        break;

        case DIVISION :
            result = divideFloat(oper1,oper2);
            cleanScreen();
            printf("%2.f / %2.f = %2.f\n\n",oper1, oper2, result);
        break;

        case MULTIPLICATION :
            result = multiplyFloat(oper1,oper2);
            cleanScreen();
            printf("%2.f x %2.f = %2.f\n\n",oper1, oper2, result);
        break;

        case FACTORIAL :
            result = factorialFloat(oper1);
            cleanScreen();
            printf("%1.f! = %1.f\n\n",oper1, result);
        break;

        case ALLOPERATIONS :

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
float addFloat(float operator1, float operator2)    /**< Realiza la suma de dos numeros de tipo float */
{
    float result = operator1 + operator2;
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
float subtractFloat(float operator1, float operator2)   /**< Realiza la resta de dos numeros de tipo float */
{
    float result = operator1 - operator2;
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
float multiplyFloat(float operator1, float operator2)   /**< Realiza la multiplicacion de dos numeros de tipo float */
{
    float result = operator1 * operator2;
    return result;
}
/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief Realiza la division de dos numeros de tipo float
 *
 * \param operator1 recibe un operador de tipo float
 * \param operator2 recibe un operador de tipo float
 * \return result almacena y devuelve un resultado de tipo float
 *
 */
float divideFloat(float operator1, float operator2) /**< Realiza la division de dos numeros de tipo float */
{
    float result = operator1 / operator2;
    return result;
}
/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief Calcula el factorial de un numero de tipo float
 *
 * \param operator1 recibe un operador de tipo float
 * \return result almacena y devuelve un resultado de tipo int
 *
 */
float factorialFloat (float operator1)  /**< Calcula el factorial de un numero de tipo float */
{
    int counter;
    int operInt1 = (int)operator1; // SE CASTEA EL FLOAT INGRESADO POR EL USUARIO A UN INT PARA SER EVALUADO POR LA FUNCION
    int result = 1; // POR CONVENCION, 0! = 1
    for (counter = 1; counter<= operInt1 ; counter++){
        result*=counter;
    }
    return (float)result;
}
