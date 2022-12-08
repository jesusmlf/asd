#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int valor;
}Dato;

struct Nodo{
    struct Nodo* sig;
    Dato dato;
    int pos;
};

typedef struct Nodo* lista;

lista* initLista(int *error);
Dato extraerN(lista *l,int *error, int index);
Dato extraerDer(lista *l, int *error);
Dato extraerIzq(lista *l, int *error);
void insertarNpos(lista *l, int *error, Dato nuevoDato, int index);
void insertarIzq(lista *l, int *error, Dato nuevoDato);
void insertarDer(lista *l, int *error, Dato nuevoDato);
bool isEmpty(lista *l, int *error);
int PosMax(lista *l, int *error);
void recorrerLista(lista *l, int *error);

Dato extraerN(lista *l,int *error, int index){
    Dato datoExtraido;
    struct Nodo* aux = *l;
    struct Nodo* aux2;

    if(isEmpty(l,error)){
        perror("No hay elementos");
    }else if(PosMax(l,error) < index){
        perror("Indice fuera de rango");
    }else if(PosMax(l,error) == index){
        datoExtraido =  extraerDer(l,error);
    }else if(index == 0){
        datoExtraido = extraerIzq(l,error);
    }else{
        for(int i=0; i<index-1; i++){
            aux = aux->sig;
        }
        aux2 = aux->sig;
        aux->sig = aux2->sig;
        aux2->sig = NULL;
        free(aux2);
    }
}

Dato extraerDer(lista *l, int *error){
    struct Nodo* aux = *l;
    struct Nodo* aux2;
    Dato datoExtraido;
    if(isEmpty(l,error)){
        perror("No se pueden extraer elementos");
    }else if(PosMax(l,error) == 0){
        datoExtraido = extraerIzq(l,error);
    }else{
        while(aux->sig->sig != *l){
            aux = aux->sig;
        }
        
        aux2 = aux->sig;
        datoExtraido = aux2->dato;
        aux->sig = *l;
        aux2->sig = NULL;
        free(aux2);
    }
    printf("\nValor extraido: %d",datoExtraido.valor);
    return datoExtraido;
}

Dato extraerIzq(lista *l, int *error){
    struct Nodo* aux = *l;
    Dato datoExtraido;
    if(isEmpty(l,error)){
        perror("Lista vacia");
    }else if((*l)->sig == *l){
        //Solo hay un unico elemento en la lista
        datoExtraido = (*l)->dato;
        aux = *l;
        aux->sig = NULL;
        free(aux);
        *l = NULL;
    }else{
        //Existe mas de un elemento en la lista
        struct Nodo* aux2 = *l;
        datoExtraido = (*l)->dato;
        
        while(aux2->sig != *l){
            aux2 = aux2->sig;
        }
        *l = (*l)->sig;
        aux2->sig = *l;
        aux->sig = NULL;
        free(aux);

        //Actualizando posiciones
        aux2 = *l;
        do{
            aux2->pos -= 1;
            aux2 = aux2->sig;
        }while(aux2 != *l);
    }
    printf("\nValor extraido: %d",datoExtraido.valor);
    return datoExtraido;
}

void insertarNpos(lista *l, int *error, Dato nuevoDato, int index){
    if(PosMax(l,error) < index){
        perror("La posición no existe");
    }else if(index == 0){
        //La posicion es la primera
        insertarIzq(l,error,nuevoDato);

    }else if(PosMax(l,error) == index){
        //La posicion es la ultima
        insertarDer(l,error,nuevoDato);
    
    }else{
        //La posicion no es la primera ni la ultima
        struct Nodo* aux = *l;
        struct Nodo* newNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
        newNodo->dato = nuevoDato;
        for(int i=0;i<index-1;i++){
            aux = aux->sig;
        }
        newNodo->sig = aux->sig;
        aux->sig = newNodo;
        newNodo->pos = index;

        //Actualizar posiciones
        aux = newNodo; //Nos movemos al nuevo dato que acabamos de insertar para
                      //actualizar las posiciones siguientes a el.
        do{
            aux = aux->sig;
            aux->pos += 1;
        }while(aux->sig != *l);
    }
}

void insertarDer(lista *l, int *error, Dato nuevoDato){
    struct Nodo* newNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    struct Nodo* aux = *l;
    newNodo->dato = nuevoDato;

    if(isEmpty(l,error)){
        insertarIzq(l,error,nuevoDato);
    }else{
        while (aux->sig != *l){
            aux = aux->sig;
        }
        aux->sig = newNodo;
        newNodo->sig = *l;
        newNodo->pos = aux->pos + 1;
    }
}

void insertarIzq(lista *l, int *error, Dato nuevoDato){
    struct Nodo* newNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    struct Nodo* aux = *l;
    newNodo->dato = nuevoDato;
    newNodo->pos = 0;

    if(isEmpty(l,error)){
        printf("\nEsta vacia");
        newNodo->sig = newNodo;
        *l = newNodo;
    }else{
        //printf("\nLista no vacia");
        newNodo->sig = *l;
        while (aux->sig != *l){ //Llegamos al nodo que esta antes de la cabeza
            aux = aux->sig;
        }
        aux->sig = newNodo; //Enlazamos ese nodo a la nueva cabeza
        *l = newNodo; //Actualizamos la cabeza

        //Actualizamos las posiciones
        aux = *l;
        do{
            aux = aux->sig;
            aux->pos += 1;
        }while(aux->sig != *l);
    }
}

void recorrerLista(lista *l, int *error){
    if(isEmpty(l,error)){
        perror("No hay elementos para recorrer la lista");
    }else{
        struct Nodo *aux = *l;
        do{
            printf("\nValor: %d       Pos: %d",aux->dato.valor,aux->pos);
            aux = aux->sig;
        }while(aux != *l);
    }
}

bool isEmpty(lista *l, int *error){
    if(*l == NULL){
        return true;
    }else{
        return false;
    }
}

int PosMax(lista *l, int *error){
    if(isEmpty(l,error)){
        perror("Lista vacia");
    }else{
        struct Nodo* aux = *l;
        while(aux->sig != *l){
            aux = aux->sig;
        }
        return aux->pos;
    }
}

lista* initLista(int *error){
    lista* l = (lista *) malloc(sizeof(lista));
    *l = NULL;
    printf("\nLista creada");
    return l;
}

int main(){
    int error = 0;
    lista* l = initLista(&error);

    Dato dato1; 
    dato1.valor = 10;

    Dato dato2;
    dato2.valor = 20;

    Dato dato3;
    dato3.valor = 30;

    Dato dato4;
    dato4.valor = 100;

    Dato dato5;
    dato5.valor = 500;
    insertarIzq(l,&error,dato1);
    insertarIzq(l,&error,dato2);
    insertarIzq(l,&error,dato3); 
    insertarIzq(l,&error,dato1);

    insertarDer(l,&error,dato4);
    
    insertarNpos(l,&error,dato5,3);
    recorrerLista(l,&error);
    
    printf("\n");
    Dato datoex;
    printf("\n");
    datoex = extraerIzq(l,&error);
    printf("\nExtraer iziq");
    recorrerLista(l,&error);

    printf("\n");
    datoex = extraerDer(l,&error);
    printf("\nPosicion maxima: %d",PosMax(l,&error));
    recorrerLista(l,&error);
}