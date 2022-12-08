#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef int Dato;

struct Nodo{
    Dato valor;
    int pos;
    struct Nodo* ant;
    struct Nodo* sig;
};

typedef struct Nodo* Lista;

Lista* initLista(int* error);
void insertarIzq(Lista *l, int *error, Dato nuevoDato);
void insertarN(Lista *l, int *error, Dato nuevoDato, int index);
int maxPos(Lista *l, int *error);
bool isEmpty(Lista *l, int *error);
void recorrerLista(Lista *l, int *error);

int main(){
    int error = 0;
    Lista *l = initLista(&error);

    Dato dato =  10;
    Dato daton = 20;
    insertarIzq(l,&error,dato);
    insertarIzq(l,&error,dato);
    insertarIzq(l,&error,dato);
    recorrerLista(l,&error);
    //insertarN(l,&error,daton,0);
    
    
}

void recorrerLista(Lista *l, int *error){
    struct Nodo *aux = *l;
    while (aux->sig != NULL){
        printf("\nValor: %d       Pos: %d",aux->valor,aux->pos);
        aux = aux->sig;
    }
    printf("\nFuera");
}

int maxPos(Lista *l, int *error){
    struct Nodo *aux = *l;
    while(aux->sig != NULL){
        aux = aux->sig;
    }
    return aux->pos;
}

bool isEmpty(Lista *l, int *error){
    if(*l == NULL){
        return true;
    }else{
        return false;
    }
}



void insertarN(Lista *l, int *error, Dato nuevoDato, int index){
    struct Nodo* newNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    struct Nodo* aux = *l;
    struct Nodo* aux2;

    if(isEmpty(l,error) && index != 0){
        perror("Indice fuera de rango");
    }else if(maxPos(l,error) < index){
        perror("Indice fuera de rango");
    }else if(index == 0){
        insertarIzq(l,error,nuevoDato);
    }else if(index == maxPos(l,error)){
        //insertarDer(l,error,nuevoDato);
    }else{
        newNodo->valor = nuevoDato;
        for(int i=0; i<index-1; i++){
            aux = aux->sig;
        }
        aux2 = aux->sig;
        aux2->ant = newNodo;
        newNodo->sig = aux2;
        aux->sig = newNodo;
        newNodo->ant = aux;
        aux = newNodo;
        while(aux->sig != NULL){
                aux = aux->sig;{
                aux->pos += 1;
            }
        }
    }
}
void insertarIzq(Lista *l, int *error, Dato nuevoDato){
    struct Nodo* newNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    struct Nodo* aux;
    newNodo->valor = nuevoDato;
    newNodo->pos = 0;
    if(isEmpty(l,error)){
        *l = newNodo;
        newNodo->sig = NULL;
        newNodo->ant = NULL;
    }else{
        newNodo->sig = *l;
        newNodo->ant = NULL;
        (*l)->ant = newNodo;
        aux = *l;
        while(aux->sig != NULL){
            aux = aux->sig;
            aux->pos += 1;
        }
    }
}

Lista* initLista(int* error){
    Lista *l = (Lista*) malloc(sizeof(Lista));
    if(l == NULL){
        perror("No se pudo crear la lista");
        return NULL;
    }else{
        *l = NULL;
        printf("\nLista creadad correctamente");
        return l;
    }
}