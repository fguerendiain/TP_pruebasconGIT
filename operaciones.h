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

int factorial (long operador1){      //FUNCION PARA CALCULAR FACTORIAL

    int contador;
    int operInt1 = (int)operador1; // SE CASTEA EL FLOAT INGRESADO POR EL USUARIO A UN INT PARA SER EVALUADO POR LA FUNCION
    int resultado = 1; // POR CONVENCION, 0! = 1

    for (contador = 1; contador<= operInt1 ; contador++){
        resultado*=contador;
    }
    return resultado;
}
