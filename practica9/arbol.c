#include "arbol.h"

void insertarElemento(Elemento_arbol raiz, int* error, Dato nuevoDato){
    if(*raiz == NULL){
        //Si el arbol esta vacio
        *raiz = (struct Nodo*) malloc(sizeof(struct Nodo));
        (*raiz)->dato = nuevoDato;
        (*raiz)->der = (*raiz)->izq = NULL;
    }else if(nuevoDato < (*raiz)->dato){
        insertarElemento(&((*raiz)->izq),error,nuevoDato);
    }else{
        insertarElemento(&((*raiz)->der),error,nuevoDato);
    }
}

void preOrden(struct Nodo* nodo_arbol){
    if(nodo_arbol){
        printf("%d ",nodo_arbol->dato);
        inOrden(nodo_arbol->izq);
        inOrden(nodo_arbol->der);
    }    
}

void inOrden(struct Nodo* nodo_arbol, int contador){
    contador = 0;
    if(nodo_arbol){ 
        contador++; 
        inOrden(nodo_arbol->izq, contador);
        printf("%d ",nodo_arbol->dato, contador);
        inOrden(nodo_arbol->der, contador);
    }
}

void posOrden(struct Nodo* nodo_arbol){
    if(nodo_arbol){
        inOrden(nodo_arbol->izq);
        inOrden(nodo_arbol->der);
        printf("%d ",nodo_arbol->dato);
    }    
}

void eliminarElemento(Elemento_arbol raiz, int* error, Dato datoEliminar){
    if(*raiz == NULL){
        //Arbol vacio
        return;
    }
    if(datoEliminar < (*raiz)->dato){
        eliminarElemento(&(*raiz)->izq,error,datoEliminar);
    }else if(datoEliminar > (*raiz)->dato){
        eliminarElemento(&(*raiz)->der,error,datoEliminar);
    }else{
        //El nodo a eliminar es el nodo actual

        if((*raiz)->izq == NULL && (*raiz)->der == NULL){
            //El nodo es un nodo hoja
            free(*raiz);
            *raiz = NULL;
        }else if((*raiz)->izq == NULL){
            //El nodo tiene solamente un hijo derecho
            struct Nodo* aux = *raiz;
            *raiz = (*raiz)->der; //La posicion del nodo actual es sustituida por el hijo derecho del nodo eliminado
            free(aux); //Eliminamos el nodo
        }else if((*raiz)->der == NULL){
            //El nodo tiene solamente un hijo izquierdo
            struct Nodo* aux = *raiz;
            *raiz = (*raiz)->izq;
            free(aux);
        }else{
            //El nodo tiene dos hijos
            struct Nodo* aux = (*raiz)->der;
            while (aux->izq != NULL){
                //Llegamos al nodo mas a la izquierda del sub-arbol derecho
                aux = aux->izq;
            }
            (*raiz)->dato = aux->dato; //Sustituimos el valor del nodo a elimnar por el valor del sucesor inmediato
            eliminarElemento(&((*raiz)->der),error,aux->dato); //Eliminamos el sucesor inmediato 
        }
    }
}

void inicioOperacion(int argc, char** argv){
    int error = 0;
    struct Nodo* raiz = NULL;

    
    insertarElemento(&raiz,&error,7);
    insertarElemento(&raiz,&error,15);
    insertarElemento(&raiz,&error,20);
    insertarElemento(&raiz,&error,3);
    insertarElemento(&raiz,&error,15);
    insertarElemento(&raiz,&error,1);
    insertarElemento(&raiz,&error,9);
    insertarElemento(&raiz,&error,10);
    insertarElemento(&raiz,&error,1);
    insertarElemento(&raiz,&error,13);
    insertarElemento(&raiz,&error,24);
    insertarElemento(&raiz,&error,0);
    insertarElemento(&raiz,&error,-3);

    printf("\nRecorrido Pre-orden: ");
    preOrden(raiz);

    printf("\nRecorrido In-orden: ");
    inOrden(raiz);

    printf("\nRecorrido Pos-orden: ");
    posOrden(raiz);

    printf("\n\nEliminando elemento");
    printf("\nRecorrido In-orden: ");
    inOrden(raiz);

    eliminarElemento(&raiz,&error,15);
    
}