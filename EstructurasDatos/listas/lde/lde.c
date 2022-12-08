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
void insertarDer(Lista *l, int *error, Dato nuevoDato);
int maxPos(Lista *l, int *error);
bool isEmpty(Lista *l, int *error);
void recorrerLista(Lista *l, int *error);
int contarNodos(Lista *l,int *error);

int main(){
    int error = 0;
    Lista *l = initLista(&error);

    Dato dato =  10;
    Dato daton = 20;
    Dato dato3 = 0;
    insertarIzq(l,&error,dato);
    insertarIzq(l,&error,dato);
    insertarIzq(l,&error,dato);
    insertarDer(l,&error,daton);
    insertarDer(l,&error,daton);
    insertarDer(l,&error,daton);
    insertarN(l,&error,dato3,2);
    recorrerLista(l,&error);
    printf("\nNodos: %d",contarNodos(l,&error));
    
    
}
int contarNodos(Lista *l,int *error){
    if(isEmpty(l,error)){
        return 0;
    }else{
        struct Nodo* aux = *l;
        int contador = 0;
        while(aux != NULL){
            aux = aux->sig;
            contador++;
        }
        return contador;
    }
    
}
void recorrerLista(Lista *l, int *error){
    struct Nodo *aux = *l;
    while (aux != NULL){
        printf("\nValor: %d       Pos: %d",aux->valor,aux->pos);
        aux = aux->sig;
    }
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
    if(newNodo == NULL){
        perror("Nodo nulo");
        *error = -3; //Nodo nulo
    }else{
            if(isEmpty(l,error) && index != 0 || contarNodos(l,error) < index){
            perror("Indice fuera de rango");
            *error = -4;
            free(newNodo);
        }else if(index == 0){
            insertarIzq(l,error,nuevoDato);
            free(newNodo);
        }else if(contarNodos(l,error) == index){
            newNodo->valor = nuevoDato;
            newNodo->pos = index;
            while(aux->sig != NULL){
                aux = aux->sig;
            }
            aux->sig = newNodo;
            newNodo->sig = NULL;
            newNodo->ant = aux;
        }else{
            newNodo->valor = nuevoDato;
            newNodo->pos = index;

            for(int i=0; i<index-1; i++){
                aux = aux->sig;
            }
            newNodo->sig = aux->sig;
            newNodo->ant = aux;
            aux->sig->ant = newNodo;
            aux->sig = newNodo;

            //Actualizando posiciones
            aux = aux->sig;
            while(aux->sig != NULL){
                    aux = aux->sig;{
                    aux->pos += 1;
                }
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
        aux = newNodo;
        while(aux->sig != NULL){
            aux = aux->sig;
            aux->pos += 1;
        }
        *l = newNodo;
    }
}

void insertarDer(Lista *l, int *error, Dato nuevoDato){
    if(isEmpty(l,error)){
        insertarIzq(l,error,nuevoDato);
    }else{
        struct Nodo *aux;
        struct Nodo *newNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
        newNodo->sig = NULL;
        newNodo->valor = nuevoDato;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = newNodo;
        newNodo->ant = aux;
        newNodo->pos = aux->pos + 1;
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