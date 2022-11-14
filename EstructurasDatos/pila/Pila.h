#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define TAM 10

/*
    Variable Error          Estado          Significado
        error                 0                 Todo ok
        error                 -1                Pila llena
        error                  -2               Pila vacia
        error                   -3              Algo es NULL
*/


typedef int Dato;

typedef struct
{
    Dato elementos;
    int cima;
    int cursor;
}Pila;

void crearPila(Pila *p, int *error);
void apilar(Pila* p,int *error, Dato valor);
void desapilar(Pila* p,Dato* datoExtraido, int *error);
void consultarCima(Pila p, int* error);
bool estaLlena(Pila p, int* error);
bool estaVacia(Pila p, int* error);
