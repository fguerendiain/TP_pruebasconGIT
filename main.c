/*
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular la suma (A+B)
4. Calcular la resta (A-B)
5. Calcular la division (A/B)
6. Calcular la multiplicacion (A*B)
7. Calcular el factorial (A!)
8. Calcular todas las operaciones
9. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las 4 operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones!!
*/


#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

#define OPER1 1
#define OPER2 2
#define SUMA 3
#define RESTA 4
#define DIVISION 5
#define MULTIPLICACION 6
#define FACTORIAL 7
#define ALLOPERACIONES 8

int main()
{
    char seguir='s';
    int opcion=0;
    float operandoNum1=0;
    float operandoNum2=0;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;
    float resultadoFactorial;

    while(seguir=='s')
    {
        printf("\n1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        printf("Elija una opcion\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case OPER1 :
                system("clear");
                printf("Ingrese el 1er operando\n");
                scanf("%f",&operandoNum1);
                break;
            case OPER2:
                system("clear");
                printf("Ingrese el 2do operando\n");
                scanf("%f",&operandoNum2);
                break;
            case SUMA:
                system("clear");
                resultadoSuma = suma(&operandoNum1,&operandoNum2);
                printf("\n%.2f + %.2f = %.2f\n", operandoNum1, operandoNum2, resultadoSuma);
                break;
            case RESTA :
                system("clear");
                resultadoResta = resta(&operandoNum1, &operandoNum2);
                printf("\n%.2f - %.2f = %.2f\n", operandoNum1, operandoNum2, resultadoResta);
                break;
            case DIVISION:
                system("clear");
                resultadoDivision = division(&operandoNum1, &operandoNum2);
                printf("\n%.2f : %.2f = %.2f\n", operandoNum1, operandoNum2, resultadoDivision);
                break;
            case MULTIPLICACION :
                system("clear");
                resultadoMultiplicacion = multiplicacion(&operandoNum1, &operandoNum2);
                printf("\n%.2f X %.2f = %.2f\n", operandoNum1, operandoNum2, resultadoMultiplicacion);
                break;
            case FACTORIAL :
                system("clear");
                break;
            case ALLOPERACIONES :
                system("clear");
                break;
            case 9:
                seguir = 'n';
                break;
        }

    }
    return 0;
}


