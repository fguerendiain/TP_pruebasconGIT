#include <stdio.h>
#include <stdlib.h>
#include "struct."
#include "../../../ownLibraries/screenSystemShow.h"
#include "../../../ownLibraries/userInputOutput.h"

#define CANTIDAD 1000

int main()
{
    Proveedor suplier[CANTIDAD];
    Articulo producto[CANTIDAD];

    int userInput;
    int exit = 1;


    do
    {
        printAwesomeMenu("1. ALTAS:\n"
                         "2. MODIFICAR:\n"
                         "3. BAJA:\n"
                         "4. INFORMAR:\n"
                         "5. LISTAR:\n"
                         "6. SALIR:\n");
        getUserInputInt($userInput,0,6,"Elija una opcion","Por favor elija una opcion valida",0);
        runFunctionMenu(suplier,producto,userInput);

    }while(exit);

    return 0;
}
