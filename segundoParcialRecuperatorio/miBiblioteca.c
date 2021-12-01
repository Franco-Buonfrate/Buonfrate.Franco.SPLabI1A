#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "miBiblioteca.h"

int menu()
{
    int opcion;

    system("cls");
    printf("            *** Menu peliculas ***              \n");
    printf("---------------------------------------------\n");
    printf("1- Cargar archivo.\n");
    printf("2- Imprimir Lista\n");
    printf("3- Asignar rating\n");
    printf("4- Asignar genero\n");
    printf("5- Filtrar por genero:\n");
    printf("6- Ordenar peliculas\n");
    printf("7- Guardar peliculas\n");
    printf("8- salir\n");




    printf("\nIngresar opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuGenero ()
{
    int opcion;

    system("cls");
    printf("            *** Menu generos ***              \n");
    printf("---------------------------------------------\n");
    printf(" 1- Drama\n");
    printf(" 2- Comedia\n");
    printf(" 3- Accion\n");
    printf(" 4- Terror\n");
    printf("0- Cancelar\n");



    printf("\nIngresar opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


int ingresarIntPos(char texto[],int* campo,int minimo,int limite)
{
    int ret=0;
    int auxInt;
    if(limite==0)
    {
        limite=2147483647;
    }

    if(texto!=NULL&&campo!=NULL&&limite >(-1))
    {
        printf("Ingrese %s: \n",texto);
        fflush(stdin);
        scanf("%d",&auxInt);
        while(auxInt<=minimo||auxInt>=limite)
        {
            printf("Invalido. Reingresar %s.\n",texto);
            fflush(stdin);
            scanf("%d",&auxInt);
        }
        *campo=auxInt;
        ret=1;
    }
    return ret;
}

int ingresarStr(char texto[],char* campo,int tam)
{
    int ret=0;
    char auxStr[200];
    if(texto!=NULL && campo!=NULL && tam>0)
    {
        printf("Ingrese %s:\n",texto);
        fflush(stdin);
        gets(auxStr);
        while(strlen(auxStr)==0 || strlen(auxStr)>tam)
        {
            printf("Invalido. Reingresar %s:\n",texto);
            fflush(stdin);
            gets(auxStr);
        }
        strcpy(campo, auxStr);
        ret=1;
    }
    return ret;
}

int ingresarFloatPos(char texto[],float* campo,int minimo,int limite)
{
    int ret=0;
    float auxFloat;
    if(limite==0)
    {
        limite=2147483647;
    }
    if(texto!=NULL&&campo!=NULL&&limite >(-1) )
    {
        printf("Ingrese %s: \n",texto);
        fflush(stdin);
        scanf("%f",&auxFloat);
        while(auxFloat<minimo||auxFloat>limite)
        {
            printf("Invalido. Reingresar %s.\n",texto);
            fflush(stdin);
            scanf("%f",&auxFloat);
        }
        *campo=auxFloat;
        ret=1;
    }
    return ret;
}

int ingresarChar(char texto[], char* campo, char parametroUno, char parametroDos)
{
    int ret=0;
    char auxChar;
    printf("Ingrese %s : ", texto);
    fflush(stdin);
    scanf("%c", &auxChar);
    auxChar=tolower(auxChar);
    if(texto!=NULL)
    {
        while(auxChar!=parametroDos && auxChar!=parametroUno)
        {
            printf("Invalido. Reingrese %s : ", texto);
            fflush(stdin);
            scanf("%c", &auxChar);
        }

        *campo=auxChar;

        ret=1;
    }
    return ret;
}

