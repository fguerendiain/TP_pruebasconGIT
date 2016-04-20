#include <stdio.h>
#include <stdlib.h>


            /*----------------SUMA----------------*/


/** \brief Realiza la suma de dos numeros **SHORT**
 *
 * \param (operator1) recibe el primer operador
 * \param (operator2) recibe el segundo operador
 * \return (result) devuelve el resultado de la suma
 *
 */

short int addShortInt(short int *operator1, short int *operator2)
{
    short int result = *operator1 + *operator2;
    return result;
}

/** \brief Realiza la suma de dos numeros **INT**
 *
 * \param (operator1) recibe el primer operador
 * \param (operator2) recibe el segundo operador
 * \return (result) devuelve el resultado de la suma
 *
 */

int addInt(int *operator1, int *operator2)
{
    int result = *operator1 + *operator2;
    return result;
}

/** \brief Realiza la suma de dos numeros **LONG**
 *
 * \param (operator1) recibe el primer operador
 * \param (operator2) recibe el segundo operador
 * \return (result) devuelve el resultado de la suma
 *
 */

long int addLongInt(long int *operator1, long int *operator2)
{
    long int result = *operator1 + *operator2;
    return result;
}

/** \brief Realiza la suma de dos numeros **FLOAT**
 *
 * \param (operator1) recibe el primer operador
 * \param (operator2) recibe el segundo operador
 * \return (result) devuelve el resultado de la suma
 *
 */

float addFloat(float *operator1, float *operator2)
{
    float result = *operator1 + *operator2;
    return result;
}

/** \brief Realiza la suma de dos numeros **DOUBLE**
 *
 * \param (operator1) recibe el primer operador
 * \param (operator2) recibe el segundo operador
 * \return (result) devuelve el resultado de la suma
 *
 */

double addDouble(double *operator1, double *operator2)
{
    double result = *operator1 + *operator2;
    return result;
}


            /*----------------RESTA----------------*/


/** \brief Realiza la resta de dos numeros **SHORT**
 *
 * \param (operator1) recibe el primer operador
 * \param (operator2) recibe el segundo operador
 * \return (result) devuelve el resultado de la resta
 *
 */

short int subtractShortInt(short int *operator1, short int *operator2)
{
    short int result = *operator1 - *operator2;
    return result;
}

/** \brief Realiza la resta de dos numeros **INT**
 *
 * \param (operator1) recibe el primer operador
 * \param (operator2) recibe el segundo operador
 * \return (result) devuelve el resultado de la resta
 *
 */

int subtractInt(int *operator1, int *operator2)
{
    int result = *operator1 - *operator2;
    return result;
}

/** \brief Realiza la resta de dos numeros **LONG**
 *
 * \param (operator1) recibe el primer operador
 * \param (operator2) recibe el segundo operador
 * \return (result) devuelve el resultado de la resta
 *
 */

long int subtractLongInt(long int *operator1, long int *operator2)
{
    long int result = *operator1 - *operator2;
    return result;
}

/** \brief Realiza la resta de dos numeros **FLOAT**
 *
 * \param (operator1) recibe el primer operador
 * \param (operator2) recibe el segundo operador
 * \return (result) devuelve el resultado de la resta
 *
 */

float subtractFloat(float *operator1, float *operator2)
{
    float result = *operator1 - *operator2;
    return result;
}

/** \brief Realiza la resta de dos numeros **DOUBLE**
 *
 * \param (operator1) recibe el primer operador
 * \param (operator2) recibe el segundo operador
 * \return (result) devuelve el resultado de la resta
 *
 */

double subtractDouble(double *operator1, double *operator2)
{
    double result = *operator1 - *operator2;
    return result;
}


            /*----------------MULTIPLICACION----------------*/


/** \brief Realiza la multiplicacion de dos numeros **SHORT**
 *
 * \param (operator1) recibe el primer operador
 * \param (operator2) recibe el segundo operador
 * \return (result) devuelve el resultado de la multiplicacion
 *
 */

short int multiplyShortInt(short int *operator1, short int *operator2)
{
    short int result = *operator1 * *operator2;
    return result;
}

/** \brief Realiza la multiplicacion de dos numeros **INT**
 *
 * \param (operator1) recibe el primer operador
 * \param (operator2) recibe el segundo operador
 * \return (result) devuelve el resultado de la multiplicacion
 *
 */

int multiplyInt(int *operator1, int *operator2)
{
    int result = *operator1 * *operator2;
    return result;
}

/** \brief Realiza la multiplicacion de dos numeros **LONG**
 *
 * \param (operator1) recibe el primer operador
 * \param (operator2) recibe el segundo operador
 * \return (result) devuelve el resultado de la multiplicacion
 *
 */

long int multiplyLongInt(long int *operator1, long int *operator2)
{
    long int result = *operator1 * *operator2;
    return result;
}

/** \brief Realiza la multiplicacion de dos numeros **FLOAT**
 *
 * \param (operator1) recibe el primer operador
 * \param (operator2) recibe el segundo operador
 * \return (result) devuelve el resultado de la multiplicacion
 *
 */

float multiplyFloat(float *operator1, float *operator2)
{
    float result = *operator1 * *operator2;
    return result;
}

/** \brief Realiza la multiplicacion de dos numeros **DOUBLE**
 *
 * \param (operator1) recibe el primer operador
 * \param (operator2) recibe el segundo operador
 * \return (result) devuelve el resultado de la multiplicacion
 *
 */

