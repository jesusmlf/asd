#include "Pila.h"

/*
    @param p Es la pila 
    @param error Es la variable que gestiona errores.
*/
void crearPila(Pila *p, int *error){
    p->cima = -1;
    p->cursor = 0;
    *error = 0;
}


void apilar(Pila* p,int *error, Dato valor){
    if(!estaLlena(*p,error)){
        p->cima++;
        p->elementos[p->cima] = valor;
        *error = 0;
    }
}

void desapilar(Pila *p,Dato* datoExtraido, int *error){
    if(!estaVacia(*p,error)){
        *datoExtraido = p->elementos[p->cima];
        p->cima--;
        *error = 0;
    }
}

void consultarCima(Pila p, int* error){
    if(!estaVacia(p,error)){
        printf("Valor en la cima: %d",p.elementos[p.cima]);
    }
}

bool estaLlena(Pila p, int* error){
    if(p.cima>(TAM-1)){
        *error = -1;
        return true;
    }else{
        *error = 0;
        false;
    }
    
}

bool estaVacia(Pila p, int* error){
    if(p.cimaz<0){
        *error = -2;
        return true;
    }else{
        *error = 0;
        return false;
    }
}