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
    printf("3- Asignar tiempos\n");
    printf("4- Filtrar por tipo \n");
    printf("5- Mostrar duraciones\n");
    printf("6- Guardar películas\n");
    printf("7- Salir\n");



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
    printf(" 1- Adventure\n");
    printf(" 2- Drama\n");
    printf(" 3- Comedy\n");
    printf(" 4- Romance\n");
    printf(" 5- Documentary\n");
    printf(" 6- Horror\n");
    printf(" 7- Musical\n");
    printf(" 8- Animation\n");
    printf(" 9- Action\n");
    printf("10- Thriller\n");
    printf("11- Western\n");
    printf("0- cancelar\n");



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

