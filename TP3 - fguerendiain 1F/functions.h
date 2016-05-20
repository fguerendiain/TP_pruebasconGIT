#ifndef __FUNCTIONS
#define __FUNCTIONS

typedef struct{

char title[31];
char genres[15]; //genero
int runTime; //duración
char description[140];
int score;
char imgPreviewLink[140];
int state;

}Movies;

/*--------------------------------------------------------------------------------------------------------------*/

int runFunctionMenu(int menu, Movies *film, int lenght);    /**< Ejecuta la opcion seleccionada por el usuario */

int initializeEmptyFlagArray(Movies *film, int length);  /**< inicializa todos los campos del array */

int addMovie(Movies *film, int lenght, int modifyFlag); /**< Permite agregar una pelicula */

int searchFirstEmpty(Movies *film, int length);     /**< busca el primer elemnto libre en el array movies */

int modifyMovie(Movies *film, int lenght);  /**< permite modificar pelicuals seleccionandolas por titulo */

int delMovie(Movies *film, int lenght);  /**< realiza el borrado logico de peliculas seleccionandolas por titulo */

int makeHtml(Movies *film, int lenght, char *urlhtmlFile); /**< genera un archivo index.html con el contenido de las peliculas */

#endif // __FUNCTIONS



