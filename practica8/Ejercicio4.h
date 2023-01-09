#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int valor;
}Dato;

struct Nodo{
    struct Nodo* sig;
    Dato dato;
    int pos;
};

typedef struct Nodo* lista;

void initLista(lista *l, int *error);
bool isEmpty(lista *l, int *error);
void insertarIzq(lista *l,int *error, Dato datoUsuario);
void insertarDer(lista *l,int *error, Dato datoUsuario);
void insertarN(lista *l, int *error, Dato datoUsuario, int pos);
void recorrerLista(lista *l, int *error);
Dato extraerIzq(lista *l,int *error);
Dato extraerDer(lista *l,int *error);
Dato extraerN(lista *l,int *error, int pos);
void borrarLista(lista *l, int *error);
int maxPos(lista *l, int *error);
void actualizarN(lista *l, int *error, Dato datoUsuario, int pos);
void main(int argc, char** argc);