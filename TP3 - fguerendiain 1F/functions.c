#include <stdio.h>
#include <stdlib.h>
#include "userInputOutput.h"
#include "screenSystemShow.h"
#include "functions.h"
#include "string.h"

#define SRTINGBUFFER 4000
#define ADD 1
#define DEL 2
#define MODIFY 3
#define MAKEWEBPAGE 4
#define EXIT 5

/** \brief Ejecuta la opcion seleccionada por el usuario
 *
 * \param (menu) recibe el numero ingresado por el usuario
 * \param (film) array de peliculas
 * \param (lenght) longitud del array
 * \return 0 para salir del programa 1 para continuar
 *
 */

int runFunctionMenu(int menu, Movies *film, int lenght)
{
    int ret = 1;

    if(film!=NULL && lenght>0)
    {
        switch(menu)
        {
            case ADD :
                cleanScreen();
                addMovie(film, lenght,1);
                pauseScreen();
            break;

            case MODIFY :
                cleanScreen();
                modifyMovie(film, lenght);
                pauseScreen();
            break;

            case DEL :
                cleanScreen();
                delMovie(film, lenght);
                pauseScreen();
            break;

            case MAKEWEBPAGE :
                cleanScreen();
                makeHtml(film, lenght,"./template/index.html");
                pauseScreen();
            break;

            case EXIT :
                ret = 0;
            break;
        }
    }
    else
    {
        ret = -1;
    }
    return ret;
}


/** \brief inicializa todos los campos del array
 *
 * \param (film) array de peliculas
 * \return 0 si funciono correctamente, -1 en caso que alguna direccion sea NULL o el largo menor que 1
 *
 */

int initializeEmptyFlagArray(Movies *film,int length)
{
    int ret = -1;

    if(film != NULL && length > 0)
    {
        int i;
        for(i=0 ; i<length ; i++)
        {
            strcpy(film[i].title,"none");
            strcpy(film[i].genres,"none");
            film[i].runTime = 0;
            strcpy(film[i].description,"none");
            film[i].score = 0;
            strcpy(film[i].imgPreviewLink,"none");
            film[i].state = 1;
        }
        ret = 0;
    }
    return ret;
}


/** \brief Permite agregar una pelicula
 *
 * \param (film) array de peliculas
 * \param (lenght) longitud del array
 * \return 0 si los valores se cargaron correctamente
 *
 */

int addMovie(Movies *film, int lenght, int modifyFlag)
{
    int index;
    int ret;

    char auxTitle[31];
    char auxGenres[15]; //genero
    int auxRunTime; //duración
    char auxDescription[140];
    int auxScore;
    char auxImgPreviewLink[140];

    if(film!=NULL && lenght>0)
    {
        index = searchFirstEmpty(film,lenght);

        if(index!=-1)
        {
            getUserInputString(auxTitle,3,31,"Ingrese el nombre de la pelicula\n","Por favor ingrese un nombre valido\n",SRTINGBUFFER,0);
            getUserInputString(auxGenres,3,15,"Ingrese el genero de la pelicula\n","Por favor ingrese un genero valido\n",SRTINGBUFFER,0);
            getUserInputInt(&auxRunTime,0,999,"Ingrese la duracion de la pelicula en minutos\n","Por favor ingrese una duracion valida\n",0);
            getUserInputString(auxDescription,3,140,"Synopsis de la pelicula\n","Por favor ingrese una descripcion valida\n",SRTINGBUFFER,0);
            getUserInputInt(&auxScore,0,100,"Ingrese el puntaje de la pelicula del 1 al 100\n","Por favor ingrese un puntaje valido\n",0);
            getUserInputString(auxImgPreviewLink,3,140,"Link o URL de la imagen portada\n","Por favor ingrese una direccion valida\n",SRTINGBUFFER,0);


            strcpy(film[index].title,auxTitle);
            strcpy(film[index].genres,auxGenres);
            film[index].runTime = auxRunTime;
            strcpy(film[index].description,auxDescription);
            film[index].score = auxScore;
            strcpy(film[index].imgPreviewLink,auxImgPreviewLink);
            film[index].state = 0;

            ret = 0;
        }
        else
        {
            printf("No hay lugar para agregar nuevas peliculas\n");
            ret = -2;
        }
    }
    return ret;
}

