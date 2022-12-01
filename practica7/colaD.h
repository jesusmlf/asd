#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


/*
                Tabla de errores
        Variable        Estado      Descripción
        error           -1          Nodo nulo
        error           -2          Cola nula
        error           -3          Cola vacia
        error           -4          Indice invalido
        error           0           Sin errores
*/

typedef struct{
    int valor;
    FILE *archivo;
}Elemento;

struct Nodo{
    Elemento elemento;
    struct Nodo *sig;
};

typedef struct{
    struct Nodo* inicio;
    struct Nodo* fin;
    int tam;
}Cola;

void initialize(Cola *c, int *error);
void encolar(Cola* c,int *error, Elemento elemento);
Elemento desencolar(Cola *c, int *error);
bool isEmpty(Cola c,int *error);
Elemento consultarFrente(Cola c,int *error);
Elemento consultarFinal(Cola c,int *error);
Elemento consultarN_Elemento(Cola c,int *error,int indice);
void recorrerCola(Cola c, int *error);
int size(Cola c,int *error);
void vaciarCola(Cola* c,int *error);
void copiarCola(Cola* c, int *error, Cola *c_copy);
void destruirCola(Cola *c, int *error);
//void ordenarCola(struct Nodo *nodo,int *error);
void ordenarColaGzu(Cola *c,int *error);
//bool numInARR(int* arr, int num, int tam);
void ingresarIzquierda(Cola *c, int *error, Elemento elemento);
void inicioOperacion(int argc, char** argv);