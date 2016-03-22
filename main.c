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
#define EXIT 9
#define LIMPIARPANTALLA "cls" // "cls" para windows | "clear" para linux

int main()
{

    //VARIABLES DEL MENU
    char seguir='s';
    int opcion = 0;

    //VARIABLES DE ENTRADA
    float operandoNum1 = 0;
    float operandoNum2 = 0;

    //VARIABLES DE SALIDA
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;
    int resultadoFactorial;


    while(seguir=='s')
    {
        printf("\n1- Ingresar 1er operando (A = %.2f)\n",operandoNum1);
        printf("2- Ingresar 2do operando (B = %.2f)\n", operandoNum2);
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
                do{
                    int flag;
                    flag = 1;
                    system(LIMPIARPANTALLA);
                    printf("Ingrese el 1er operando\n");
                    flag = scanf("%f",&operandoNum1);
                }while(flag == 0);
                break;

            case OPER2:
                system(LIMPIARPANTALLA);
                printf("Ingrese el 2do operando\n");
                scanf("%f",&operandoNum2);
                break;

            case SUMA:
                system(LIMPIARPANTALLA);
                resultadoSuma = suma(operandoNum1,operandoNum2);
                printf("\n%.2f + %.2f = %.2f\n", operandoNum1, operandoNum2, resultadoSuma);
                break;

            case RESTA :
                system(LIMPIARPANTALLA);
                resultadoResta = resta(operandoNum1, operandoNum2);
                printf("\n%.2f - %.2f = %.2f\n", operandoNum1, operandoNum2, resultadoResta);
                break;

            case DIVISION:
                if(operandoNum2!=0){ //CASO DE ERROR DIVISION POR 0

                    //A REVISAR: SI UN NUMERO ES DIVIDIDO POR OTRO MAS GRANDE EL RESULTADO DA 0

                    system(LIMPIARPANTALLA);
                    resultadoDivision = division(operandoNum1, operandoNum2);
                    printf("\n%.2f : %.2f = %.2f\n", operandoNum1, operandoNum2, resultadoDivision);
                    break;
                }else{
                    system(LIMPIARPANTALLA);
                    printf("Por favor ingrese un divisor mayor a 0 para realizar la operacion\n\n");
                    break;
                }

            case MULTIPLICACION :
                system(LIMPIARPANTALLA);
                resultadoMultiplicacion = multiplicacion(operandoNum1, operandoNum2);
                printf("\n%.2f x %.2f = %.2f\n", operandoNum1, operandoNum2, resultadoMultiplicacion);
                break;

            case FACTORIAL :
                system(LIMPIARPANTALLA);
                resultadoFactorial = factorial(operandoNum1);
                printf("\n%d! = %d\n", (int)operandoNum1, resultadoFactorial);
                break;

            case ALLOPERACIONES :
                system(LIMPIARPANTALLA);
                if(operandoNum2!=0){ //CASO DE ERROR DIVISION POR 0

                    system(LIMPIARPANTALLA);

                    resultadoSuma = suma(operandoNum1,operandoNum2);
                    printf("\n%.2f + %.2f = %.2f\n", operandoNum1, operandoNum2, resultadoSuma);

                    resultadoResta = resta(operandoNum1, operandoNum2);
                    printf("\n%.2f - %.2f = %.2f\n", operandoNum1, operandoNum2, resultadoResta);

                    resultadoDivision = division(operandoNum1, operandoNum2);
                    printf("\n%.2f : %.2f = %.2f\n", operandoNum1, operandoNum2, resultadoDivision);

                    resultadoMultiplicacion = multiplicacion(operandoNum1, operandoNum2);
                    printf("\n%.2f x %.2f = %.2f\n", operandoNum1, operandoNum2, resultadoMultiplicacion);

                    resultadoFactorial = factorial(operandoNum1);
                    printf("\n%d! = %d\n", (int)operandoNum1, resultadoFactorial);

                    break;

                }else{
                    system(LIMPIARPANTALLA);
                    printf("Por favor ingrese un divisor mayor a 0 para realizar todas las operaciones\n\n");
                    break;
                }

            case EXIT :
                seguir = 'n';
                break;

            case default :                      //CASO DE ERROR, SE INGRESA UNA OPCION DISTINTA A LAS POSIBLES
                system(LIMPIARPANTALLA);
                printf("Ingrese una opcion valida");
        }

    }
    return 0;
}



