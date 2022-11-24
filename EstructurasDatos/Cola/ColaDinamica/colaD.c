#include "colaD.h"

void initialize(Cola *c, int *error){
    c->inicio = NULL;
    c->fin = NULL;
    c->tam = 0;
    *error = 0;
}
void encolar(Cola* c, int *error, Elemento elemento){
    struct Nodo* nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    if(nuevoNodo == NULL){
        perror("No hay memoria para crear un nuevo nodo");
        *error = -1;
    }
    if(c->inicio == NULL){
    //Cuando se encola un primer elemento, inicio y cabecera deberan apuntar a él.
    c->inicio = nuevoNodo;
    c->fin = nuevoNodo;
    }else{
        c->fin->sig = nuevoNodo;//El nodo anterior al nuevo nodo apunta al nuevo nodo.
        c->fin = nuevoNodo;
    }
    nuevoNodo->elemento = elemento;
    nuevoNodo->sig = NULL;
    c->tam++;
}

Elemento desencolar(Cola *c, int *error){
    Elemento r;
    struct Nodo* aux;

    if(c->tam == 0){
        perror("Cola vacia");
        *error = -3;
    }
    
    r = c->inicio->elemento;
    
    if(c->tam == 1){
        free(c->inicio);
        c->fin = NULL;
        c->inicio = NULL;
        c->tam = 0;
        *error = -3;
    }else{
        aux = c->inicio;
        c->inicio = c->inicio->sig;
        free(aux);
        c->tam--;
        *error = 0;
    }
    return r;
}
bool isEmpty(Cola c,int *error){
    if(c.tam == 0){
        *error = -3;
        return true;
    }else{
        *error = 0;
        return false;
    }
}
Elemento consultarFrente(Cola c,int *error){
    if(c.tam == 0){
        perror("Cola vacia");
        *error = -3;
    }
    *error = 0;
    return c.inicio->elemento;
}

Elemento consultarFinal(Cola c,int *error){
    if(c.tam == 0){
        perror("Cola vacia");
        *error = -3;
    }
    *error = 0;
    return c.fin->elemento;
}

Elemento consultarN_Elemento(Cola c,int *error,int indice){
    struct Nodo* aux;
    if(isEmpty(c,error)){
        perror("Cola vacia");
        *error = -3;
    }   
    if(indice>c.tam){
        perror("Indice fuera de rango");
        *error = -4;
        }
    
    aux = c.inicio;
    for(int i=0;i<indice;i++){
        //Saltamos n-1 veces
        aux = aux->sig;
    }
    *error = 0;
    return aux->elemento;
    }

void recorrerCola(Cola c, int *error){
    struct Nodo *aux;
    if(c.tam == 0){
        perror("Cola vacia, no se pueden consultar los elementos");
        *error = -3;
    }
    aux = c.inicio;
    for(int i=0;i<c.tam;i++){
        printf("Elemento numero %d: %d",i,c.inicio->elemento.valor);
        aux = aux->sig;
    }
    *error = 0;
}

int size(Cola c,int *error){
    return c.tam;
}

void vaciarCola(Cola* c,int *error){
    struct Nodo *aux;
    if (c->tam == 0){
        perror("Cola vacia");
        *error = -3;
    }
    while(c->inicio != NULL){
        aux = c->inicio->sig;
        free(c->inicio);
        c->inicio = aux;
    }
    c->tam = 0;
    c->fin = NULL;
    //c.inicio ya es null;
}

void destruirCola(Cola *c, int *error){
    if(!isEmpty(*c,error)){
        puts("No se puede eliminar la pila, tiene elementos");
        *error = 0;
    }else{
        puts("Destruyendo pila");
        *error = -2;
        free(c);
    }
}