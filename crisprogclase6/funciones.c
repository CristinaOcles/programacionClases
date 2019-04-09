#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int pedirNombre(char* nombre, int size)
{
    char buffer[20];
    int isOk=0;

    printf("Ingrese nombre\n");
    fgets(buffer, sizeof(buffer), stdin);

    if(validarNombre(buffer))
    {
       isOk=1;
       strncpy(nombre, buffer, size);

    }
    else
    {
        printf("\n Solo debe ingresar letras\n");
    }

    return isOk;
}


int validarNombre(char* buffer)
{

    int isChar = 0;

    int i;

    for (i=0; i<strlen(buffer); i++)
    {

        if((buffer[i] >= 'a' && buffer[i] <= 'z' ) || (buffer[i] >= 'A' && buffer[i] <= 'Z' ))
        {
            isChar = 1;
        }

    }

    return isChar;

}


