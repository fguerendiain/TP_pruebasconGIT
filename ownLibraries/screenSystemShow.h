#ifndef __SCREENSYSTEMSHOW
#define __SCREENSYSTEMSHOW

void printAwesomeMenu(char *menu);   /**< Imprime el menu */

void erradicateStdin();  /**<Consume todo el stdin hasta encontrar un EOF o un "\n", se utiliza en reemplazo del fflush().*/

void pauseScreen();  /**< Pausa el programa hasta que se presiona Enter */

void cleanScreen(); /**< Limpia la pantalla */

int stringSetCase(char *stringToConvert,int option);  /**< convierte una cadena de carateres en mayuscula, minuscula o capital */

#endif //__SCREENSYSTEMSHOW
