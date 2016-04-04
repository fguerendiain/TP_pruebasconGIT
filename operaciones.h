#ifndef OPERACIONES_H_INCLUDED
#define OPERACIONES_H_INCLUDED

#endif // OPERACIONES_H_INCLUDED
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
void runFunction(int userMenuInput,float *valueA,float *valueB);   /**< Ejecuta la operacion seleccionada por el usuario */

float addFloat(float *operator1, float *operator2);    /**< Realiza la suma de dos numeros de tipo float */

float subtractFloat(float *operator1, float *operator2);   /**< Realiza la resta de dos numeros de tipo float */

float multiplyFloat(float *operator1, float *operator2);   /**< Realiza la multiplicacion de dos numeros de tipo float */

float divideFloat(float *operator1, float *operator2); /**<  Realiza la division de dos numeros de tipo float excepto cuando *operator2 sea igual a 0*/

long factorialFloat (float *operator1);  /**< Calcula el factorial de un numero de tipo float */
