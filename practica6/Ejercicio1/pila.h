#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 8
#define LEN_EXP 30 //Longitud en caracteres de la expresion a leer
#define EXPRESIONES 8 //Cantidad de expresiones a leer

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
    char parentesis;
}Nodo;

typedef struct{
    Nodo elementos[EXPRESIONES+1];
    int cima;
}Pila;

void crearTDA(Pila* p, int* error);
void apilar(Pila *p, int* error, Nodo dato);
void desapilar(Pila *p,int* error, Nodo *datoExtraido);
char consultarCima(Pila *p, int *error);
bool isEmpty(Pila p, int *error);
bool isFull(Pila p, int *error);
void vaciarPila(Pila *p,int *error);
void inicioOperacion(int argv,char** argc);