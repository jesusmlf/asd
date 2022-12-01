#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Nodo *lista;

typedef int Dato;

typedef struct Nodo{
    Dato dato;
    struct Nodo *sig;
    int pos;
}Nodo;

void insertarIzq(lista *l, int *error, Dato dato);
void insertarDer(lista *l, int *error, Dato dato);
void insertarNpos(lista *l, int *error, Dato dato, int pos);

void insertarIzq(lista *l, int *error, Dato dato){
    struct Nodo *new = (struct Nodo*) malloc(sizeof(struct Nodo));
    struct Nodo *aux;

    new->dato = dato;
    new->sig = *l;
    new->pos = 0;
    aux = new;

    if(*l != NULL){
        while (aux->sig != NULL){
            aux = aux->sig;
            aux->pos += 1;
        }
    }

    *l = new;
}

void insertarDer(lista *l, int *error, Dato dato){
    struct Nodo *new = (struct Nodo*) malloc(sizeof(struct Nodo));
    struct Nodo *aux;

    if(*l != NULL){
        new->dato = dato;
        aux = (*l);
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = new;
        new->pos = aux->pos + 1;
    }else{
        insertarIzq(l,error,dato);
    }
}

void insertarNpos(lista *l, int *error, Dato dato, int pos){

    struct Nodo *new = (struct Nodo*) malloc(sizeof(struct Nodo));
    struct Nodo *aux = *l;
    new->dato = dato;
    printf("afuera");
    if(*l == NULL){
        printf("Entra");
        //*l = new;
        //(*l)->sig = NULL;
        //(*l)->pos = 0;
        insertarIzq(l,error,dato);
    }

    else if(pos == 0){
        insertarIzq(l,error,dato);
    }

    for(int i=0; i<pos-1; i++){
        aux = aux->sig;
        //Insertar el dato en una posicon que no existe
        //if(aux->sig == NULL){
        //    puts("No se puede ingresar el elemento en la posicion N, se agregara a la derecha");
        //    insertarDer(l,error,dato);
        //    return;
        //}
    }
    if(aux->sig == NULL && pos != 0){
        printf("\nCaso 2");
        //Existe la posicion N-1
        insertarDer(l,error,dato);
    }
    else if(aux->sig != NULL && pos != 0){
        //Existe la posicion
        printf("\nCaso 3");
        new->sig = aux->sig;
        aux->sig = new;
        new->pos = pos;
        aux = aux->sig;

        while (aux->sig != NULL){
            aux = aux->sig;
            aux->pos += 1;
        }
    }
}

int main(){
    lista *l;
    struct Nodo* vacio = NULL;
    *l = vacio; //Inicializamos la cola vacia
    int error = 0;

    Dato nuevoDato = 10;
    insertarIzq(l,&error,nuevoDato);

    Dato nuevoDato2 = 20;
    //insertarIzq(l,&error,nuevoDato2);

    Dato nuevoDato3 = 30;
    //insertarDer(l,&error,nuevoDato3);


    //printf("\nValor primer dato: %d",(*l)->dato);
    //printf("\nValor segundo dato: %d",(*l)->sig->dato);
    //printf("\nValor tercer dato: %d",(*l)->sig->sig->dato);

    Dato nuevoDato4 = 50;
//
    //printf("\n-----------------");
    if(*l == NULL){
        insertarDer(l,&error,nuevoDato4);
    }else{
        insertarNpos(l,&error,nuevoDato4,1);
    }
    
    printf("\nValor primer dato: %d Posicion %d",(*l)->dato,(*l)->pos);
    printf("\nValor segundo dato: %d Posicion %d",(*l)->sig->dato,(*l)->sig->pos);
    //printf("\nValor tercer dato: %d Posicion %d",(*l)->sig->sig->dato,(*l)->sig->sig->pos);
    //printf("\nValor cuarto dato: %d Posicion %d",(*l)->sig->sig->sig->dato,(*l)->sig->sig->sig->pos);
}