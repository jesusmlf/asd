#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Dato;

struct Nodo{
    Dato dato;
    struct Nodo* der;
    struct Nodo* izq;
};

typedef struct Nodo** Elemento_arbol;

void insertarElemento(Elemento_arbol raiz, int* error, Dato nuevoDato);
void eliminarElemento(Elemento_arbol raiz, int* error, Dato datoEliminar);
void preOrden(struct Nodo* nodo_arbol);
void inOrden(struct Nodo* nodo_arbol);
void PosOrden(struct Nodo* nodo_arbol);

void inicioOperacion(int argc, char** argv);