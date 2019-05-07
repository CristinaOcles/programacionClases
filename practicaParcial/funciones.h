#include <string.h>
#include <stdio.h>
#include <stdlib.h>



typedef struct
{
    int codAutor;
    char nombre[][31];
    char apellido[][31];
    int isEmpty;

} eAutores;


typedef struct
{
    int codLibro;
    char titulo[][51];
    int codAutor;
    int isEmpty;

} eLibros;

typedef struct
{
    int codSocio;
    char nombre[][31];
    char apellido[][31];
    char sexo;
    char telefono[][16];
    char eMail[][16];
    char fechaPrestamo[];
    int isEmpty;

} eSocios;

typedef struct
{
    int idPrestamo;
    int idLibro;
    int idSocio;
    int isEmpty;

} ePrestamo;





int getString (char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado);
int getName (char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado);
int isValidName (char* cadena);
int initAutores(eAutores list[], int len);
int initLibros(eLibros list[], int len);
int initSocios(eSocios list[], int len);
int initPrestamo(ePrestamo list[], int len);
int getFreeSpaceAutor(eAutores list[],int len);
int getFreeSpaceLibros(eLibros list[],int len);
int getFreeSpaceSocios(eSocios list[],int len);
int getFreeSpacePrestamo(ePrestamo list[],int len);
int findAutor(eAutores list[],int len, int id);
int altaAutores (eAutores list[],int len);
int addAutor(eAutores list[],int len, int id, char name[],char lastName[]);
void printAutor(eAutores oneAutor);


