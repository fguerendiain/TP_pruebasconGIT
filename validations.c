#define LIMPIARPANTALLA "clear" // "cls" para windows | "clear" para linux

/** \brief
 *
 * \param optionMenu recibe una cadena de texto con las opciones del menu
 * \param welcomeMessege recibe una cadena de texto, con un mensaje inicial
 * \param ranks recibe un int con la cantidad de opciones validas
 * \param userAttempts recibe un int para limitar la cantidad de ingresos erroneos
 * \return devuelve un tipo de dato entero con la opcion seleccionada por el usuario
 *
 */

int printMenu(char* optionMenu, char* welcomeMessege, int ranks, int userAttempts)
{

    int userDecision = 0;
    int validateInteger =0;
    int errAttempts =0;

    printf("%c",optionMenu);
    printf("%c",welcomeMessege);

    validateInteger = scanf("%d",userDecision);

    if (validateInteger == 0 )
    {
        do
        {
            errAttempts++;
            printf("Por favor ingrese una opcion del 1 al %d\n",ranks);
            validateInteger = scanf("%d",userDecision);
        }
        while(validateInteger == 0 || errAttempts != userAttempts || userDecision > ranks || userDecision < 1);

        if (validateInteger == 0)
        {
            system(LIMPIARPANTALLA);
            printf("Usted realizo %d intentos fallidos. Por favor cierre el programa e intente de nuevo");
            exit(0);
        }
    }
    else
    {
        return userDecision;
    }

}
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
