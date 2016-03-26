#include <stdio.h>
#include <stdlib.h>

void printMenu(float valueA, float valueB){
    printf(
        "1- Ingresar 1er operando (A = %2.f)\n".
        "2- Ingresar 2do operando (B = %2.f)\n".
        "3- Calcular la suma (A+B)\n".
        "4- Calcular la resta (A-B)\n".
        "5- Calcular la division (A/B)\n".
        "6- Calcular la multiplicacion (A*B)\n".
        "7- Calcular el factorial (A!)\n".
        "8- Calcular todas las operacione\n".
        "9- Salir\n",
        valueA,
        valueB
    );
}

int getMenuInputFromUser(){
    int userInput = -1;

    while (userInput == -1){
        printf("Por favor ingrese una opcion del 1 al 9: ");
        int inputValid = scanf("%d",&userInput);

        if (inputValid==1 && (userInput < 1 || userInput > 9)){
            userInput == -1;
        }

        fflush(stdin);
        printf("\n");
    }

    return userInput;
}

float getFloatInputFromUser(){
    float userInput = 0;
    int inputValid = 0;

    while (inputValid == 0){
        inputValid = scanf("%f",&userInput);
        fflush(stdin);

        if (inputValid == 0){
            printf("Por favor ingresá un float\n");
        }else{
            return userInput;
        }
    }
}

#define OPER1 1
#define OPER2 2
#define SUMA 3
#define RESTA 4
#define DIVISION 5
#define MULTIPLICACION 6
#define FACTORIAL 7
#define ALLOPERACIONES 8
#define EXIT 9
void runFunction(int function, float* valueA, float* valueB){
    switch (function){
        case OPER1:
            float userInput = getFloatInputFromUser();
            *valueA = userInput;
        break;
        case OPER2:
            float userInput = getFloatInputFromUser();
            *valueB = userInput;
        break;
        case SUMA:

        break;
        case RESTA:
        break;
        case DIVISION:
        break;
        case MULTIPLICACION:
        break;
        case FACTORIAL:
        break;
        case ALLOPERACIONES:
        break;
        case EXIT:
        break;
    }
}





/** \brief
 *
 * \param optionMenu recibe una cadena de texto con las opciones del menu
 * \param welcomeMessege recibe una cadena de texto, con un mensaje inicial
 * \param ranks recibe un int con la cantidad de opciones validas
 * \param userAttempts recibe un int para limitar la cantidad de ingresos erroneos
 * \return devuelve un tipo de dato entero con la opcion seleccionada por el usuario
 *
 */
/*
int printMenu(char* optionMenu, char* welcomeMessege, int ranks, int userAttempts)
{

    int userDecision = 0;
    int validateInteger =0;
    int errAttempts =0;

    printf("%s",optionMenu);
    printf("%s",welcomeMessege);

    validateInteger = scanf("%d",&userDecision);

    if (validateInteger == 0 )
    {
        do
        {
            errAttempts++;
            printf("Por favor ingrese una opcion del 1 al %d\n",ranks);
            validateInteger = scanf("%d",&userDecision);
        }
        while(validateInteger == 0 || errAttempts != userAttempts || userDecision > ranks || userDecision < 1);

        if (validateInteger == 0)
        {
            system(LIMPIARPANTALLA);
            printf("Usted realizo %d intentos fallidos. Por favor cierre el programa e intente de nuevo",userAttempts);
            exit(0);
        }
    }
    return userDecision;
}*/
/*

contador=0;
do{                                 //EVALUA QUE SE INGRESE UN VALOR PARA OPERAR
    flagValidarOperando = 1;
    system(LIMPIARPANTALLA);
    if (contador==0){
    printf("Ingrese el 1er operando\n");
}else{
    printf("Por favor ingrese un numero valido\n");
}
    flagValidarOperando = scanf("%f",&operandoNum1);
    fflush(stdin);
    contador++;
}while(flagValidarOperando == 0);






if(operandoNum2!=0){ //CASO DE ERROR DIVISION POR 0
    system(LIMPIARPANTALLA);
    resultadoDivision = division(operandoNum1, operandoNum2);
    printf("\n%.2f : %.2f = %.2f\n", operandoNum1, operandoNum2, resultadoDivision);
    break;
}else{
    system(LIMPIARPANTALLA);
    printf("Por favor ingrese un divisor mayor a 0 para realizar la operacion\n\n");
    break;
}
*/
