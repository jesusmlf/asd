#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int valor;
}Dato;


struct Nodo{
    Dato dato;
    struct Nodo* sig;
    struct Nodo* ant;
    int pos;
};

typedef struct Nodo* lista;

lista* initLista(int* errro);
bool isEmpty(lista* l, int* error);
void recorrerLista(lista *l, int *error);
int numeroNodos(lista* l, int *error);
void vaciarLista(lista* l, int *error);
void actualizarNodo(lista* l, int *error, Dato nuevoDato, int pos);
Dato extraerIzq(lista *l, int *error);
void insertarIzq(lista *l, int* error, Dato nuevoDato);
void insertarDer(lista *l, int* error, Dato nuevoDato);
void insertarN(lista *l, int* error, Dato nuevoDato, int pos);

void inicioOperacion(int argc, char ** argv);