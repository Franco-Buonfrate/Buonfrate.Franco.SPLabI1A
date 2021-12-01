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
    int genero=0;
    int rating=0;

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
                if(controller_asignarRating(lista))
                {
                    printf("Se asignaron los ratings correctamente\n");
                    rating=1;
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
                if(controller_asignarGenero(lista))
                {
                    printf("Se asignaron los generos correctamente\n");
                    genero=1;
                }
            }
            break;
        case 5:
            if(ll_isEmpty(lista))
            {
                printf("primero debe cargar los datos\n");
            }
            else
            {
                if(genero==0)
                {
                    printf("primero debe asignar los generos\n");
                }
                else
                {
                    controller_filtrarPorGenero(lista);
                }
            }
            break;
        case 6:
            if(ll_isEmpty(lista))
            {
                printf("primero debe cargar los datos\n");
            }
            else
            {
                if(rating==0 || genero==0)
                {
                    printf("primero debe asignar el rating y el genero\n");
                }
                else
                {
                    if(controller_ordenarPeliculas(lista))
                    {
                        printf("Ordenamiento exitoso \n");
                    }
                }
            }
            break;
        case 7:
            if(ll_isEmpty(lista))
            {
                printf("primero debe cargar los datos\n");
            }
            else
            {
                controller_saveAsText("peliculasOrdenadas.csv", lista);
            }
            break;
        case 8:
            seguir='n';
            break;
        default:

            break;
        }
        system("pause");
    }while(seguir=='s');

    return 0;
}
