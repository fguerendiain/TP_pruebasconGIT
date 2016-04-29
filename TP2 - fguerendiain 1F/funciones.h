#ifndef __FUNCIONES
#define __FUNCIONES

/*-----------------------------------STRUCT-------------------------------------------*/

typedef struct
{
    char name[31];
    char lastName[31];
    short int age;
    char dni[11];
    short int state; //1 para ocupado
}Epeople;




/*----------------------------FUNCIONES ESPECIFICAS DEL PROGRAMA-------------------------------------*/


int runFunctionMenu(int option, Epeople *person, long int personLenght); /**< ejecuta la opcion elegida por el usuario */

int addNewPerson(Epeople *person, long int personLenght);     /**< realiza el alta de una nueva persona validando disponibilidad */

long searchFreeIndex(Epeople *person, long int personLenght);    /**< busca el primer indice libre */

void intializeArrayState(Epeople *person, long int personLenght); /**< inicializa en '0' y '\0' los campos del array person */

void delPerson(Epeople *person, long int personLenght);   /**< borrado logido de un elemento de la estructura person */

void printListOfPeople(Epeople *person, long int personLenght); /**< imprime todos los elementos de person con state en 1 */

void sortArrayByName(Epeople *person, long int personLenght);    /**< Ordena los elementos alfabeticamente por nombre de persona */

void definePercentageOfAges(Epeople *person, long int personLenght); /**< grafica el porcentaje de las edades <18 19-35 >35 */

#endif //__FUNCIONES


