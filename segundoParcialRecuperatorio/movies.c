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
        nuevaMovie->rating=0;
    }
    return nuevaMovie;
}

eMovies* movie_newMovieParam(char* id_peliStr, char* TituloStr, char* generoStr, char* ratingStr)
{
    eMovies* movieCargar=NULL;

    movieCargar=movie_newMovie();

    if(id_peliStr!=NULL && TituloStr!=NULL && generoStr!=NULL && ratingStr!=NULL && movieCargar!=NULL)
    {
        if(!(movie_setId_peli(movieCargar,atoi(id_peliStr))&&
        movie_setTitulo(movieCargar,TituloStr) &&
        movie_setGenero(movieCargar,generoStr) &&
        movie_setrating(movieCargar, atoi(ratingStr))))
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
        strcpy(genero, movie->genero);
        validacion=1;
    }
    return validacion;
}

int movie_setrating (eMovies* movie, float rating)
{
    int validacion=0;
    if(movie!=NULL)
    {
        movie->rating=rating;
        validacion=1;
    }
    return validacion;
}

int movie_getrating (eMovies* movie, float* rating)
{
    int validacion=0;
    if(movie!=NULL && rating!=NULL)
    {
        *rating=movie->rating;
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
    char genero[30];
    float rating;

    if(movie!=NULL)
    {
        movie_getId_peli(movie, &id);
        movie_getTitulo(movie, titulo);
        movie_getGenero(movie, genero);
        movie_getrating(movie, &rating);

        printf("%3d   %-30s %15s           %.1f\n", id, titulo, genero, rating);
    }
}

void* movie_cargarMovie (void* movie)
{
    float rating;

    if(movie!=NULL)
    {
        rating = (float)(rand() % 100 + 1)/10;


        movie_setrating(movie, rating);
     }

    return movie;
}

void* movie_cargarGenero (void* movie)
{
    int numero;
    char genero[10];

    if(movie!=NULL)
    {
        numero = rand() % 4 + 1;

        switch(numero)
        {
        case 1:
            strcpy(genero, "drama");
            break;
        case 2:
            strcpy(genero, "comedia");
            break;
        case 3:
            strcpy(genero, "accion");
            break;
        case 4:
            strcpy(genero, "terror");
            break;
        }
        movie_setGenero(movie, genero);
     }

    return movie;
}

int movies_OrdenarPorGenero (void* movieI, void* movieJ)
{
    char generoI[30];
    char generoJ[30];
    int retorno;
    int diferencia;

    movie_getGenero(movieI, generoI);
    movie_getGenero(movieJ, generoJ);

    diferencia = strcmp(generoI, generoJ);

    if(diferencia>0)
    {
        return 1;
    }

    if(diferencia<0)
    {
        return -1;
    }


    retorno = movies_OrdenarPorrating(movieI, movieJ);
    return retorno;
}

int movies_OrdenarPorrating(void* movieI, void* movieJ)
{
    float ratingI;
    float ratingJ;

    movie_getrating(movieI, &ratingI);
    movie_getrating(movieJ, &ratingJ);

    if(ratingI<ratingJ)
    {
        return 1;
    }

    return 0;
}

