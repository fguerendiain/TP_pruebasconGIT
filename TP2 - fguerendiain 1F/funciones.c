#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "validations.h"
#include "funciones.h"
#include "../ownLibraries/userInputOutput.h"
#include "../ownLibraries/screenSystemShow.h"
#define MAXTRIES 0
#define STRINGBUFFER 4000


/*
        1. Agregar una persona
        2. Borrar una persona
        3. Imprimir lista ordenada por nombre
        4. Imprimir gráfico de edades
        5. Salir
*/

/** \brief Ejecuta la opcion elegida por el usuario
 * \param opcion recibe un int con la opcion ingresada por el usuario
 * \return luego de ejecutar la opcion devuelve el valor par continuar o no
 */

int runFunctionMenu(int option, Epeople *person, long personLenght)
{
    int exit = 1;
    switch(option)
    {
        case 1:
            addNewPerson(person,personLenght);
          break;

        case 2:
        break;

        case 3:
        break;

        case 4:
        break;

        case 5:
            exit = 0;
        break;
    }
    return exit;
}

/** \brief permite dar de alta una nueva persona siempre que se encuentren posiciones disponibles
 *
 * \param array donde realizar la carga
 * \param tamaño del array
 * \return 0 se realizo la carga correctamente, -1 no se pudo realizar la carga
 *
 */

int addNewPerson(Epeople *person, long personLenght)
{
    long index;
    int checkName;
    int checkLastName;
    int checkAge;
    int checkDni;

    cleanScreen();

    index=searchFreeIndex(person,personLenght);

    if (index!= -1)
    {
        checkName = getUserInputString(person[index].name,3,30,"Ingrese el nombre de la persona:\n","Por favor ingrese un nombre valido:\n",STRINGBUFFER,MAXTRIES);
        checkLastName = getUserInputString(person[index].lastName,3,30,"Ingrese el apellido de la persona:\n","Por favor ingrese un apellido valido:\n",STRINGBUFFER,MAXTRIES);
        checkAge = getUserInputInt(&person[index].age,0,120,"Ingrese la edad de la persona:\n","Por favor ingrese una edad valida:\n",MAXTRIES);
        checkDni = getUserInputString(person[index].dni,7,8,"Ingrese el DNI de la persona:\n","Por favor ingrese DNI valido:\n",STRINGBUFFER,MAXTRIES);

        if (checkName == -1 || checkLastName == -1 || checkAge == -1 || checkDni == -1)
        {
            printf("Uno o mas datos no fueron ingresados correctamente, por favor vuelva a intentarlo\n");
            erradicateStdin();
            pauseScreen();
        }
        else
        {
            person[index].state = 1;
            printf("Los datos se cargaron correctamente\n");
            erradicateStdin();
            pauseScreen();
        }
    }
    else
    {
        printf("No existen posiciones libres, por favor borre alguna\n posicion para poder ingresar nuevos datos\n\n");
        erradicateStdin();
        pauseScreen();
        return -1;
    }
    return 0;
}

/** \brief recorre el array buscando el primer indice libre
 *
 * \param array donde buscar
 * \param  extencion del array
 * \return devuelve el numero del indice o -1 en caso que no haya posiciones libres
 *
 */

long searchFreeIndex(Epeople *person, long personLenght)
{
    long i;

    for(i=0; i < personLenght; i++)
    {
        if(person[i].state == 0)
            return i;
    }
    return -1;
}

/** \brief inicializa en 0 los campos de estado y edad del array
 *
 * \param Array a recorrer
 * \param tamaño del array
 *
 */

void intializeArrayState(Epeople *person, long personLenght)
{
    long i;

    for(i=0; i < personLenght; i++)
    {
        person[i].state = 0;
        person[i].age = 0;
    }
}
