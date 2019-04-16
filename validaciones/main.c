#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
   // char auxName[500] = "test";
   // char auxNumber[500] = "333";
    char auxDni [500] = "dni";

  /*  if(getName( "Nombre?: ",
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

/*
    if(getNumber( "numero?: ",
                "Error",
                1,
                150,
                2,
                auxNumber) == 0)
    {
        printf("OK: %s",auxNumber);
    }
    else
    {
        printf("ER: %s",auxNumber);
    }


*/



        if(getDni( "numero de dni?: ",
                "Error",
                999999,
                60000000,
                2,
                auxDni) == 0)
    {
        printf("OK: %s",auxDni);
    }
    else
    {
        printf("ER: %s",auxDni);
    }


    return 0;
}
