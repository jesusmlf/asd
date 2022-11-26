#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
                Tabla de errores
        Variable        Estado      Descripción
        error           -1          Nodo nulo
        error           -2          Cola nula
        error           -3          Cola vacia
        error           -4          Indice invalido
        error           0           Sin errores
*/

typedef struct{
    char nombre[20];
    float estatura;
    int edad;
}DatoG;

struct Nodo{
    struct Nodo* sig;
    DatoG dato;
};

typedef struct{
    struct Nodo* cab;
    struct Nodo* fin;
    int cursor;
}Cola;

//Prototipos
void crearCola(Cola *c,int *error);
void encolar(Cola *c, int *error, DatoG datoUsuario);
DatoG desencolar(Cola *c,int *error);
