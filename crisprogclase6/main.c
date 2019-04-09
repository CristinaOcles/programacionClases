#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
int main()
{

    char nombre[20];


    if(pedirNombre(nombre,sizeof(nombre)))
    {
        printf("%s", nombre);
    }

    /*
        strncpy(nombre, nombre2, sizeof(nombre));
        printf("\n %s", nombre);

        fgets(nombre, sizeof(nombre), stdin);
        printf("\n %s", nombre);
    */







    return 0;
}
