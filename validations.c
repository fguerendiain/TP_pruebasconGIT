#include <stdio.h>
#include <stdlib.h>

#define LIMPIARPANTALLA "clear" // "cls" para windows | "clear" para linux
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief imprime el menu en pantalla
 *
 * \param valueA recibe un float para mostrar en el menu como 1er operando
 * \param valueB recibe un float para mostrar en el menu como 2do operando
 * \return void
 *
 */
void printMenu(float valueA, float valueB)
{
    system(LIMPIARPANTALLA);
    printf("1- Ingresar 1er operando (A = %2.f)\n"
           "2- Ingresar 2do operando (B = %2.f)\n"
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
        fflush(stdin);
        validateUserInput = 1;
        if(flagFirstInput == 0)
        {
            printf("\nIngrese una opcion: ");
            flagFirstInput++;
        }
        else
        {
            printf("\nPor favor, ingrese una opcion valida: ");
        }
        validateUserInput = scanf("%d",&userInput);
        if (validateUserInput == 0 || (userInput < 0 || userInput > 9))
        {
            userInput = -1;
        }
    }
    while(userInput == -1);
    fflush(stdin);
    return userInput;
}
/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief Solicita al usuario ingresar dos valores para continuar o no
 *
 * \return devuelve un int con el dato ingresado por el usuario
 *
 */

int getUserConfirmToContinue()
{
    int validateUserAnswer = -1;
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
        fflush(stdin);
        scanf("%d",&validateUserAnswer);

        switch(validateUserAnswer)
        {
            case 1 :
                validateUserAnswer = 1;
            break;
            case 2 :
                validateUserAnswer = 2;
            break;
            default :
                validateUserAnswer = -1;
        }
    }
    while(validateUserAnswer == -1);

    return validateUserAnswer;
}
