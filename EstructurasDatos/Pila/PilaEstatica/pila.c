#include "pila.h"

void crearTDA(Pila* p, int* error){
    p->cima = -1;
    *error = 0;
}

void apilar(Pila *p, int* error, Nodo dato){
    if(!isFull(*p,error)){
        (*p).cima++;
        p->elementos[p->cima] = dato;
        *error = 0;
    }else{
        puts("Pila llena");
        *error = -1;
    }
}

void desapilar(Pila *p,int* error, Nodo *datoExtraido){
    if(!isEmpty(*p,error)){
        *datoExtraido = p->elementos[p->cima];
        p->cima--;
        *error = 0;
    }else{
        puts("Pila vacia, no hay elementos para extraer");
        *error = -2;
    }
}

void consultarCima(Pila *p, int *error){
    printf("\nEl valor de la cima es %d y contiene el valor: %d", p->cima,p->elementos[p->cima].valor);
    return;
}

bool isEmpty(Pila p, int *error){
    if(p.cima == -1){
        *error = -2;
        return true;
    }else{
        *error = 0;
        return false;
    }
}

bool isFull(Pila p, int *error){
    if(p.cima == MAX-1){
        *error = -1;
        return true;
    }else{
        *error = 0;
        return false;
    }
}

void vaciarPila(Pila *p, int *error){
    Nodo datoAuxiliar;
    puts("Comienza el proceso de vaciado");
    while(!isEmpty(*p,error)){
        desapilar(p,error,&datoAuxiliar);
        printf("El valor extraido es: %d\n",datoAuxiliar.valor);
    }
    puts("Se termino de vaciar la pila");
}

void inicioOperacion(int argv,char** argc){
    //Creando la pila
    Pila* p;
    int error = 0;
    crearTDA(p,&error);
    printf("Pila creada correctamente");

    Nodo datoApilar;
    datoApilar.valor = 10;

    
    apilar(p,&error,datoApilar);
    consultarCima(p,&error);

    Nodo datoDesapilar;
    desapilar(p,&error,&datoDesapilar);

    printf("\nDato desapilado: %d",datoDesapilar.valor);
    consultarCima(p,&error);
    vaciarPila(p,&error);
    consultarCima(p,&error);
}