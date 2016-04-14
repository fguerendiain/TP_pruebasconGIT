#include <stdio.h>
#include <stdlib.h>
#include "screenSystemShow.h"
#include "userInputOutput.h"

void printAwesomeMenu(char *menu);   /**< Imprime el menu */

void erradicateStdin();  /**<Consume todo el stdin hasta encontrar un EOF o un "\n", se utiliza en reemplazo del fflush().*/

void pauseScreen();  /**< Pausa el programa hasta que se presiona Enter */
