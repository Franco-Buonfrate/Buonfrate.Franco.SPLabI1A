#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "movies.h"
#include "parser.h"
#include "miBiblioteca.h"



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


int controller_saveAsText(char* path , LinkedList* lista)
{
    int validacion=0;
    FILE* pFile=NULL;
    eMovies movie;
    eMovies* pMovie;

    if(path!=NULL && lista!=NULL)
    {
        pFile=fopen(path, "w");
        fprintf(pFile,"id_peli,titulo,genero,rating\n");

        for(int i=0; i<ll_len(lista); i++)
        {
            pMovie=ll_get(lista, i);
            movie_getId_peli(pMovie, &movie.id_peli);
            movie_getTitulo(pMovie, movie.titulo);
            movie_getGenero(pMovie, movie.genero);
            movie_getrating(pMovie, &movie.rating);

            fprintf(pFile,"%d,%s,%s,%.1f\n", movie.id_peli, movie.titulo, movie.genero, movie.rating);
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
        printf(" ID              TITULO                     GENERO            RATING\n");
        for(int i=0; i<ll_len(lista); i++)
        {
            movie_showMovie(ll_get(lista, i));
        }
        validacion=1;
    }
    return validacion;
}



int controller_asignarRating(LinkedList* lista)
{
    int validacion=0;

    if(lista!=NULL)
    {
        ll_map(lista, movie_cargarMovie);
        validacion=1;
    }

    return validacion;
}



int controller_asignarGenero(LinkedList* lista)
{
    int validacion=0;

    if(lista!=NULL)
    {
        ll_map(lista, movie_cargarGenero);
        validacion=1;
    }

    return validacion;
}


int controller_filtrarPorGenero(LinkedList* lista)
{
    int validacion=0;
    char filtro[30];
    int tam;
    eMovies* auxMovie=NULL;
    LinkedList* listaFiltrada;

    tam=ll_len(lista);
    listaFiltrada=ll_newLinkedList();

    if(lista!=NULL && listaFiltrada!=NULL)
    {
        switch(menuGenero())
        {
        case 1:
            strcpy(filtro,"drama");
            break;
        case 2:
            strcpy(filtro,"comedia");
            break;
        case 3:
            strcpy(filtro,"accion");
            break;
        case 4:
            strcpy(filtro,"terror");
            break;
        case 0:
            return 1;
            break;
        default:
            printf("Ingrese una opcion valida\n");
            break;
        }

        for(int i=0;i<tam;i++)
        {
            auxMovie=ll_get(lista, i);
            if(strcmp(auxMovie->genero, filtro)==0)
            {
                ll_add(listaFiltrada, auxMovie);
            }
        }

        strcat(filtro, ".csv");

        if(controller_saveAsText(filtro, listaFiltrada))
        {
            printf("Se guardo correctamente el archivo\n");
        }
        validacion=1;
    }

    return validacion;
}


int controller_ordenarPeliculas(LinkedList* lista)
{
    int validacion=0;
    if(lista!=NULL)
    {
        ll_sort(lista, movies_OrdenarPorGenero, 1);
        controller_listarMovies(lista);

        validacion=1;
    }

    return validacion;
}




