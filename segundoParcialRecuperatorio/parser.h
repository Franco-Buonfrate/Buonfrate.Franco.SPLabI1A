/** \brief parsea los datos desde el archivo de texto
 *
 * \param pFile FILE* puntero al archivo
 * \param lista LinkedList* lista donde se cargaran los datos
 * \return int (1) en caso de que no haber errores
 *             (0) en caso de que se haya producido un error
 *
 */

int parser_movieFromText(FILE* pFile , LinkedList* lista);
