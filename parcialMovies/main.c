#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "Controller.h"
#include "miBiblioteca.h"

int main()
{
    LinkedList* lista=NULL;
    char seguir='s';
    lista=ll_newLinkedList();

    srand(time(NULL));

    do
    {
        switch(menu())
        {
        case 1:
            if(!ll_isEmpty(lista))
            {
                printf("Ya se cargaron los datos\n");
            }
            else
            {
                controller_loadFromText("movies.csv", lista);
            }
            break;
        case 2:
            if(ll_isEmpty(lista))
            {
                printf("primero debe cargar los datos\n");
            }
            else
            {
                controller_listarMovies(lista);
            }
            break;
        case 3:
            if(ll_isEmpty(lista))
            {
                printf("primero debe cargar los datos\n");
            }
            else
            {
                if(controller_asignarTiempos(lista))
                {
                    printf("Se asignaron las duraciones correctamente\n");
                }
            }
            break;
        case 4:
            if(ll_isEmpty(lista))
            {
                printf("primero debe cargar los datos\n");
            }
            else
            {
                controller_filtrarPorTipo(lista);
            }
            break;
        case 5:
            if(ll_isEmpty(lista))
            {
                printf("primero debe cargar los datos\n");
            }
            else
            {
                controller_mostrarDuraciones(lista);
            }
            break;
        case 6:
            if(ll_isEmpty(lista))
            {
                printf("primero debe cargar los datos\n");
            }
            else
            {
                controller_saveAsText("peliculasOrdenadas.csv", lista);
            }
            break;
        case 7:
            seguir='n';
            break;
        default:

            break;
        }
        system("pause");
    }while(seguir=='s');

    return 0;
}
