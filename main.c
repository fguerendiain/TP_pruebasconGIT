/*
Hacer una calculadora. Para ello el programa iniciar� y contar� con un men� de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular la suma (A+B)
4. Calcular la resta (A-B)
5. Calcular la division (A/B)
6. Calcular la multiplicacion (A*B)
7. Calcular el factorial (A!)
8. Calcular todas las operaciones
9. Salir
� Todas las funciones matem�ticas del men� se deber�n realizar en una biblioteca aparte,
que contenga las funciones para realizar las 4 operaciones.
� En el men� deber�n aparecer los valores actuales cargados en los operandos A y B
(donde dice �x� e �y� en el ejemplo, se debe mostrar el n�mero cargado)
� Deber�n contemplarse los casos de error (divisi�n por cero, etc)
� Documentar todas las funciones!!
*/

#include "operaciones.h"
#include "validations.h"
#define LIMPIARPANTALLA "clear" // "cls" para windows | "clear" para linux

int main(){
    float valueA = 0;
    float valueB = 0;

    while (1==1){
        printMenu(valueA, valueB);
        int chosenOption = getMenuInputFromUser();
        runFunction(chosenOption, &valueA, &valueB);
        printf("Dale a cualquiera pa seguir");
        scanf("%s");
        system(LIMPIARPANTALLA);
    }
}