/** \brief busca el primer elemnto libre en el array movies
 *
 * \param (film) array de peliculas
 * \return devuelve el subindice buscado, en caso que no exista devuelve -1
 *
 */

int searchFirstEmpty(Movies *film, int length)
{
    int i;
    int ret = -1;

    for(i=0 ; i<length ; i++)
    {
        if(film[i].state == 1)
            ret = i;
    }

    return ret;
}

/** \brief permite modificar pelicuals seleccionandolas por titulo
 *
 * \param (film) array de peliculas
 * \param (lenght) longitud del array
 * \return 0 si funciona correctamente -1 si es un puntero a null o una longitud negativa
 *
 */

int modifyMovie(Movies *film, int lenght)
{
    char modTitle[31];
    int flagModifyOk = 1;
    int i;
    int ret = -1;

    if (film!=NULL && lenght>0)
    {
            getUserInputString(modTitle,3,31,"Ingrese el nombre de la pelicula a modificar\n","Por favor ingrese un nombre valido\n",SRTINGBUFFER,0);

        for(i=0;i<lenght;i++)
        {
            if(film[i].state==0 && strcmp(film[i].title,modTitle)==0)
            {
                getUserInputString(film[i].title,3,31,"Ingrese el nombre de la pelicula\n","Por favor ingrese un nombre valido\n",SRTINGBUFFER,0);
                getUserInputString(film[i].genres,3,15,"Ingrese el genero de la pelicula\n","Por favor ingrese un genero valido\n",SRTINGBUFFER,0);
                getUserInputInt(&film[i].runTime,0,999,"Ingrese la duracion de la pelicula en minutos\n","Por favor ingrese una duracion valida\n",0);
                getUserInputString(film[i].description,3,140,"Synopsis de la pelicula\n","Por favor ingrese una descripcion valida\n",SRTINGBUFFER,0);
                getUserInputInt(&film[i].score,0,100,"Ingrese el puntaje de la pelicula del 1 al 100\n","Por favor ingrese un puntaje valido\n",0);
                getUserInputString(film[i].imgPreviewLink,3,140,"Link o URL de la imagen portada\n","Por favor ingrese una direccion valida\n",SRTINGBUFFER,0);
                flagModifyOk = 0;
                break;
            }
        }
        if(flagModifyOk)
        {
            printf("La pelicula indicada no existe, por favor intente nuevamente\n");
        }
        else
        {
            printf("La pelicula fue modificada con exito\n");
        }
        ret = 0;
    }
    return ret;
}

/** \brief realiza el borrado logico de peliculas seleccionandolas por titulo
 *
 * \param (film) array de peliculas
 * \param (lenght) longitud del array
 * \return 0 si funciona correctamente, -1 si hay un puntero a null o una longitud menor a 1
 *
 */

int delMovie(Movies *film, int lenght)
{
    char delTitle[31];
    int flagDeleteOk = 1;
    int i;
    int ret = -1;

    if (film!=NULL && lenght>0)
    {
            getUserInputString(delTitle,3,31,"Ingrese el nombre de la pelicula a eliminar\n","Por favor ingrese un nombre valido\n",SRTINGBUFFER,0);

        for(i=0;i<lenght;i++)
        {
            if(film[i].state==0 && strcmp(film[i].title,delTitle)==0)
            {
                film[i].state = 1;
                flagDeleteOk = 0;
                break;
            }
        }
        if(flagDeleteOk)
        {
            printf("La pelicula indicada no existe, por favor intente nuevamente\n");
        }
        else
        {
            printf("La pelicula fue eliminada con exito\n");
        }
        ret = 0;
    }
    return ret;
}

