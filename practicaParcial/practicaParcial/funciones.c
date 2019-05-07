#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TRUE 1
#define FALSE 0



int getString ( char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {

        do
        {
            printf("%s",msg);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr)>=minimo && strlen(bufferStr) <maximo)
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s",msgError);
        }
        while(reintentos>=0);
    }
    return retorno;
}

int getName (   char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidName(bufferStr))
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
        }

    }
    return retorno;
}


int isValidName (char* cadena)
{
    int retorno = TRUE;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a')  )
        {
            retorno = FALSE;
            break;
        }
    }
    return retorno;
}


int initAutores(eAutores list[], int len)
{
    int retorno = -1;

    if(list != NULL && len > 0)


        for(int i=0; i < len; i++)
        {

            list[i].isEmpty = 1;
        }
    retorno = 0;


    return retorno;
}


int initLibros(eLibros list[], int len)
{
    int retorno = -1;

    if(list != NULL && len > 0)


        for(int i=0; i < len; i++)
        {

            list[i].isEmpty = 1;
        }
    retorno = 0;


    return retorno;
}

int initSocios(eSocios list[], int len)
{
    int retorno = -1;

    if(list != NULL && len > 0)


        for(int i=0; i < len; i++)
        {

            list[i].isEmpty = 1;
        }
    retorno = 0;


    return retorno;
}


int initPrestamo(ePrestamo list[], int len)
{
    int retorno = -1;

    if(list != NULL && len > 0)


        for(int i=0; i < len; i++)
        {

            list[i].isEmpty = 1;
        }
    retorno = 0;


    return retorno;
}



int getFreeSpaceAutor(eAutores list[],int len)
{

    int index = -1;

    for (int i=0; i<len; i++)
    {
        if (list[i].isEmpty==1)
        {
            index = i;
            break;
        }
    }
    return index;
}

int getFreeSpaceLibros(eLibros list[],int len)
{

    int index = -1;

    for (int i=0; i<len; i++)
    {
        if (list[i].isEmpty==1)
        {
            index = i;
            break;
        }
    }
    return index;
}

int getFreeSpaceSocios(eSocios list[],int len)
{

    int index = -1;

    for (int i=0; i<len; i++)
    {
        if (list[i].isEmpty==1)
        {
            index = i;
            break;
        }
    }
    return index;
}
int getFreeSpacePrestamo(ePrestamo list[],int len)
{

    int index = -1;

    for (int i=0; i<len; i++)
    {
        if (list[i].isEmpty==1)
        {
            index = i;
            break;
        }
    }
    return index;
}


int findAutor(eAutores list[],int len, int id)
{
    int index= -1;

    if(list!=NULL && len>0 && id >-1)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].idAutor == id);
            {index = i;
            break;
            }
        }

    }

    return index;
}



int altaAutores (eAutores list[],int len, int* id)
{

    char name[20];
    char lastName[20];

    int index;
    int existeId;
    int opcion;
    int retorno;

    system("cls");
    index = getFreeSpaceAutor(list,len);


    if (list!=NULL && len>0 && index>=0)
    {

        if( index == -1)
        {
            printf("No hay lugar en el sistema\n\n");
            system("pause");
        }
        else
        {

            printf("\n ***alta de autores*** \n");

            id = id + 1;
            existeId = findAutor(list, len, id);

            if(existeId==-1)
            {
                printf("Ingrese nombre: \n");
                fflush(stdin);
                gets(name);
                printf("Ingrese Apellido: \n");
                fflush(stdin);
                gets(lastName);

                printf("\n\n");

                printf("Nombre       apellido\n\n");
                printf("%10s %10s %5.2f  %10d\n\n", name, lastName);
                printf("Si los datos son correctos ingrese 1, si los datos son incorrectos ingrese 9\n");
                scanf("%d", &opcion);

                if(opcion == 1)
                {
                    retorno = addAutor(list,len,id,name,lastName);

                    if(retorno == 0)
                    {
                        printf("Alta exitosa!!!!\n\n");
                        retorno = 0;
                    }
                    else
                    {
                        printf("Alta sin efecto: \n");
                        retorno = -1;
                    }

                }
                else
                {
                    printf("Alta cancelada: \n");
                    retorno = -1;
                }



            }
            else
            {

                printf("Ya existe un autor con el id %d\n", id);
                printAutor(list[index]);
                system("pause");
            }

        }

        return retorno;

    }



}



int addAutor(eAutores list[],int len, int id, char name[],char lastName[])
{
    int retorno = -1;
    int index;

    index = id - 1;

    if (list!=NULL && len>0)
    {

        strcpy (list[index].nombre,name);
        strcpy (list[index].apellido,lastName);
        list[index].idAutor = id;
        list[index].isEmpty=0;

        retorno = 0;
    }



    return retorno;

}


void printAutor(eAutores oneAutor)
{


    printf("%3d   %6s     %6s     \n\n", oneAutor.idAutor, oneAutor.nombre, oneAutor.apellido);

}
