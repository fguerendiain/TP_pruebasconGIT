#include "screenSystemShow.h"
#include "userInputOutput.h"
#include "struct.h"



int getUserInputInt(int *userInput, int min, int max, char *msgFirstTime, char *msgError, int maxTries);    /**< recibe y valida el ingreso de un entero por parte del usuario */


float getUserInputFloat(float *userInput,char *msgFirstTime, int min, int max, char *msgError);


char getUserInputChar(char *userInput,char *msgFirstTime, char min, char max, char *msgError);


char getUserInputString(char *userImput,char *msgFirstTime,char *msgError);


