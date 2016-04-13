#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int legajo;
    char nombre[51];
    char apellido[51];
    float salario;
    char sector;
    long int fechaIngreso;
    char flagEstado;
}Empleados;

int main()
{
    Empleados nomina[10000];

    do
    {
       printMenu()
       userInput=getUserInput();

       switch(userInput);

        case 1 ://ALTA
        numeroUltimoLegajo(array, lenght); //recorre buscando el maximo y suma 1 numero de legajo
        posicionLibre(array, lenght); //recorre buscando el estado libre
        cargaDatos(array, lenght); //solicita datos al usuario y los carga en posicion libre

        /*DESARROLLAR PARA BIBLIOTECA*/
        getInt(*userImput,"mensaje", min, max, "mensaje Error");
        getfloat(*userImput,"mensaje", min, max, "mensaje Error");
        getChar(*userImput,"mensaje", "si", "no", "mensaje Error");
        getString(*userImput,"mensaje", cantMinLetras,cantMaxLetras,"MensajeError");
        printMenu("");
        /*devuelven si pudo o no realizar la tarea y guarda lo ingresado en userInput*/

        ; //recorre el array nomina y busca el primer miembro estado en 0, devolviendo el indice
        solicitarIngreso(empleado); //solicita al usuario ingresar los miembros de la estructura en la posicion pasada como parametro
        break;

        case 2 : // MODIFICAR
        controlState=chekStatus(); //recorre el array nomina y busca por legajo el ingresado por el usuario revisa si el miembro estado se encuentra en 1 o 0 y arroja un mensaje indicando si existe o no
        if(controlState == 0)
            {
                solicitarIngreso(empleado); //solicita al usuario ingresar los miembros de la estructura en la posicion pasada como parametro
            }

    }while(opcion);


}
