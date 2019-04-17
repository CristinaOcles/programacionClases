#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define QTY_EMPLEADOS 50




int main()
{
   // char auxName[500] = "test";
    int indice;


    char arrayNombres[QTY_EMPLEADOS][50];

    initName(arrayNombres,QTY_EMPLEADOS);

    strncpy(arrayNombres[0], "Juan", 50);
    strncpy(arrayNombres[1], "Pedro", 50);
    strncpy(arrayNombres[2], "Luis", 50);

    //mostrarNombres(arrayNombres, 6);

    indice = buscarIndiceVacio(arrayNombres, QTY_EMPLEADOS);

    mostrarNombres(arrayNombres, QTY_EMPLEADOS);

    /*

    if(getName( "Nombre?: ",
                "Error",
                2,
                5,
                2,
                auxName) == 0)
    {
        printf("OK: %s",auxName);
    }
    else
    {
        printf("ER: %s",auxName);
    }
    */


    return 0;
}



