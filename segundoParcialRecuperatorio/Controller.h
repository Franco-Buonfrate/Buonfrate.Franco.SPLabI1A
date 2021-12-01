
/** \brief Carga los datos de las peliculas desde el archivo path (modo texto).
 *
 * \param path char* nombre del archivo a cargar
 * \param lista LinkedList* lista donde se cargaran los datos al sistema
 * \return int (1) en caso de que no haber errores
 *             (0) en caso de que se haya producido un error
 */
int controller_loadFromText(char* path , LinkedList* lista);

/** \brief Guarda los datos de las peliculas en el archivo path (modo texto).
 *
 * \param path char* nombre del archivo donde se guardaran los datos
 * \param lista LinkedList* lista de donde se cargar los datos al archivo
 * \return int (1) en caso de que no haber errores
 *             (0) en caso de que se haya producido un error
 *
 */
int controller_saveAsText(char* path , LinkedList* lista);

/** \brief Imprime en pantalla el contenido de la linkedlist previamente cargado
 *
 * \param lista LinkedList* lista con los datos a mostrar
 * \return int (1) en caso de que no haber errores
 *             (0) en caso de que se haya producido un error
 *
 */
int controller_listarMovies (LinkedList* lista);

/** \brief asigna al parametro rating un numero aleatoreo entre 1 y 10 con un decimal
 *
 * \param lista LinkedList* lista con los datos a cargar
 * \return int (1) en caso de que no haber errores
 *             (0) en caso de que se haya producido un error
 *
 */
int controller_asignarRating(LinkedList* lista);

/** \brief asigna al parametro genero, un genero entre 4 posibles de manera aleatoria
 *
 * \param lista LinkedList* lista con los datos a cargar
 * \return int (1) en caso de que no haber errores
 *             (0) en caso de que se haya producido un error
 *
 */
int controller_asignarGenero(LinkedList* lista);

/** \brief crea una nueva linkedList con los elementos de la anterior filtrados por genero y los carga en un nuevo archivo
 *
 * \param lista LinkedList* lista con los datos a filtrar
 * \return int (1) en caso de que no haber errores
 *             (0) en caso de que se haya producido un error
 *
 */
int controller_filtrarPorGenero(LinkedList* lista);

/** \brief ordena los elementos de la linkedList por genero y rating
 *
 * \param lista LinkedList* lista con los datos a cargar
 * \return int (1) en caso de que no haber errores
 *             (0) en caso de que se haya producido un error
 *
 */
int controller_ordenarPeliculas(LinkedList* lista);

