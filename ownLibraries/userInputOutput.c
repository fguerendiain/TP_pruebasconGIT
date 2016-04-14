#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#inlcude "../ownLibraries/screenSystemShow.h"
#inlcude "../ownLibraries/userInputOutput.h"



int getUserInputInt(int *userInput,char *msgFirstTime, int min, int max, char *msgError)
{
    {
    int ret = -1;
    int flagFirstInput = 0;
    int validateUserInput;

    do
    {
        if(flagFirstInput == 0)
        {
            printf("%s",msgFirstTime);
            flagFirstInput++;
        }
        else
        {
            printf("%s",msgError);
        }

        validateUserInput = scanf("%d", userInput);

        if(validateUserInput == 0 || userInput < min || userInput > max)
        {
            return ret;
        }
        erradicateStdin();
    }
    return 0;
    }
}
/*---------------------------------------------------------------------------------------------*/
float getUserInputFloat(float *userInput,char *msgFirstTime, int min, int max, char *msgError)
{
    {
    int ret = -1;
    int flagFirstInput = 0;
    int validateUserInput;

    do
    {
        if(flagFirstInput == 0)
        {
            printf(msgFirstTime);
            flagFirstInput++;
        }
        else
        {
            printf(msgError);
        }

        validateUserInput = scanf("%f", userInput);

        if(validateUserInput == 0 || userInput < min || userInput > max)
        {
            return ret;
        }
        erradicateStdin();
    }
    return 0;
    }
}
/*---------------------------------------------------------------------------------------------*/
char getUserInputChar(char *userInput,char *msgFirstTime, char *msgError)
{
    {
    int ret = -1;
    int flagFirstInput = 0;
    int validateUserInput;

    do
    {
        if(flagFirstInput == 0)
        {
            printf(msgFirstTime);
            flagFirstInput++;
        }
        else
        {
            printf(msgError);
        }

        validateUserInput = scanf("%c", userInput);

        if(validateUserInput == 0)
        {
            return ret;
        }
        erradicateStdin();
    }
    return 0;
    }
}
/*---------------------------------------------------------------------------------------------*/
char getUserInputString(char *userImput,char *msgFirstTime, cantMinLetras,cantMaxLetras,char *msgError)
{
    printf(msgFirstTime);
    gets(userImput);

    if(strlen(userImput) > cantMaxLetras && strlen(userImput) < cantMinLetras)
    {
        ret
    }

}

