#ifndef MOVIES_H_INCLUDED
#define MOVIES_H_INCLUDED

typedef struct
{
    int id_peli;
    char titulo[128];
    char genero[30];
    float rating;
} eMovies;

#endif // MOVIES_H_INCLUDED

/** \brief crea una estructera eMovie vacia
 *
 * \return retorna un puntero a una nueva estructura
 *
 */
eMovies* movie_newMovie();


/** \brief crea una estructera eMovie cargada con los datos pasados por puntero
 *
 * \param id_peliStr char*
 * \param TituloStr char*
 * \param generoStr char*
 * \param ratingStr char*
 * \return retorna un puntero a una nueva estructura
 *
 */

eMovies* movie_newMovieParam(char* id_peliStr, char* TituloStr, char* generoStr, char* ratingStr);

/** \brief setea los datos del id con el valor pasado por parametro
 *
 * \param eMovies* movie
 * \param int id_peli
 * \return  int (1) en caso de que no haber errores
 *              (0) en caso de que se haya producido un error
 *
 */

int movie_setId_peli(eMovies* movie, int id_peli);

/** \brief obtiene el datos del id y se lo pasa por puntero al segundo parametro
 *
 * \param eMovies* movie
 * \param int* id_peli
 * \return  int (1) en caso de que no haber errores
 *              (0) en caso de que se haya producido un error
 *
 */
int movie_getId_peli(eMovies* movie, int* id_peli);

/** \brief setea los datos del titulo con el valor pasado por parametro
 *
 * \param eMovies* movie
 * \param char* Titulo
 * \return  int (1) en caso de que no haber errores
 *              (0) en caso de que se haya producido un error
 *
 */
int movie_setTitulo (eMovies* movie, char* Titulo);

/** \brief obtiene el datos del titulo y se lo pasa por puntero al segundo parametro
 *
 * \param eMovies* movie
 * \param char* pTitulo
 * \return  int (1) en caso de que no haber errores
 *              (0) en caso de que se haya producido un error
 *
 */
int movie_getTitulo(eMovies* movie, char* pTitulo);

/** \brief setea los datos del genero con el valor pasado por parametro
 *
 * \param eMovies* movie
 * \param char* genero
 * \return  int (1) en caso de que no haber errores
 *              (0) en caso de que se haya producido un error
 *
 */
int movie_setGenero(eMovies* movie, char* genero);

/** \brief obtiene el datos del genero y se lo pasa por puntero al segundo parametro
 *
 * \param eMovies* movie
 * \param char* genero
 * \return  int (1) en caso de que no haber errores
 *              (0) en caso de que se haya producido un error
 *
 */
int movie_getGenero(eMovies* movie, char* genero);

/** \brief setea los datos del id con el valor pasado por parametro
 *
 * \param eMovies* movie
 * \param float rating
 * \return  int (1) en caso de que no haber errores
 *              (0) en caso de que se haya producido un error
 *
 */
int movie_setrating (eMovies* movie, float rating);

/** \brief obtiene el datos del rating y se lo pasa por puntero al segundo parametro
 *
 * \param eMovies* movie
 * \param float* rating
 * \return  int (1) en caso de que no haber errores
 *              (0) en caso de que se haya producido un error
 *
 */
int movie_getrating (eMovies* movie, float* rating);

/** \brief borra la estructura y el punturo pasado por parametro
 *
 * \param eMovies* movie puntero de la estructura a borrar
 *
 */

void movie_delete(eMovies* movie);

/** \brief muestra los datos almacenados en la estructura
 *
 * \param eMovies* movie puntero de la estructura a mostrar
 *
 */

void movie_showMovie(eMovies* movie);

/** \brief carga el campo rating con un numero aleatoreo
 *
 * \param movie void* puntero a estructura
 *
 */

void* movie_cargarMovie (void* movie);

/** \brief carga el campo genero con de manera aleatorea
 *
 * \param movie void* puntero a estructura
 *
 */

void* movie_cargarGenero (void* movie);


/** \brief determina si los elementos deberian switchearse
 *
 * \param void* movieI
 * \param void* movieJ
 * \return retorna 1 en caso de que debean switchearse los elementos
 *
 */

int movies_OrdenarPorGenero (void* movieI, void* movieJ);

/** \brief determina si los elementos deberian switchearse
 *
 * \param void* movieI
 * \param void* movieJ
 * \return retorna 1 en caso de que debean switchearse los elementos
 *
 */
int movies_OrdenarPorrating(void* movieI, void* movieJ);
