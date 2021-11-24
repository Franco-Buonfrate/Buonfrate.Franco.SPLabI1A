#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "movies.h"

/** \brief Parsea los datos los datos de las peliculas desde el archivo movie.csv (modo texto).
 *
 * \param path char*
 * \param lista LinkedList*
 * \return int
 *
 */
int parser_movieFromText(FILE* pFile , LinkedList* lista)
{
    int validacion=0;
    int cant;
    char buffer[4][128];
    eMovies* movie=NULL;

    if(pFile!=NULL && lista!=NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        do{
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if(cant<4)
            {
                break;
            }

            movie=movie_newMovieParam(buffer[0], buffer[1], buffer[2], buffer[3]);

            if(ll_add(lista, movie))
            {
                validacion=0;
                break;
            }
            else
            {
                validacion=1;
            }

        } while(!feof(pFile));
    }
    return validacion;
}
