#include <stdio.h>
#include <stdlib.h>

#define LIMPIARPANTALLA "clear" // "cls" para windows | "clear" para linux
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief Limpia la pantalla
 *
 * \return void
 *
 */

void cleanScreen() /**< Limpia la pantalla */
{
    system(LIMPIARPANTALLA);
}
/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief Solicita al usuario ingresar un numero de tipo float
 *
 * \return Devuelve el valor ingresado por el usuario previamente validado
 *
 */

float getUserNumberInput(int order) /**< Solicita al usuario ingresar un numero de tipo float */
{
    float userFloatInput =0;
    int valideUserInput = 0;
    int flagFirstInput = 0;

    do
    {
        if(flagFirstInput == 0)
        {
            if(order == 1)
            {
                printf("Ingrese el 1er operando: ");
            }
            else
            {
                printf("Ingrese el 2do operando: ");
            }
        }
        else
        {
            printf("Por favor ingrese un valor numerico: ");
        }
        valideUserInput = scanf("%f",&userFloatInput);
    }while(valideUserInput == 0);

    return userFloatInput;
}
/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief imprime el menu en pantalla
 *
 * \param valueA recibe un float para mostrar en el menu como 1er operando
 * \param valueB recibe un float para mostrar en el menu como 2do operando
 * \return void
 *
 */
void printAwesomeMenu(float valueA, float valueB)
{
    cleanScreen();
    printf("1- Ingresar 1er operando (A = %.2f)\n"
           "2- Ingresar 2do operando (B = %.2f)\n"
           "3- Calcular la suma (A+B)\n"
           "4- Calcular la resta (A-B)\n"
           "5- Calcular la division (A/B)\n"
           "6- Calcular la multiplicacion (A*B)\n"
           "7- Calcular el factorial (A!)\n"
           "8- Calcular todas las operacione\n"
           "9- Salir\n",valueA, valueB);
    return;
}
/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief Solicita ingresar una opcion del menu validando la misma
 *
 * \return Devuelve el int ingresado por el usuario
 *
 */
int getMenuUserInput()
{
    int userInput = -1;
    int flagFirstInput = 0;
    int validateUserInput;

    do
    {
        if(flagFirstInput == 0)
        {
            printf("\nIngrese una opcion: ");
            flagFirstInput++;
        }
        else
        {
            printf("\nPor favor, ingrese una opcion valida: ");
        }

        validateUserInput = scanf("%d", &userInput);

        if(validateUserInput == 0 || userInput < 0 || userInput > 9)
        {
            userInput = -1;
        }

        erradicateStdin();

    }
    while(userInput == -1);
    return userInput;
}
/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief Solicita al usuario ingresar dos valores para continuar o no
 *
 * \return devuelve la respuesta del usuario 1 para continuar, 2 para salir
 *
 */

int getUserConfirmToContinue()
{
/*-------------------------------------------------------------------------------------------------------------------*/
    int userAnswer = -1;
    int flagFirstInput = 0;

    do
    {
        if(flagFirstInput == 0)
        {
            printf("Desea Continuar:\n\n1- continuar\n2- salir\n");
            flagFirstInput++;
        }
        else
        {
            printf("Por favor, ingrese una opcion valida:\n\n1- continuar\n2- salir\n");
        }
        scanf("%d",&userAnswer);

        if(userAnswer!=1 && userAnswer!=2)
        {
            userAnswer = -1;
        }

        erradicateStdin();

    }
    while(userAnswer == -1);

    return userAnswer;
}
/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief Consume todo el stdin hasta encontrar un EOF o un "\n", se utiliza en reemplazo del fflush().
 * \return void
 */

void erradicateStdin()
{
    char stdinBuffer;
    while((stdinBuffer = getchar()) != '\n' && stdinBuffer != EOF);

    return;
}
