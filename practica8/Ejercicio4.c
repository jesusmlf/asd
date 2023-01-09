#include "Ejercicio4.h"

void initLista(lista *l, int *error){
    *l = NULL;
    *error = 0;
    printf("\nLista creada correctamente");
}


void main(int argc, char** argv){
    int error = 0;
    lista *l1 = (lista *) malloc(sizeof(lista));
    lista *l2 = (lista *) malloc(sizeof(lista));

    Dato dato1;
    Dato dato2;
    Dato dato3;
    Dato dato4;
    Dato dato5;
    Dato dato6;
    dato1.valor = 1;
    dato2.valor = 2;
    dato3.valor = 2;
    dato4.valor = 1;
    dato5.valor = 7;
    dato6.valor = 9;
    insertarIzq(l1,&error,dato1);
    insertarIzq(l1,&error,dato2);
    insertarIzq(l1,&error,dato3);
    insertarIzq(l2,&error,dato4);
    insertarIzq(l2,&error,dato5);
    insertarIzq(l2,&error,dato6);


}

void mezclarListas(lista *l1, lista *l2, lista* lde, int* error);
void actualizarN(lista *l, int *error, Dato datoUsuario, int pos){
    if(isEmpty(l,error)){
        perror("Lista vacia");
        *error = -1;
    }else{
        if(pos > maxPos(l,error)){
            printf("No existe la posicion: %d",pos);
        }else{
            struct Nodo* aux = *l;
            for(int i=0; i<pos; i++){
                aux = aux->sig;
                //printf("\nPos: %d",aux->pos);
            }
            aux->dato = datoUsuario;
            printf("\nDato actualizado");
        }
    }
}


int maxPos(lista *l, int *error){
    if(isEmpty(l,error)){
        perror("No hay elementos");
        return 0;
    }else{
        struct Nodo* aux = *l;
        while (aux->sig != NULL){
            aux = aux->sig;
        }
        return aux->pos;
    }
}

void borrarLista(lista *l, int *error){
    struct Nodo* aux = *l;
    while (aux->sig != NULL){
        extraerIzq(l,error);
        aux = aux->sig;
    }
    printf("\nSe ha borrado la lista");
}

Dato extraerN(lista *l,int *error,int pos){
    Dato datoExtraido;
    if(isEmpty(l,error)){
        //Lista vacia
        perror("No hay elementos en la lista");
        *error = -2;
    }else{
        if(pos == 0){
            //El dato a extraer es el primer elemento en la lista
            datoExtraido = extraerIzq(l,error);
        }else{
            //El dato a extraer no esta al inicio de la lista
            struct Nodo* aux = *l;
            struct Nodo* aux2;

            for(int i=0; i<pos-1; i++){
                aux = aux->sig;
                if(aux->sig == NULL){
                    printf("No existe la posicion: %d",pos);
                    //insertarDer(l,error,datoUsuario);
                    //*error = -2;
                    break;
                }
            }
            if(aux->sig == NULL){
                //El dato a extraer esta al final de la lista
                datoExtraido = extraerDer(l,error);
            }else{
                //El dato extraido no esta el inicio ni al final
                aux2 = aux->sig;
                datoExtraido = aux->sig->dato;
                aux->sig = aux2->sig;
                free(aux2);
                while(aux->sig != NULL){
                    aux = aux->sig;
                    aux->pos -= 1;
                }
            }
        }
    }
    printf("\nDato extraido: %d",datoExtraido.valor);
    return datoExtraido;
}

Dato extraerDer(lista *l,int *error){
    Dato datoExtraido;
    if(isEmpty(l,error)){
        perror("No hay elementos en la lista");
        *error = -2;
    }else{
        struct Nodo* aux = *l;
        while(aux->sig->sig != NULL){
            aux = aux->sig;
        }
        datoExtraido = aux->sig->dato;
        free(aux->sig);
        aux->sig = NULL;
    }
    printf("\nDato extraido: %d",datoExtraido.valor);
    return datoExtraido;
}

Dato extraerIzq(lista *l,int *error){
    Dato datoExtraido;
    if(isEmpty(l,error)){
        perror("No hay elementos en la lista");
        *error = -2;
    }
    else{
        struct Nodo *aux = *l;
        datoExtraido = (*l)->dato;
        while(aux->sig != NULL){
            aux = aux->sig;
            aux->pos -= 1;
        }
        aux = *l;
        *l = (*l)->sig;
        aux->sig = NULL;
        free(aux);
    }
    printf("\nDato extraido: %d",datoExtraido.valor);
    return datoExtraido;
}

void recorrerLista(lista *l, int *error){
    struct Nodo* aux = *l;
    while(aux != NULL){
        printf("\nValor: %d   Pos: %d",aux->dato.valor,aux->pos);
        aux = aux->sig;
    }
}

void insertarN(lista *l, int *error, Dato datoUsuario, int pos){
    struct Nodo* aux = *l;
    if(pos == 0){
        insertarIzq(l,error,datoUsuario);
    }else{
        for(int i=0;i<pos-1;i++){
            aux = aux->sig;
            if(aux->sig == NULL){
                printf("\nNo existe la posición %d",pos);
                //insertarDer(l,error,datoUsuario);
                //*error = -2;
                return;
            }
        }
        if(aux->sig == NULL){
            insertarDer(l,error,datoUsuario);
        }else if(aux->sig != NULL && aux->pos < pos){
            struct Nodo* nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
            nuevoNodo->pos = pos;
            nuevoNodo->dato = datoUsuario;
            nuevoNodo->sig = aux->sig;
            aux->sig = nuevoNodo;
            aux = nuevoNodo;
            while(aux->sig != NULL){
                aux = aux->sig;
                aux->pos += 1;
            }
        }
    }
}

void insertarDer(lista *l,int *error, Dato datoUsuario){
    if(isEmpty(l,error)){
        insertarIzq(l,error,datoUsuario);
    }else{
        struct Nodo* nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
        struct Nodo* aux = *l;

        nuevoNodo->dato = datoUsuario;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevoNodo;
        nuevoNodo->pos = aux->pos + 1;
        nuevoNodo->sig = NULL;
    }
}

void insertarIzq(lista *l,int *error, Dato datoUsuario){
    struct Nodo* nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    struct Nodo* aux;

    nuevoNodo->pos = 0;
    nuevoNodo->dato = datoUsuario;
    if(isEmpty(l,error)){
        nuevoNodo->sig = NULL;
    }else{
        nuevoNodo->sig = *l;
        aux = nuevoNodo;
        while(aux->sig != NULL){
            aux = aux->sig;
            aux->pos += 1; 
        }
    }
    *l = nuevoNodo;
}

bool isEmpty(lista *l, int *error){
    if(*l == NULL){
        return true;
    }else{
        return false;
    }
}