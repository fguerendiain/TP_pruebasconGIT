#ifndef OPERACIONES_H_INCLUDED
#define OPERACIONES_H_INCLUDED



#endif // OPERACIONES_H_INCLUDED


long suma(long operador1, long operador2){      //FUNCION PARA CALCULAR SUMA

    long resultado;
    resultado = operador1 + operador2;

    return resultado;
}

long resta(long operador1, long operador2){     //FUNCION PARA CALCULAR RESTA

    long resultado;
    resultado = operador1 - operador2;

    return resultado;
}

long multiplicacion(long operador1, long operador2){      //FUNCION PARA CALCULAR MULTIPLICACION

    long resultado;
    resultado = operador1 * operador2;

    return resultado;
}

long division(long operador1, long operador2){      //FUNCION PARA CALCULAR DIVISION

    long resultado;
    resultado = operador1 / operador2;

    return resultado;
}

int factorial (int operador1){      //FUNCION PARA CALCULAR FACTORIAL

    int contador;
    int resultado = 1;
    if (operador1 == 0){  //CASO DE ERROR CALCULAR FACTORIAL DE 0
        resultado=0;
    }
    for (contador = 1; contador<= operador1 ; contador++){
        resultado*=contador;
    }
    return resultado;
}

