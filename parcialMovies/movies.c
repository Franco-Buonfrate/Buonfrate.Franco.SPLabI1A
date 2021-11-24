#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "movies.h"

eMovies* movie_newMovie()
{
    eMovies* nuevaMovie=NULL;
    nuevaMovie = (eMovies*) malloc(sizeof(eMovies));
    if(nuevaMovie!=NULL)
    {
        nuevaMovie->id_peli=0;
        strcpy(nuevaMovie->titulo, "nn");
        strcpy(nuevaMovie->genero, "nn");
        nuevaMovie->duracion=0;
    }
    return nuevaMovie;
}

eMovies* movie_newMovieParam(char* id_peliStr, char* TituloStr, char* generoStr, char* duracionStr)
{
    eMovies* movieCargar=NULL;

    movieCargar=movie_newMovie();

    if(id_peliStr!=NULL && TituloStr!=NULL && generoStr!=NULL && duracionStr!=NULL && movieCargar!=NULL)
    {
        if(!(movie_setId_peli(movieCargar,atoi(id_peliStr))&&
        movie_setTitulo(movieCargar,TituloStr) &&
        movie_setGenero(movieCargar,generoStr) &&
        movie_setDuracion(movieCargar, atoi(duracionStr))))
        {
            movie_delete(movieCargar);
            movieCargar=NULL;
        }
    }
    return movieCargar;
}

int movie_setId_peli(eMovies* movie, int id_peli)
{
    int validacion=0;
    if(movie!=NULL)
    {
        movie->id_peli=id_peli;
        validacion=1;
    }
    return validacion;
}

int movie_getId_peli(eMovies* movie, int* id_peli)
{
    int validacion=0;
    if(movie!=NULL && id_peli!=NULL)
    {
      *id_peli = movie->id_peli;
      validacion=1;
    }
    return validacion;
}

int movie_setTitulo (eMovies* movie, char* Titulo)
{

    int validacion=0;
    if( movie!=NULL && Titulo!=NULL)
    {
        validacion=1;
        strcpy(movie->titulo, Titulo);
    }
    return validacion;
}

int movie_getTitulo(eMovies* movie, char* pTitulo)
{
    int validacion=0;
    if(movie!=NULL && pTitulo!=NULL)
    {
        strcpy(pTitulo, movie->titulo);
        validacion=1;
    }
    return validacion;
}

int movie_setGenero(eMovies* movie, char* genero)
{
    int validacion=0;
    if(movie!=NULL && genero!=NULL)
    {
        validacion=1;
        strcpy(movie->genero, genero);
    }
    return validacion;
}

int movie_getGenero(eMovies* movie, char* genero)
{
    int validacion=0;
    if(movie!=NULL && genero!=NULL)
    {
        strcpy(genero, movie->titulo);
        validacion=1;
    }
    return validacion;
}

int movie_setDuracion (eMovies* movie, int duracion)
{
    int validacion=0;
    if(movie!=NULL)
    {
        movie->duracion=duracion;
        validacion=1;
    }
    return validacion;
}

int movie_getDuracion (eMovies* movie, int* duracion)
{
    int validacion=0;
    if(movie!=NULL && duracion!=NULL)
    {
        *duracion=movie->duracion;
        validacion=1;
    }
    return validacion;
}

void movie_delete(eMovies* movie)
{
    free(movie);
}

void movie_showMovie(eMovies* movie)
{
    int id;
    char titulo[128];
    char genero[15];
    int duracion;

    if(movie!=NULL)
    {
        movie_getId_peli(movie, &id);
        movie_getTitulo(movie, titulo);
        movie_getGenero(movie, genero);
        movie_getDuracion(movie, &duracion);

        printf("%3d   %s              %s         %2d\n", id, titulo, genero, duracion);
    }
}

void* movie_cargarMovie (void* movie)
{
    int duracion;

    if(movie!=NULL)
    {
        duracion = rand() % (240-100+1) + 1;

        movie_setDuracion(movie, duracion);
     }

    return movie;
}

int movies_filtroPorGenero()
{
    return 0;
}

int movies_OrdenarPorGeneroDuracion (void* movieI, void* movieJ)
{
    char generoI[15];
    char generoJ[15];

    int duracionI;
    int duracionJ;

    int diferencia;

    movie_getGenero(movieI, generoI);
    movie_getGenero(movieJ, generoJ);

    movie_getDuracion(movieI, &duracionI);
    movie_getDuracion(movieJ, &duracionJ);

    diferencia = strcmp(generoI, generoJ);

    if(diferencia>0)
    {
        return 1;
    }

    if(diferencia<0)
    {
        return -1;
    }

    movies_OrdenarPorDuracion(movieI, movieJ);

    return 0;
}

int movies_OrdenarPorDuracion(void* movieI, void* movieJ)
{
    int duracionI;
    int duracionJ;

    movie_getDuracion(movieI, &duracionI);
    movie_getDuracion(movieJ, &duracionJ);

    if(duracionI>duracionJ)
    {
        return 1;
    }

    if(duracionI<duracionJ)
    {
        return -1;
    }

    return 0;
}
