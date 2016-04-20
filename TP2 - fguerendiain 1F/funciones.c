#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "validations.h"
#include "funciones.h"
#include "../ownLibraries/userInputOutput.h"
#include "../ownLibraries/screenSystemShow.h"

#define MAXTRIES 3
#define STRINGBUFFER 4000

#define ADD 1
#define ERREASE 2
#define PRINTLIST 3
#define PRINTGRAPHIC 4
#define EXIT 5

/** \brief ejecuta la opcion elegida por el usuario
 * \param (option) recibe opcion ingresada por el usuario
 * \param (person) recibe la estructura persona
 * \param (personLenght) recibe el tamaño del array persona
 * \return (0 = finaliza el programa | 1 = continua ejecutando)
 */

int runFunctionMenu(int option, Epeople *person, long int personLenght)
{
    int exit = 1;

    switch(option)
    {
        case ADD:
            cleanScreen();
            addNewPerson(person,personLenght);
          break;

        case ERREASE:
            cleanScreen();
            delPerson(person,personLenght);
        break;

        case PRINTLIST:
            cleanScreen();
            printListOfPeople(person,personLenght);
        break;

        case PRINTGRAPHIC:
            cleanScreen();
        break;

        case EXIT:
            exit = 0;
        break;
    }
    return exit;
}

/** \brief realiza el alta de una nueva persona validando disponibilidad
 * \param (person) recibe la estructura persona
 * \param (personLenght) recibe el tamaño del array persona
 * \return 0 se realizo la carga, -1 no se pudo realizar la carga
 *
 */

int addNewPerson(Epeople *person, long int personLenght)
{
    long int index;
    int checkName;
    int checkLastName;
    int checkAge;
    int checkDni;

    index=searchFreeIndex(person,personLenght);

    if (index!= -1)
    {
        checkName = getUserInputString(person[index].name,3,30,"Ingrese el nombre de la persona:\n","Por favor ingrese un nombre valido:\n",STRINGBUFFER,MAXTRIES);
        checkLastName = getUserInputString(person[index].lastName,3,30,"Ingrese el apellido de la persona:\n","Por favor ingrese un apellido valido:\n",STRINGBUFFER,MAXTRIES);
        checkAge = getUserInputShortInt(&person[index].age,0,120,"Ingrese la edad de la persona:\n","Por favor ingrese una edad valida:\n",MAXTRIES);
        checkDni = getUserInputString(&person[index].dni,9,10,"Ingrese el DNI de la persona:\n","Por favor ingrese DNI valido:\n",STRINGBUFFER,MAXTRIES);

        if (checkName != 0)
        {
            printf("\nNombre invalido, por favor vuelva a intentarlo\n");
            erradicateStdin();
            pauseScreen();
        }
        else if (checkLastName != 0)
        {
            printf("\nApellido invalido, por favor vuelva a intentarlo\n");
            erradicateStdin();
            pauseScreen();
        }
        else if (checkAge != 0)
        {
            printf("\nEdad invalida, por favor vuelva a intentarlo\n");
            erradicateStdin();
            pauseScreen();
        }
        else if (checkDni != 0)
        {
            printf("\nDNI invalido, por favor vuelva a intentarlo\n");
            erradicateStdin();
            pauseScreen();
        }
        else
        {
            person[index].state = 1;
            printf("\nLos datos se cargaron correctamente\n");
            erradicateStdin();
            pauseScreen();
        }
    }
    else
    {
        printf("No existen posiciones libres,\npor favor borre alguna para poder ingresar nuevos datos\n\n");
        erradicateStdin();
        pauseScreen();
        return -1;
    }
    return 0;
}

/** \brief busca el primer indice libre
 * \param (person) recibe la estructura persona
 * \param (personLenght) recibe el tamaño del array persona
 * \return devuelve el numero del indice o -1 en caso que no haya posiciones libres
 *
 */

long searchFreeIndex(Epeople *person, long int personLenght)
{
    long int i;

    for(i=0; i < personLenght; i++)
    {
        if(person[i].state == 0)
            return i;
    }
    return -1;
}

/** \brief inicializa en 0 los campos state y age del array person
 * \param (person) recibe la estructura persona
 * \param (personLenght) recibe el tamaño del array persona
 *
 */

void intializeArrayState(Epeople *person, long int personLenght)
{
    long int i;
    long int j;
    long int k;

    for(i=0; i < personLenght; i++)
    {
        person[i].state = 0;
        person[i].age = 0;

        for(j=0; j<31; j++)
        {
            person[i].name[j] = '\0';
            person[i].lastName[j] = '\0';

            for(k=0;k<11; k++)
            {
                person[i].dni[k] = '\0';
            }
        }
    }
}

/** \brief borrado logido de un elemento de la estructura person
 * \param (person) recibe la estructura persona
 * \param (personLenght) recibe el tamaño del array persona
 *
 */

void delPerson(Epeople *person, long int personLenght)
{
    long int index;

    getUserInputLongInt(&index,0,personLenght,"Ingrese la posicion a eliminar:\n","Por favor, ingrese una posicion valida:\n",MAXTRIES);

    if(person[index].state != 0)
    {
        person[index].state = 0;
        printf("Se eliminaron los datos de la posicion %ld\n", index);
        pauseScreen();
    }
    else
    {
        printf("La posicion %ld se encuentra libre\n", index);
        pauseScreen();
    }
}

/** \brief imprime todos los elementos de person con state en 1
 * \param (person) recibe la estructura persona
 * \param (personLenght) recibe el tamaño del array persona
 *
 */

void printListOfPeople(Epeople *person, long int personLenght)
{
    long int i;

    sortArrayByName(person,personLenght);

    printf("INDICE\t\tNOMBRE\t\tAPELLIDO\t\tEDAD\t\tDNI\n");

    for(i=0 ; i< personLenght; i++)
    {
            if(person[i].state != 0)
            {
                printf("%ld\t\t%s\t\t%s\t\t%hi\t\t%s\n",i,person[i].name,person[i].lastName,person[i].age,person[i].dni);
            }
    }
    pauseScreen();
}

/** \brief Ordena los elementos alfabeticamente por nombre de persona
 * \param (person) recibe la estructura persona
 * \param (personLenght) recibe el tamaño del array persona
 *
 */

void sortArrayByName(Epeople *person, long int personLenght)
{
    long i;
    long j;
    Epeople auxPerson;

    for(i=0; i<personLenght-1; i++)
    {
        for(j=i+1; j<personLenght; j++)
        {
            if(strcmp(person[i].name,person[j].name)>0)
            {
                auxPerson = person[i];
                person[i] = person[j];
                person[j] = auxPerson;
            }
        }
    }
}
