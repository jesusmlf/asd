#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int coeficiente;
    int exponente;
}Expresion;

struct Nodo{
    struct Nodo* sig;
    Expresion expresion;
    int pos;
};

typedef struct Nodo* lista; //Lista simplemente enlazada

lista* initLista(lista *l, int *error);
bool isEmpty(lista *l, int *error);
void insertarIzq(lista* l, int *error, Expresion nuevaExp);
void insertarDer(lista* l, int *error, Expresion nuevaExp);
void insertarN(lista* l, int *error, Expresion nuevaExp, int pos);
void recorrerLista(lista *l, int *error);
Expresion extraerIzq(lista *l,int *error);
Expresion extraerDer(lista *l,int *error);
Expresion extraerN(lista *l,int *error, int pos);
int numeroNodos(lista* l, int *error);
void actualizarN(lista *l, int *error, Expresion nuevaExp, int pos);

void inicioOperacion(int argc, char** argv);