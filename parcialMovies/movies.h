#ifndef MOVIES_H_INCLUDED
#define MOVIES_H_INCLUDED

typedef struct
{
    int id_peli;
    char titulo[128];
    char genero[15];
    int duracion;
} eMovies;

#endif // MOVIES_H_INCLUDED


eMovies* movie_newMovie();
eMovies* movie_newMovieParam(char* id_peliStr, char* TituloStr, char* generoStr, char* duracionStr);
int movie_setId_peli(eMovies* movie, int id_peli);
int movie_getId_peli(eMovies* movie, int* id_peli);
int movie_setTitulo (eMovies* movie, char* Titulo);
int movie_getTitulo(eMovies* movie, char* pTitulo);
int movie_setGenero(eMovies* movie, char* genero);
int movie_getGenero(eMovies* movie, char* genero);
int movie_setDuracion (eMovies* movie, int duracion);
int movie_getDuracion (eMovies* movie, int* duracion);
void movie_delete(eMovies* movie);
void movie_showMovie(eMovies* movie);
void* movie_cargarMovie (void* movie);
int movies_filtroPorGenero();
int movies_OrdenarPorGeneroDuracion (void* movieI, void* movieJ);
int movies_OrdenarPorDuracion(void* movieI, void* movieJ);