/** \brief genera un archivo index.html con el contenido de las peliculas
 *
 * \param (film) array de peliculas
 * \param (lenght) longitud del array
 * \param (urlhtmlFile) direccion del archivo index.html
 * \return 0 si funciona correctamente, -1 si hay un puntero a null o una longitud menor a 1
 *
 */

int makeHtml(Movies *film, int lenght, char *urlhtmlFile)
{
    char *staticTemplate_1;
    char *staticTemplate_2;
    char *dynamicTemplate;
    int i;
    int ret = -1;
    int flagWriteOk = 0;

    FILE *indexHtmlFile;
    indexHtmlFile = fopen(urlhtmlFile,"w");

    if (film!=NULL && indexHtmlFile!=NULL && lenght>0)
    {
        staticTemplate_1 = "<!DOCTYPE html>"
                            "<!-- Template by Quackit.com -->"
                            "<html lang='en'>"
                            "<head>"
                            "    <meta charset='utf-8'>"
                            "    <meta http-equiv='X-UA-Compatible' content='IE=edge'>"
                            "    <meta name='viewport' content='width=device-width, initial-scale=1'>"
                            "    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->"
                            "    <title>Lista peliculas</title>"
                            "    <!-- Bootstrap Core CSS -->"
                            "    <link href='css/bootstrap.min.css' rel='stylesheet'>"
                            "    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->"
                            "    <link href='css/custom.css' rel='stylesheet'>"
                            "    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->"
                            "    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->"
                            "    <!--[if lt IE 9]>"
                            "        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>"
                            "        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>"
                            "    <![endif]-->"
                            "</head>"
                            "<body>"
                            "    <div class='container'>"
                            "        <div class='row'>";

        staticTemplate_2 = "        </div>"
                            "        <!-- /.row -->"
                            "    </div>"
                            "    <!-- /.container -->"
                            "    <!-- jQuery -->"
                            "    <script src='js/jquery-1.11.3.min.js'></script>"
                            "    <!-- Bootstrap Core JavaScript -->"
                            "    <script src='js/bootstrap.min.js'></script>"
                            "    <!-- IE10 viewport bug workaround -->"
                            "    <script src='js/ie10-viewport-bug-workaround.js'></script>"
                            "    <!-- Placeholder Images -->"
                            "    <script src='js/holder.min.js'></script>"
                            "</body>"
                            "</html>";

        dynamicTemplate = "<article class='col-md-4 article-intro'>"
                           "     <a href='#'>"
                           "         <img class='img-responsive img-rounded' src='%s' alt=''>" //  mascara %s para el link de la imagen
                           "     </a>"
                           "     <h3>"
                           "         <a href='#'>%s</a>" //mascara %s para el titulo
                           "     </h3>"
                           "     <ul>"
                           "         <li>Género: %s</li>" //mascara %s para el genero
                           "         <li>Puntaje: %d</li>" //mascara %d para el puntaje
                           "         <li>Duración: %d minutos</li>" //mascara %d para la duracion
                           "     </ul>"
                           "     <p>%s</p>" //mascara %s para la synopsis
                           " </article>";

        for(i=0; i<lenght;i++)
        {
            if(film[i].state==0)
            {
                fprintf(indexHtmlFile,"%s",staticTemplate_1);
                fprintf(indexHtmlFile,dynamicTemplate,film[i].imgPreviewLink,film[i].title,film[i].genres,film[i].score,film[i].runTime,film[i].description);
                fprintf(indexHtmlFile,"%s",staticTemplate_2);
                flagWriteOk = 1;
            }
        }
        if(flagWriteOk)
        {
            ret = 0;
            printf("Se genero la pagina web\n");
        }
        else
        {
            printf("No existen peliculas para generar la pagina web\n");
        }
    }
    fclose(indexHtmlFile);
    return ret;
}
