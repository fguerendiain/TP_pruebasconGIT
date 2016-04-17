
            /*----------------SUMA----------------*/

short int addShortInt(short int *operator1, short int *operator2);  /**< Realiza la suma de dos numeros **SHORT** */

int addInt(int *operator1, int *operator2); /**< Realiza la suma de dos numeros **INT** */

long int addLongInt(long int *operator1, long int *operator2);  /**< Realiza la suma de dos numeros **LONG** */

float addFloat(float *operator1, float *operator2); /**< Realiza la suma de dos numeros **FLOAT** */

double addDouble(double *operator1, double *operator2); /**< Realiza la suma de dos numeros **DOUBLE** */


            /*----------------RESTA----------------*/

short int subtractShortInt(short int *operator1, short int *operator2); /**< Realiza la resta de dos numeros **SHORT** */

int subtractInt(int *operator1, int *operator2);    /**< Realiza la resta de dos numeros **INT** */

long int subtractLongInt(long int *operator1, long int *operator2); /**< Realiza la resta de dos numeros **LONG** */

float subtractFloat(float *operator1, float *operator2);    /**< Realiza la resta de dos numeros **FLOAT** */

double subtractDouble(double *operator1, double *operator2);    /**< Realiza la resta de dos numeros **DOUBLE** */


            /*----------------MULTIPLICACION----------------*/

short int multiplyShortInt(short int *operator1, short int *operator2); /**< Realiza la multiplicacion de dos numeros **SHORT** */

int multiplyInt(int *operator1, int *operator2);    /**< Realiza la multiplicacion de dos numeros **INT** */

long int multiplyLongInt(long int *operator1, long int *operator2); /**< Realiza la multiplicacion de dos numeros **LONG** */

float multiplyFloat(float *operator1, float *operator2);    /**< Realiza la multiplicacion de dos numeros **FLOAT** */

double multiplyDouble(double *operator1, double *operator2);    /**< Realiza la multiplicacion de dos numeros **DOUBLE** */


            /*----------------DIVISION----------------*/

short int divideShortInt(short int *operator1, short int *operator2);   /**< Realiza la division de dos numeros **SHORT**, excepto cuando *operator2 sea igual a 0 */

int divideInt(int *operator1, int *operator2);  /**<  Realiza la division de dos numeros **INT**, excepto cuando *operator2 sea igual a 0 */

long int divideLongInt(long int *operator1, long int *operator2);   /**< Realiza la division de dos numeros **LONG**, excepto cuando *operator2 sea igual a 0 */

float divideFloat(float *operator1, float *operator2);  /**< Realiza la division de dos numeros **FLOAT**, excepto cuando *operator2 sea igual a 0 */

double divideDouble(double *operator1, double *operator2);  /**< Realiza la division de dos numeros **DOUBLE**, excepto cuando *operator2 sea igual a 0 */


            /*----------------FACTORIAL----------------*/

long factorialShortInt (short int *operator1); /**< Calcula el factorial de un numero **SHORT** */

long factorialInt (int *operator1);   /**< Calcula el factorial de un numero **INT** */

long factorialLongInt (long int *operator1);  /**< Calcula el factorial de un numero **LONG** */

long factorialFloat (float *operator1); /**< Calcula el factorial de un numero **FLOAT** */

long factorialDouble (double *operator1);    /**< Calcula el factorial de un numero **DOUBLE** */

