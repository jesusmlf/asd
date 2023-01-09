#include "biblioteca.h"

lista* initLista(int* error){
    lista *l = (lista*) malloc(sizeof(lista));
    if(l == NULL){
        perror("No se pudo reservar memoria para la lista");
        *error = -1;
    }else{
        *l = NULL;
        printf("\nLista creada correctamente");
    }
    return l;
}

void recorrerLista(lista *l, int *error){
    struct Nodo* aux = *l;
    if(isEmpty(l,error)){
        perror("Esta vacia");
    }else{
        do{
            printf("\nValor: %d   Pos: %d",aux->dato.valor, aux->pos);
            aux = aux->sig;
        }while(aux != *l);
    }
    
}


bool isEmpty(lista* l, int* error){
    if(*l == NULL){
        return true;
    }else{
        return false;
    }
}

int numeroNodos(lista* l, int *error){
    
    return (*l)->ant->pos + 1;
}

Dato extraerIzq(lista *l, int *error){
    Dato dato;
    struct Nodo* aux2;
    struct Nodo* aux;

    if(*l == NULL){
        perror("\nLista vacia");
        *error = -1;
    }else{
        aux = *l;
        dato = (*l)->dato;
        if(aux != (*l)->sig){
            (*l) = aux->sig;
            (*l)->ant = aux->ant;
            aux->ant->sig = *l;
            aux->ant = NULL;
            aux->sig = NULL;
            aux2 = *l;
            free(aux);
            //Actualizar posiciones
            do{
                aux2->pos -= 1; //aux->pos = aux->pos -1
                aux2 = aux2->sig;
            }while(aux2 != *l);
        }else{
            aux->sig = NULL;
            aux->ant = NULL;
            free(aux);
            *l = NULL;
        }
        printf("\nDato extraido: %d",dato.valor);
    }
    return dato;
}

void vaciarLista(lista* l, int *error){
    while(*l != NULL){
        Dato asd = extraerIzq(l,error);
    }
    printf("\nLista BaZiaDa");
}

void actualizarNodo(lista* l, int *error, Dato nuevoDato, int pos){
    struct Nodo* aux = *l;
    if(isEmpty(l,error)){
        perror("\nLista vacia");
        *error = -2;
    }else{
        for(int i=0; i<pos; i++){
            aux = aux->sig;
        }
        aux->dato = nuevoDato;
    }
}

void insertarN(lista *l, int* error, Dato nuevoDato, int pos){
    struct Nodo* aux = *l;
    struct Nodo* newNodo;
    newNodo->dato = nuevoDato;
    if( (numeroNodos(l,error)-1) < pos){
        perror("Indice fuera de rango");
    }else{
        for(int i=0; i<pos-1; i++){
            aux = aux->sig;
        }
        if(aux->sig != *l){
            newNodo->ant = aux;
            newNodo->sig = aux->sig;
            aux->sig->ant = newNodo;
            aux->sig = newNodo;
        }
    }
}


void insertarDer(lista *l, int* error, Dato nuevoDato){
    struct Nodo* newNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    struct Nodo* aux;
    newNodo->dato = nuevoDato;
    if(newNodo == NULL){
        perror("No se puede crear un nuevo nodo");
        *error = -2;
    }else{
        if(isEmpty(l,error)){
    	    insertarIzq(l,error,nuevoDato);
        }else{
            newNodo->sig = *l;
            newNodo->ant = (*l)->ant;
            newNodo->pos = (*l)->ant->pos + 1;
            (*l)->ant->sig = newNodo;
            (*l)->ant = newNodo;
        }
    }
}

void insertarIzq(lista *l, int* error, Dato nuevoDato){
    struct Nodo* newNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    struct Nodo* aux = *l;

    if(newNodo == NULL){
        perror("No se pudo reservar memoria para el nuevo nodo");
        *error = -2;
    }else{
        newNodo->dato = nuevoDato;
        newNodo->pos = 0;
        if(isEmpty(l,error)){
            (*l) = newNodo;
            newNodo->sig = newNodo;
            newNodo->ant = newNodo;
        }else{
            newNodo->dato = nuevoDato;
            newNodo->pos = 0;
            newNodo->sig = *l;
            newNodo->ant = (*l)->ant;
            (*l)->ant->sig = newNodo;
            (*l)->ant = newNodo;
            *l = newNodo;
            //Actualizando posiciones
            do{
                aux->pos += 1;
                aux = aux->sig;
            }while(aux != *l);
        }
    }
}

void inicioOperacion(int argc, char ** argv){
    int error = 0;
    lista *l = initLista(&error);
    Dato dato1;
    dato1.valor = 2;
    Dato dato2;
    dato2.valor = 3;
    Dato dato3;
    dato3.valor = 100;
    Dato dato4;
    dato4.valor = 1000;

    Dato datoex;
    insertarIzq(l,&error,dato1);
    insertarIzq(l,&error, dato3);
    insertarDer(l,&error,dato2);
    insertarIzq(l,&error,dato1);
    //insertarN(l,&error,dato4,1);

    recorrerLista(l,&error);
    printf("\n\n");
    //datoex = extraerIzq(l,&error);
    actualizarNodo(l,&error, dato4,2);

    recorrerLista(l,&error); 
    //printf("\nNumero de nodos: %d",numeroNodos(l,&error));

    vaciarLista(l,&error);
    recorrerLista(l,&error); 
}
