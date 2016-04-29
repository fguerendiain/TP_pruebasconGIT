#ifndef __USERINPUTOUTPUT
#define __USERINPUTOUTPUT


int getUserInputShortInt(short int *userInput, short int min, short int max, char *msgFirstTime, char *msgError, int maxTries);   /**< recibe y valida el ingreso de un **SHORT INT** por parte del usuario */

int getUserInputInt(int *userInput, int min, int max, char *msgFirstTime, char *msgError, int maxTries);  /**< recibe y valida el ingreso de un **INT** por parte del usuario */

int getUserInputLongInt(long int *userInput, long int min, long int max, char *msgFirstTime, char *msgError, int maxTries);   /**< recibe y valida el ingreso de un **LONG INT** por parte del usuario */

int getUserInputFloat(float *userInput, float min, float max, char *msgFirstTime, char *msgError, int maxTries);  /**< recibe y valida el ingreso de un **FLOAT** por parte del usuario */

int getUserInputDouble(double *userInput, double min, double max, char *msgFirstTime, char *msgError, int maxTries);  /**< recibe y valida el ingreso de un **DOUBLE** por parte del usuario */

int getUserInputChar(char *userInput, char *msgFirstTime, char *msgError, int maxTries);  /**< recibe y valida el ingreso de un **CHAR** por parte del usuario */

int getUserInputString(char *userInput, long min, long max, char *msgFirstTime, char *msgError, long bufferSize, int maxTries);   /**< recibe y valida el ingreso de un **STRING** por parte del usuario */

int getUserConfirmToContinue(int intYes, int intNo, char charYes, char charNo, char *msgFirstTime, char *msgError,int charOrIntMode, int maxTries); /**< solicitud booleana de confirmacion */

#endif //__USERINPUTOUTPUT
