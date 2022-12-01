#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int valor;
}Dato;

struct Nodo{
    Dato dato;
    struct Nodo* sig;
    int pos;
};

typedef struct Nodo *Lista;
Lista *l;

void insertarIzq(Lista *l, int *error, Dato dato){
    struct Nodo* nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    if(nuevo == NULL){
        perror("No se pudo reservar memoria para el nuevo nodo");
    }

    if(*l == NULL){
        *l = nuevo;
        nuevo->pos = 0;
        nuevo->sig = NULL;
    }else{
        struct Nodo* aux = *l;
        aux = *l;
        *l = nuevo;
        nuevo-
        nuevo->pos = 0;
    }
    *error = 0;
}

int main(int argc, char** argv){
    Lista *l;
    printf("Inicio");
    int error = 0;
    Dato datoInsertar;
    datoInsertar.valor = 10;
    insertarIzq(l,&error,datoInsertar);

}