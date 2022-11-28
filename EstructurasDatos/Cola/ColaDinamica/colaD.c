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
        printf("\nElemento numero %d: %d",i,aux->elemento.valor);
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
    //free(c);
}

void copiarCola(Cola *c, int *error, Cola *c_copy){
    struct Nodo *aux;
    aux = c->inicio;
    for(int i=0;i<c->tam;i++){
        encolar(c_copy,error,aux->elemento);
        aux = aux->sig;
    }
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

bool numInARR(int* arr, int num, int tam){
    bool flag = false;
    for(int i=0;i<tam;i++){
        if(arr[i] == num){
            flag = true;
        }
    }
    return flag;
}

//void ordenarCola(Cola *c, Cola *c_ordenada, int *error){
//    struct Nodo* min;
//    struct Nodo* aux;
//    struct Nodo* recorre;
//    min = c->inicio;
//    recorre = c->inicio;
//    aux = c->inicio;
//    int j;
//    int arr[c->tam];
//
//    for(int i=0;i<(c->tam)-1;i++){
//        j = 0;
//        if(i==0){
//            min = c->inicio;
//        }
//        else{
//            recorre = recorre->sig;
//            min = recorre;
//            printf("\n--Minimo: %d",min->elemento.valor);
//
//        }
//        while(aux->sig != NULL){
//            if(aux->elemento.valor < min->elemento.valor){
//                min = aux;
//                printf("\nMinimo: %d",min->elemento.valor);
//            }else{
//                aux = aux->sig;
//                printf("--");
//
//                if(aux->sig == NULL){
//                    printf("hola");
//                    min = aux;
//                    printf("\nMinimo: %d",min->elemento.valor);
//                }
//            }
//            j++;
//            
//        }
//        //printf("\nMinimo: %d",min->elemento.valor);
//        arr[i] = j;
//        encolar(c_ordenada,error,min->elemento);
//
//        if(numInARR(arr,j,c->tam) == false){
//            encolar(c_ordenada,error,min->elemento);
//        }
//    }
//    //encolar(c_ordenada,error,c->fin->elemento);
//    for(int i=0;i<c->tam;i++){
//        printf("\n%d",arr[i]);
//    }
//}

//void ordenarCola(struct Nodo *nodo,int *error){
//    struct Nodo* aux=nodo;
//    while(aux->sig!=NULL){
//        if(nodo->elemento.valor > aux->sig->elemento.valor){
//            Elemento dato;
//            dato = nodo->elemento;
//            nodo->elemento.valor=aux->sig->elemento.valor;
//            aux->sig->elemento=dato;
//        }
//        aux=aux->sig;
//    }
//    if(nodo->sig!=NULL){
//        ordenarCola(nodo->sig,error);
//    }
//}

void ordenarColaGzu(Cola *c,int *error){
    struct Nodo* min = c->inicio;
    struct Nodo* recorre = c->inicio;
     Elemento swap;

    for(int i=0;i<c->tam;i++){
        for(int j=0;j<c->tam;j++){
            if(recorre->elemento.valor < min->elemento.valor){
                swap = min->elemento;
                min->elemento = recorre->elemento;
                recorre->elemento = swap;
            }
            if(recorre->sig == NULL){
                break;
            }
            recorre = recorre->sig;
            if(recorre->sig == NULL && (recorre->elemento.valor < min->elemento.valor)){
                    swap = min->elemento;
                    min->elemento = recorre->elemento;
                    recorre->elemento = swap;
            }
        }
        if(min->sig != NULL){
            min = min->sig;
        }
    }
}

void inicioOperacion(int argc, char** argv){
    printf("Inicio");
    Cola* c = (Cola*) malloc(sizeof(Cola));
    int error = 0;

    initialize(c,&error);

    Elemento dato1;
    dato1.valor = 3;

    Elemento dato2;
    dato2.valor = 5;

    Elemento dato3;
    dato3.valor = 1;

    encolar(c,&error,dato1);
    encolar(c,&error,dato2);
    encolar(c,&error,dato3);

    recorrerCola(*c,&error);

    Cola* c_ordenada = (Cola*) malloc(sizeof(Cola));
    
    ordenarColaGzu(c,&error);

    printf("\n");
    recorrerCola(*c,&error);

    //Cola* c_copia = (Cola*) malloc(sizeof(Cola));
//
    //copiarCola(c,&error,c_copia);
    //recorrerCola(*c_copia,&error);
}