#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int valor;
    char caracter;
}Dato;


struct Nodo{
    struct Nodo* sig;
    Dato dato;
    int pos;
};

typedef struct Nodo* lista;

lista* initLista(int *error);
Dato extraerN(lista *l,int *error, int index);
Dato extraerDer(lista *l, int *error);
Dato extraerIzq(lista *l, int *error);
void insertarNpos(lista *l, int *error, Dato nuevoDato, int index);
void insertarIzq(lista *l, int *error, Dato nuevoDato);
void insertarDer(lista *l, int *error, Dato nuevoDato);
bool isEmpty(lista *l, int *error);
int PosMax(lista *l, int *error);
void recorrerLista(lista *l, int *error);
bool esPalindromo(lista* l, int *error);

void main(int argc, char** argv);