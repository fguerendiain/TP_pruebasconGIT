/*      Definir una estructura que represente una persona,
        con los campos nombre, edad, dni y un flag de estado.

        Hacer un programa que defina un array de 20 �tems de esta estructura
        y con un men� como el siguiente:

        1. Agregar una persona
        2. Borrar una persona
        3. Imprimir lista ordenada por nombre
        4. Imprimir gr�fico de edades

        Se utilizar� el campo de estado para indicar si el �tem del array esta
        ocupado o no.

        El gr�fico deber� ser un gr�fico de barras en donde se agrupar�n 3 barras:

        � Menores de 18
        � De 19 a 35
        � Mayores de 35.

        En el eje Y se marcar�n la cantidad de personas en el grupo, y en el
        eje X el grupo

        Ejemplo:

                                *
                                *     *
                                *     *     *
                                *     *     *
                                *     *     *
                                *     *     *
                               <18  19-35   >35

        Gr�fico para una estad�stica de 6 personas con edad menor a 18,
        4 personas con edades entre 19 y 35, y 5 personas con edades
        mayores a 35.*/
/*-------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "validations.h"
#include "funciones.h"
#define MSGFIRSTTIME "Eliga una opcion:\n"
#define MSGERROR "Por favor eliga una opcion valida: \n"


void main()
{
    int userImput;
    short int exit;
    int control;
    Epersona persona[20];

    do
    {
        printAwesomeMenu("1- Agregar persona\n"
        "2- Borrar persona\n"
        "3- Imprimir lista ordenada por  nombre\n"
        "4- Imprimir grafico de edades\n"
        "5- Salir\n\n");
        control = getUserInputInt(&userImput,1,5,MSGFIRSTTIME,MSGERROR,3);

        printf("valor %d\n", userImput);
        printf("funcion %d\n\n", control);
        exit = runFunctionMenu(userImput);
    }
    while(exit);
}
