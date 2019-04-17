#define TRUE 1
#define FALSE 0

int getString ( char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado);
//-------------------------------------

int getName (   char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado);


int isValidName (char* cadena);


int mostrarNombres(char cadena[][50], int largo);
void initName(char cadena[][50], int largo);
int buscarIndiceVacio(char cadena[][50], int largo);


