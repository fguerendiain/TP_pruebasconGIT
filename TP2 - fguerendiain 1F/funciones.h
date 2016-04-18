

int runFunctionMenu(int option, Epeople *person, long int personLenght); /**< Ejecuta la opcion elegida por el usuario */

int addNewPerson(Epeople *person, long int personLenght);     /**< permite dar de alta una nueva persona siempre que se encuentren posiciones disponibles */

long searchFreeIndex(Epeople *person, long int personLenght);    /**< recorre el array buscando el primer indice libre */

void intializeArrayState(Epeople *person, long int personLenght); /**< inicializa en 0 el campo de estado del array */

void delPerson(Epeople *person, long int personLenght);   /**< borrado logido de un elemento de la estructura person */

void printListOfPeople(Epeople *person, long int personLenght); /**< imprime todos los elementos del array */

void sortArrayByName(Epeople *person, long int personLenght);    /**< Ordena los elementos alfabeticamente por nombre de persona */




