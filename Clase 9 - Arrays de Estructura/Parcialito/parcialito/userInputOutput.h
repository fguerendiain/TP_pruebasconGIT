#include "screenSystemShow.h"
#include "userInputOutput.h"
#include "struct.h"


int getUserInputInt(int *userInput,char *msgFirstTime, int min, int max, char *msgError);


float getUserInputFloat(float *userInput,char *msgFirstTime, int min, int max, char *msgError);


char getUserInputChar(char *userInput,char *msgFirstTime, char min, char max, char *msgError);


char getUserInputString(char *userImput,char *msgFirstTime,char *msgError);


printAwesomeMenu(char *menu);

void erradicateStdin();

void pauseScreen();  /**< Pausa el programa hasta que se presiona Enter */
