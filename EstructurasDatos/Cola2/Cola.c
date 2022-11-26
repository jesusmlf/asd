#include "Cola.h"

void crearCola(Cola *c,int *error){
    if(*error == -2){
        perror("Cola nula");
    }
    c->cab = NULL;
    c->fin = NULL;
    c->cursor = 0;
}

void encolar(Cola *c, int *error, DatoG datoUsuario){
    struct Nodo* nuevoNodo = (struct Nodo *) malloc(sizeof(struct Nodo));
    if(nuevoNodo == NULL){
        perror("No hay memoria suficiente para el nodo");
        *error = -1;
    }
    if(c->fin == NULL){
        //Primer elemento a encolar
        c->cab = nuevoNodo;
        c->fin = nuevoNodo;
    }else{
        //No es el primer elemento a encolar
        c->fin->sig = nuevoNodo;
        c->fin = nuevoNodo;
    }
    nuevoNodo->dato = datoUsuario;
    nuevoNodo->sig = NULL;
    c->cursor++;
}

DatoG desencolar(Cola *c,int *error){
    DatoG datoExtraido;
    struct Nodo* aux;

    if(c->cursor == 0){
        perror("Cola vacia");
        *error = -3;
    }

    datoExtraido = c->cab->dato;

    if(c->cursor == 1){
        //El elemento a extraer sea el unico
        free(c->cab);
        c->cab = NULL;
        c->fin = NULL;
        c->cursor = 0;
        *error = -3;
    }else{
        //Hay mas de un elemento en cola
        aux = c->cab;
        c->cab = c->cab->sig;
        free(aux);
        c->cursor--;
        *error = 0;
    }
    return datoExtraido;
}

int main(){
    //int error = 0;
    ////Declarar la cola
    //Cola *c = (Cola *) malloc(sizeof(Cola));
    //if(c == NULL){
    //    perror("No hay memoria para crear la cola");
    //    error = -2;
    //}
    //DatoG datoExtraido;
    //datoExtraido = desencolar(c,&error);
//
    //crearCola(c,&error);
    //printf("Tamaño: %d",c->cursor);
    //c->cursor++;
    //printf("\nTamaño: %d",c->cursor);

    int error = 0;
    Cola* c = (Cola *) malloc(sizeof(Cola));

    if(c == NULL){
        perror("No hay memoria para crear la cola");
        error = -2;
    }

    crearCola(c,&error);

    DatoG nuevoDato;

    nuevoDato.edad = 18;
    nuevoDato.estatura = 1.80;
    strcpy(nuevoDato.nombre,"Goten Dick");

    printf("-------------Te quiero mucho GotenPi-------------");

    encolar(c,&error,nuevoDato);

    DatoG josueDato;

    josueDato.edad = 20;
    josueDato.estatura = 200;
    strcpy(josueDato.nombre,"CockSue");

    encolar(c,&error,josueDato);

    printf("\n%s",c->cab->dato.nombre);
    printf("\n%s",c->cab->sig->dato.nombre);

    DatoG datoExtraido1;
    datoExtraido1 = desencolar(c,&error);
    printf("\nNombre dato extraido: %s",datoExtraido1.nombre);
    printf("\n%s",c->cab->dato.nombre);

    DatoG datoExtraiod2;
    datoExtraiod2 = desencolar(c,&error);
    printf("\nNombre dato extraido 2: %s",datoExtraiod2.nombre);
}
//
//int main(){
//    //int numero;
//    //printf("Dame un numero: ");
//    //scanf("%d",&numero);
//    //char nombre[20];
//    //printf("Escribe el nombre");
//    //scanf("%s",nombre);
//
//    struct Nodo nodo1;
//
//    nodo1.dato.estatura = 1.70;
//    printf("Estatura: %f",nodo1.dato.estatura);
//
//    strcpy(nodo1.dato.nombre,"Pika");
//    printf("Nombre: %s",nodo1.dato.nombre);
//
//
//    struct Nodo* nodoPuntero = (struct Nodo*) malloc(sizeof(struct Nodo));
//    //malloc -> void
//    //(struct Nodo *)
//
//    nodoPuntero->dato.estatura = 1.80;
//    printf("\n\nEstatura: %f",nodoPuntero->dato.estatura);
//    strcpy(nodoPuntero->dato.nombre,"Rodrigo");
//    printf("\nNombre: %s",nodoPuntero->dato.nombre);
//    free(nodoPuntero);
//}