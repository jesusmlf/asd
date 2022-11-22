#include "pilaD.h"

Pila* crearPila(int* error){
    Pila *p = (Pila*) malloc(sizeof(Pila));
    if(p == NULL){
        perror("No hay memoria para la pila");
        *error = -2;
        return NULL;
    }else{
        p->cima = NULL; //Si la cima apunta a NULL significa que esta vacia
        p->cursor = 0;
        *error = 0;
        return p;
    }
}

void apilar(Pila *p, int* error, struct Nodo datoUsuario){
    struct Nodo* nodoNuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    if (nodoNuevo == NULL){
        perror("No hay memoria para almacenar tu informacion");
        *error = -1;
    }
    if(*error == 2){
        puts("Pila nula");
    }
    else{
        nodoNuevo->elemento = datoUsuario.elemento;
        nodoNuevo->nodoAnterior = p->cima;
        p->cima = nodoNuevo;
        p->cursor++;
        *error = 0;
    }
    return;
}

void desapilar(Pila *p, int* error,struct Nodo *datoExtraido){
    if(isEmpty(*p,error)){
        puts("No hay elementos para desapilar");
        *error = -3;
    }else{
        printf("\nDesapilando");
        struct Nodo* aux = p->cima;
        datoExtraido->elemento = aux->elemento;
        p->cima = aux->nodoAnterior;
        aux->nodoAnterior = NULL;
        p->cursor--;
        free(aux);
        *error = 0;
    }
}
bool isEmpty(Pila p, int* error){
    if(p.cima == NULL){
        *error = -3;
        return true;
    }else{
        *error = 0;
        return false;
    }
}
void consultarCima(Pila p, int* error){
    printf("Error:%d",*error);
    if(isEmpty(p,error)==false && *error == 0){
        printf("\nValor en la cima: %d\n",p.cima->elemento.dato);
        *error = 0;
    }else{
        puts("No hay elementos a consultar");
        *error = -3;
    }
}
void vaciarPila(Pila *p, int* error){
    while (!isEmpty(*p,error)){
        struct Nodo datoExtraido;
        desapilar(p,error,&datoExtraido);
        printf("Valor extraido: %d\n",datoExtraido.elemento.dato);
        *error = 0;
    }
    *error = -3;
}
void destruirPila(Pila* p, int* error){
    if(isEmpty(*p,error)){
        puts("Destruyendo pila");
        *error = -2;
        free(p); 
    }else{
        puts("No se puede destruir la pila debido a que contiene informacion");
        *error = 0;   
    }
    return;
}
void inicioOperacion(int argc, char** argv){
    Pila *p;
    int error = 0;
    p = crearPila(&error);

    struct Nodo datoNew;
    struct Nodo datoExtraido;

    datoNew.elemento.dato = 15;

    apilar(p,&error,datoNew);
    consultarCima(*p,&error);
    printf("\n%d",error);
    desapilar(p,&error,&datoExtraido);
    printf("\n%d",error);
    consultarCima(*p,&error);
    printf("\n%d",error);
    consultarCima(*p,&error);
    free(p);
    destruirPila(p,&error);
    
    printf("Pila destruida");
    printf("\n%d",error);
    consultarCima(*p,&error);
    printf("\n%d",error);
    apilar(p,&error,datoNew);
    printf("\n%d",error);
    consultarCima(*p,&error);
    printf("\n%d",error);
}