double multiplyDouble(double *operator1, double *operator2)
{
    double result = *operator1 * *operator2;
    return result;
}


            /*----------------DIVISION----------------*/


/** \brief Realiza la division de dos numeros **SHORT**, excepto cuando *operator2 sea igual a 0
 *
 * \param (operator1) recibe el primer operador
 * \param (operator2) recibe el segundo operador
 * \return (result) La división de operator1 sobre operator2 o '0' cuando operator2 es igual a 0
 *
 */
short int divideShortInt(short int *operator1, short int *operator2)
{
    if(*operator2!=0)
    {
        short int result = *operator1 / *operator2;
        return result;
    }
        else
    {
        return 0;
    }
}

/** \brief Realiza la division de dos numeros **INT**, excepto cuando *operator2 sea igual a 0
 *
 * \param (operator1) recibe el primer operador
 * \param (operator2) recibe el segundo operador
 * \return (result) La división de operator1 sobre operator2 o '0' cuando operator2 es igual a 0
 *
 */
int divideInt(int *operator1, int *operator2)
{
    if(*operator2!=0)
    {
        int result = *operator1 / *operator2;
        return result;
    }
        else
    {
        return 0;
    }
}

/** \brief Realiza la division de dos numeros **LONG**, excepto cuando *operator2 sea igual a 0
 *
 * \param (operator1) recibe el primer operador
 * \param (operator2) recibe el segundo operador
 * \return (result) La división de operator1 sobre operator2 o '0' cuando operator2 es igual a 0
 *
 */
long int divideLongInt(long int *operator1, long int *operator2)
{
    if(*operator2!=0)
    {
        long int result = *operator1 / *operator2;
        return result;
    }
        else
    {
        return 0;
    }
}

/** \brief Realiza la division de dos numeros **FLOAT**, excepto cuando *operator2 sea igual a 0
 *
 * \param (operator1) recibe el primer operador
 * \param (operator2) recibe el segundo operador
 * \return (result) La división de operator1 sobre operator2 o '0' cuando operator2 es igual a 0
 *
 */
float divideFloat(float *operator1, float *operator2)
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

/** \brief Realiza la division de dos numeros **DOUBLE**, excepto cuando *operator2 sea igual a 0
 *
 * \param (operator1) recibe el primer operador
 * \param (operator2) recibe el segundo operador
 * \return (result) La división de operator1 sobre operator2 o '0' cuando operator2 es igual a 0
 *
 */
double divideDouble(double *operator1, double *operator2)
{
    if(*operator2!=0)
    {
        double result = *operator1 / *operator2;
        return result;
    }
        else
    {
        return 0;
    }
}


            /*----------------FACTORIAL----------------*/


/** \brief Calcula el factorial de un numero **SHORT**
 *
 * \param (operator1) recibe un operador
 * \return (result) devuelve el factorial de un numero
 *
 */
long factorialShortInt (short int *operator1)
{
    int counter;
    int operInt1 = (int)*operator1; // SE CASTEA EL DATO INGRESADO POR EL USUARIO A UN INT PARA SER EVALUADO POR LA FUNCION
    long result = 1; // POR CONVENCION, 0! = 1
    for (counter = 1; counter<= operInt1 ; counter++){
        result*=counter;
    }
    return result;
}

/** \brief Calcula el factorial de un numero **INT**
 *
 * \param (operator1) recibe un operador
 * \return (result) devuelve el factorial de un numero
 *
 */
long factorialInt (int *operator1)
{
    int counter;
    int operInt1 = *operator1; // SE CASTEA EL DATO INGRESADO POR EL USUARIO A UN INT PARA SER EVALUADO POR LA FUNCION
    long result = 1; // POR CONVENCION, 0! = 1
    for (counter = 1; counter<= operInt1 ; counter++){
        result*=counter;
    }
    return result;
}

/** \brief Calcula el factorial de un numero **LONG**
 *
 * \param (operator1) recibe un operador
 * \return (result) devuelve el factorial de un numero
 *
 */
long factorialLongInt (long int *operator1)
{
    int counter;
    int operInt1 = (int)*operator1; // SE CASTEA EL DATO INGRESADO POR EL USUARIO A UN INT PARA SER EVALUADO POR LA FUNCION
    long result = 1; // POR CONVENCION, 0! = 1
    for (counter = 1; counter<= operInt1 ; counter++){
        result*=counter;
    }
    return result;
}

/** \brief Calcula el factorial de un numero **FLOAT**
 *
 * \param (operator1) recibe un operador
 * \return (result) devuelve el factorial de un numero
 *
 */
long factorialFloat (float *operator1)
{
    int counter;
    int operInt1 = (int)*operator1; // SE CASTEA EL DATO INGRESADO POR EL USUARIO A UN INT PARA SER EVALUADO POR LA FUNCION
    long result = 1; // POR CONVENCION, 0! = 1
    for (counter = 1; counter<= operInt1 ; counter++){
        result*=counter;
    }
    return result;
}

/** \brief Calcula el factorial de un numero **DOUBLE**
 *
 * \param (operator1) recibe un operador
 * \return (result) devuelve el factorial de un numero
 *
 */
long factorialDouble (double *operator1)
{
    int counter;
    int operInt1 = (int)*operator1; // SE CASTEA EL DATO INGRESADO POR EL USUARIO A UN INT PARA SER EVALUADO POR LA FUNCION
    long result = 1; // POR CONVENCION, 0! = 1
    for (counter = 1; counter<= operInt1 ; counter++){
        result*=counter;
    }
    return result;
}
