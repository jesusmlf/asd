#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


typedef int Dato;

typedef struct{
    char numero;
}Elemento;

struct NodoPila
{
    Elemento elemento;// --> Puede ser otro tipo de dato, incluso otro TDA
    struct NodoPila* NodoPilaAnterior;
};

typedef struct{
    struct NodoPila* cima;
    int cursor;
}Pila;



struct Nodo{
    Dato dato;
    char operacion[50];
    int nivel;
    struct Nodo* der;
    struct Nodo* izq;
};

typedef struct Nodo** Elemento_arbol;

void insertarElemento(Elemento_arbol raiz, int* error, Dato nuevoDato,int nivel, char expresion[50]);
void eliminarElemento(Elemento_arbol raiz, int* error, Dato datoEliminar);
void preOrden(struct Nodo* nodo_arbol);
void inOrden(struct Nodo* nodo_arbol);
void PosOrden(struct Nodo* nodo_arbol);
int evaluarExpresion(struct Nodo* nodo_arbol, int* error,Pila *p);

Pila* crearPila(int* error);
void apilar(Pila *p, int* error, char numero);//push
void consultarCima(Pila p, int* error);
char desapilar(Pila *p, int* error);
bool isEmpty(Pila p, int* error);
void vaciarPila(Pila *p, int* error);
void destruirPila(Pila* p, int* error);

void inicioOperacion(int argc, char** argv);