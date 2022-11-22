#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 30

/*
                Tabla de errores
        Variable        Estado      Descripción
        error           -1          Pila llena
        error           -2          Pila esta Vacia
        error           -3          Nodo/Elemento es Nulo
        error           0           Sin errores
*/

typedef struct{
    //Lo que se desee
    int valor;
}Nodo;

typedef struct{
    Nodo elementos[MAX];
    int cima;
}Pila;

void crearTDA(Pila* p, int* error);
void apilar(Pila *p, int* error, Nodo dato);
void desapilar(Pila *p,int* error, Nodo *datoExtraido);
void consultarCima(Pila *p, int *error);
bool isEmpty(Pila p, int *error);
bool isFull(Pila p, int *error);
void vaciarPila(Pila *p,int *error);
void inicioOperacion(int argv,char** argc);