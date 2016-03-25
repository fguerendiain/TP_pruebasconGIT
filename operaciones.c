
/** \brief Realiza la suma de dos numeros de tipo long
 *
 * \param operator1 recibe un operador de tipo long
 * \param operator2 recibe un operador de tipo long
 * \return result almacena y devuelve un resultado de tipo long
 *
 */
long addLong(long operator1, long operator2){ //CALCULA SUMA

    long result = operator1 + operator2;

    return result;
}




/** \brief Realiza la resta de dos numeros de tipo long
 *
 * \param operator1 recibe un operador de tipo long
 * \param operator2 recibe un operador de tipo long
 * \return result almacena y devuelve un resultado de tipo long
 *
 */
long subtractLong(long operator1, long operator2){     //CALCULA RESTA

    long result = operator1 - operator2;

    return result;
}





/** \brief Realiza la multiplicacion de dos numeros de tipo long
 *
 * \param operator1 recibe un operador de tipo long
 * \param operator2 recibe un operador de tipo long
 * \return result almacena y devuelve un resultado de tipo long
 *
 */
long multiplyLong(long operator1, long operator2){      //CALCULA MULTIPLICACION

    long result = operator1 * operator2;

    return result;
}





/** \brief Realiza la division de dos numeros de tipo long
 *
 * \param operator1 recibe un operador de tipo long
 * \param operator2 recibe un operador de tipo long
 * \return result almacena y devuelve un resultado de tipo long
 *
 */
long divideLong(long operator1, long operator2){      //CALCULA DIVISION

    long result = operator1 / operator2;

    return result;
}





/** \brief Calcula el factorial de un numero de tipo long
 *
 * \param operator1 recibe un operador de tipo long
 * \return result almacena y devuelve un resultado de tipo int
 *
 */




int factorial (long operator1){      //CALCULA FACTORIAL

    int counter; /**< contador local de la funcion */
    int operInt1 = (int)operator1; // SE CASTEA EL FLOAT INGRESADO POR EL USUARIO A UN INT PARA SER EVALUADO POR LA FUNCION
    int result = 1; // POR CONVENCION, 0! = 1

    for (counter = 1; counter<= operInt1 ; counter++){
        result*=counter;
    }
    return result;
}
