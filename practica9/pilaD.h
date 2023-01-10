#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
                Tabla de errores
        Variable        Estado      Descripción
        error           -1          Nodo nulo
        error           -2          Pila nula
        error           -3          Pila vacia
        error           0           Sin errores
*/

typedef struct{
    int numero;
}Elemento;

struct Nodo
{
    Elemento elemento;// --> Puede ser otro tipo de dato, incluso otro TDA
    struct Nodo* nodoAnterior;
};

typedef struct{
    struct Nodo* cima;
    int cursor;
}Pila;

Pila* crearPila(int* error);
void apilar(Pila *p, int* error, struct Nodo datoUsuario);//push
void consultarCima(Pila p, int* error);
void desapilar(Pila *p, int* error,struct Nodo *datoExtraido);
bool isEmpty(Pila p, int* error);
void vaciarPila(Pila *p, int* error);
void destruirPila(Pila* p, int* error);
void inicioOperacion(int argc, char** argv);