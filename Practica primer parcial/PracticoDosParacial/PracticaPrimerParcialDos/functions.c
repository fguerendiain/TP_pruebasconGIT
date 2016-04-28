#include <stdio.h>
#include <stdlib.h>
#include "struct."
#include "../../../ownLibraries/screenSystemShow.h"
#include "../../../ownLibraries/userInputOutput.h"


#define ALTAS 1
#define MODIFICAR 2
#define BAJA 3
#define INFORMAR 4
#define LISTAR 5
#define SALIR 6

void runFunctionMenu(Proveedor *suplier, Articulo *producto, int userInput)
{
    if(suplier == NULL || producto == NULL)
    {
        printf("Error de memoria\n\nPor favor, intente nuevamente\n");
        pauseScreen();
        return -1;
    }
    else
    {
        switch(userInput)
        {
            case ALTAS :

            break;

            case MODIFICAR :
            break;

            case BAJA :
            break;

            case INFORMAR :
            break;

            case LISTAR :
            break;

            case SALIR :
            break;
        }

    }
}


setEmptyValuesOff(Proveedor *suplier, Articulos *productos, int arrayLenght)
{
    int i;
    for(i)

}
