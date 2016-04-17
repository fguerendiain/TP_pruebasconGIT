

int runFunctionMenu(int option, Epeople *person, long personLenght); /**< Ejecuta la opcion elegida por el usuario */

int addNewPerson(Epeople *person, long personLenght);     /**< permite dar de alta una nueva persona siempre que se encuentren posiciones disponibles */

long searchFreeIndex(Epeople *person, long personLenght);    /**< recorre el array buscando el primer indice libre */

void intializeArrayState(Epeople *person, long personLenght); /**< inicializa en 0 el campo de estado del array */




