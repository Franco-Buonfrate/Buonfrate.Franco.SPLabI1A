#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "movies.h"
#include "parser.h"
#include "miBiblioteca.h"


/** \brief Carga los datos de las peliculas desde el archivo movies.csv (modo texto).
 *
 * \param path char*
 * \param lista LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* lista)
{
    int validacion=0;
    FILE* pFile;
    if(path!=NULL && lista!=NULL)
    {
        pFile=fopen(path,"r");
        if(pFile!=NULL && parser_movieFromText(pFile, lista))
        {
            printf("\nSe cargaron los archivos de forma exitosa\n");
            validacion=1;
        }
        else
        {
            printf("\nError al cargar los datos\n");
        }
        fclose(pFile);
    }
    return validacion;
}

/** \brief Guarda los datos de las peliculas en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param lista LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* lista)
{
    int validacion=0;
    FILE* pFile=NULL;
    eMovies movie;
    eMovies* pMovie;

    if(path!=NULL && lista!=NULL)
    {
        pFile=fopen(path, "w");
        fprintf(pFile,"id_peli,titulo,genero,duracion\n");

        for(int i=0; i<ll_len(lista); i++)
        {
            pMovie=ll_get(lista, i);
            movie_getId_peli(pMovie, &movie.id_peli);
            movie_getTitulo(pMovie, movie.titulo);
            movie_getGenero(pMovie, movie.genero);
            movie_getDuracion(pMovie, &movie.duracion);

            fprintf(pFile,"%d,%s,%s,%d\n", movie.id_peli, movie.titulo, movie.genero, movie.duracion);
            validacion=1;
        }
        fclose(pFile);
    }
    return validacion;
}

int controller_listarMovies (LinkedList* lista)
{
    int validacion=0;
    if(lista!=NULL)
    {
        printf("ID     TITULO         GENERO      DURACION\n");
        for(int i=0; i<ll_len(lista); i++)
        {
            movie_showMovie(ll_get(lista, i));
        }
        validacion=1;
    }
    return validacion;
}

int controller_asignarTiempos(LinkedList* lista)
{
    int validacion=0;

    if(lista!=NULL)
    {
        ll_map(lista, movie_cargarMovie);
        validacion=1;
    }

    return validacion;
}


int controller_filtrarPorTipo(LinkedList* lista)
{
    int validacion=0;


    if(lista!=NULL)
    {

        validacion=1;
    }

    return validacion;
}

int controller_mostrarDuraciones (LinkedList* lista)
{
    int validacion=0;


    if(lista!=NULL)
    {
        ll_sort(lista, movies_OrdenarPorDuracion, 0);

        controller_listarMovies(lista);

        validacion=1;
    }

    return validacion;
}


