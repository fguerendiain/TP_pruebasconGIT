#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "validations.h"
#include "funciones.h"



/** \brief Ejecuta la opcion elegida por el usuario
 * \param opcion recibe un int con la opcion ingresada por el usuario
 * \return luego de ejecutar la opcion devuelve el valor par continuar o no
 */
int runFunctionMenu(int opcion) /**< Ejecuta la opcion elegida por el usuario */
{
    int seguir = 1;
    switch(opcion)
    {
        case 1:

        break;
        case 2:
        break;
        case 3:
        break;
        case 4:
        break;
        case 5:
            seguir = 0;
        break;
    }
    return seguir;
}


//funcion para controlar errores
