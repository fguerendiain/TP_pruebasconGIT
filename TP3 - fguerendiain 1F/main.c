/*
*   Definir una estructura “movie” con los datos de una pelicula:
*   • Título
*   • Género
*   • Duración
*   • Descripción
*   • Puntaje
*   • Link de imagen
*
*   Realizar un programa que permita agregar, borrar y modificar peliculas en un archivo binario
*   mediante un menú:
*   1. Agregar película
*   2. Borrar película
*   3. Modificar película
*   4. Generar página web
*   5. Salir
*
*   La opción 3, listará las peliculas pero no por pantalla, sino generando un archivo html
*   (descargar template de ejemplo, archivo template.zip).
*   Crear una función que reciba un array de estructuras movie y el nombre del archivo html de
*   salida, y se encargue de generarlo.
*
*   En el archivo de la template, index.html, se encontrará la porción de código html que se debe
*   repetir para cada película, dentro de este bloque, se debe cargar ciertas partes con los datos
*   de cada película, a continuación se muestra un bloque y en color rojo lo que se debe variar
*   según la pelicula.
*/


#include <stdio.h>
#include <stdlib.h>
#include "userInputOutput.h"

int main()
{
    int exit = 1;
    int userOptionMenu;

    do
    {
        printAwesomeMenu("1. Agregar película\n"
                         "2. Borrar película\n"
                         "3. Modificar película\n"
                         "4. Generar página web\n"
                         "5. Salir\n\n");
        getUserInputInt(&userOptionMenu,1,5,"Elija una opcion del menu\n","Por favor ingrese una opcion valida\n",0);
        exit = runFunctionMenu(userOptionMenu,QUANTITY);

    }while(exit);



    return 0;
}
