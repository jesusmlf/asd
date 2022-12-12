#include "biblioteca.h"

lista* initLista(lista *l, int *error){
    lista *l = (lista *) malloc(sizeof(lista));
    if(l == NULL){
        perror("No se pudo reservar memoria para la lista");
        *error = -2;
    }else{
        *error = -1;
        *l = NULL;
    }
    return *l;
}

bool isEmpty(lista *l, int *error){
    if(*l == NULL){
        return true;
    }else{
        return false;
    }
}

void insertarIzq(lista* l, int *error, Expresion nuevaExp){
    struct Nodo* nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    struct Nodo* aux;

    nuevoNodo->pos = 0;
    nuevoNodo->expresion = nuevaExp;
    if(isEmpty(l,error)){
        nuevoNodo->sig = NULL;
    }else{
        nuevoNodo->sig = *l;
        aux = nuevoNodo;
        while(aux->sig != NULL){
            aux = aux->sig;
            aux->pos += 1; 
        }
    }
    *l = nuevoNodo;
}

void insertarDer(lista* l, int *error, Expresion nuevaExp){
    if(isEmpty(l,error)){
        insertarIzq(l,error,nuevaExp);
    }else{
        struct Nodo* nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
        struct Nodo* aux = *l;

        nuevoNodo->expresion = nuevaExp;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevoNodo;
        nuevoNodo->pos = aux->pos + 1;
        nuevoNodo->sig = NULL;
    }
}
void insertarN(lista* l, int *error, Expresion nuevaExp, int pos){
    struct Nodo* aux = *l;
    if(pos == 0){
        insertarIzq(l,error,nuevaExp;
    }else{
        for(int i=0;i<pos-1;i++){
            aux = aux->sig;
            if(aux->sig == NULL){
                printf("\nNo existe la posición %d",pos);
                //insertarDer(l,error,datoUsuario);
                //*error = -2;
                return;
            }
        }
        if(aux->sig == NULL){
            insertarDer(l,error,nuevaExp);
        }else if(aux->sig != NULL && aux->pos < pos){
            struct Nodo* nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
            nuevoNodo->pos = pos;
            nuevoNodo->expresion = nuevaExp;
            nuevoNodo->sig = aux->sig;
            aux->sig = nuevoNodo;
            aux = nuevoNodo;
            while(aux->sig != NULL){
                aux = aux->sig;
                aux->pos += 1;
            }
        }
    }
}

void recorrerLista(lista *l, int *error){
    struct Nodo* aux = *l;
    while(aux != NULL){
        printf("\nValor: %d   Pos: %d",aux->dato.valor,aux->pos);
        aux = aux->sig;
    }
}
Expresion extraerIzq(lista *l,int *error);
Expresion extraerDer(lista *l,int *error);
Expresion extraerN(lista *l,int *error, int pos);
int numeroNodos(lista* l, int *error);
void actualizarN(lista *l, int *error, Expresion nuevaExp, int pos);

void inicioOperacion(int argc, char** argv);