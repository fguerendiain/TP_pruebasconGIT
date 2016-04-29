/********************************************************************
*********************************************************************
****
****    PRORGAMACION I / LABORATORIO I
****    DIVISION 1#F
****    ALUMNO: GUERENDIAIN, FRANCO JAVIER
****
****    TRABAJO PRACTICO #2
****
****    FECHA DE ENTREGA - 29/04/2016
****
*********************************************************************
*********************************************************************/


/*      Definir una estructura que represente una persona,
        con los campos nombre, edad, dni y un flag de estado.

        Hacer un programa que defina un array de 20 ítems de esta estructura
        y con un menú como el siguiente:

        1. Agregar una persona
        2. Borrar una persona
        3. Imprimir lista ordenada por nombre
        4. Imprimir gráfico de edades

        Se utilizará el campo de estado para indicar si el ítem del array esta
        ocupado o no.

        El gráfico deberá ser un gráfico de barras en donde se agruparán 3 barras:

        • Menores de 18
        • De 19 a 35
        • Mayores de 35.

        En el eje Y se marcarán la cantidad de personas en el grupo, y en el
        eje X el grupo

        Ejemplo:

                                *
                                *           *
                                *     *     *
                                *     *     *
                                *     *     *
                                *     *     *
                               <18  19-35   >35

        Gráfico para una estadística de 6 personas con edad menor a 18,
        4 personas con edades entre 19 y 35, y 5 personas con edades
        mayores a 35.*/
/*-------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "../ownLibraries/userInputOutput.h"
#include "../ownLibraries/screenSystemShow.h"

#define EPEOPLELENGTH 20
#define MSGFIRSTTIME "Eliga una opcion:\n"
#define MSGERROR "Por favor eliga una opcion valida: \n"


int main()
{
    int userInput;
    short int exit;
    Epeople person[EPEOPLELENGTH];

    intializeArrayState(person,EPEOPLELENGTH);

    do
    {
        printAwesomeMenu(   "1- Agregar persona\n"
                            "2- Borrar persona\n"
                            "3- Imprimir lista ordenada por nombre\n"
                            "4- Imprimir grafico de edades\n"
                            "5- Salir\n\n");
        getUserInputInt(&userInput,1,5,MSGFIRSTTIME,MSGERROR,2);
        exit = runFunctionMenu(userInput,person,EPEOPLELENGTH);
    }
    while(exit);

    return 0;
}

