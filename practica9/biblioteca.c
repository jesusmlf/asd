#include "biblioteca.h"

void leer(Elemento_arbol raiz, int* error){
    char operacion[50];
    printf("\nIngresa la expresion: ");
    scanf("%s",operacion);
    
    Dato numero_aleatorio = (rand() % (16 - 1 + 1)) + 1;
    insertarElemento(raiz,error,numero_aleatorio,-2,operacion);
    return;
}
void insertarElemento(Elemento_arbol raiz, int* error, Dato nuevoDato, int nivel, char expresion[50]){
    nivel++;
    if(*raiz == NULL){
        //Si el arbol esta vacio
        *raiz = (struct Nodo*) malloc(sizeof(struct Nodo));
        (*raiz)->dato = nuevoDato;
        (*raiz)->der = (*raiz)->izq = NULL;
        (*raiz)->nivel = nivel + 1;
        strcpy((*raiz)->operacion, expresion);
        
    }else if(nuevoDato < (*raiz)->dato){
        insertarElemento(&((*raiz)->izq),error,nuevoDato,nivel,expresion);
    }else{
        insertarElemento(&((*raiz)->der),error,nuevoDato,nivel,expresion);
    }
}

void preOrden(struct Nodo* nodo_arbol){
    if(nodo_arbol){
        printf("%d ",nodo_arbol->dato);
        preOrden(nodo_arbol->izq);
        preOrden(nodo_arbol->der);
    }    
}

void inOrden(struct Nodo* nodo_arbol){
    if(nodo_arbol){
        inOrden(nodo_arbol->izq);
        printf("\nNivel: %d - Prioridad: %d- Expresion: %s",nodo_arbol->nivel,nodo_arbol->dato,nodo_arbol->operacion);
        inOrden(nodo_arbol->der);
    }
}

void posOrden(struct Nodo* nodo_arbol){
    if(nodo_arbol){
        posOrden(nodo_arbol->izq);
        posOrden(nodo_arbol->der);
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

void apilar(Pila *p, int* error, char numero){
    struct NodoPila* NodoPilaNuevo = (struct NodoPila*) malloc(sizeof(struct NodoPila));
    if (NodoPilaNuevo == NULL){
        perror("No hay memoria para almacenar tu informacion");
        *error = -1;
    }
    if(*error == 2){
        puts("Pila nula");
    }
    else{
        NodoPilaNuevo->elemento.numero = numero;
        NodoPilaNuevo->NodoPilaAnterior = p->cima;
        p->cima = NodoPilaNuevo;
        p->cursor++;
        *error = 0;
    }
    return;
}

char desapilar(Pila *p, int* error){
    char ch;
    if(isEmpty(*p,error)){
        puts("No hay elementos para desapilar");
        *error = -3;
    }else{
        //printf("\nDesapilando");
        struct NodoPila* aux = p->cima;
        ch = aux->elemento.numero;
        p->cima = aux->NodoPilaAnterior;
        aux->NodoPilaAnterior = NULL;
        p->cursor--;
        free(aux);
        *error = 0;
    }
    return ch;
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
        printf("\nValor en la cima: %d\n",p.cima->elemento.numero);
        *error = 0;
    }else{
        puts("No hay elementos a consultar");
        *error = -3;
    }
}
void vaciarPila(Pila *p, int* error){
    while (!isEmpty(*p,error)){
        struct NodoPila datoExtraido;
        desapilar(p,error);
        printf("Valor extraido: %d\n",datoExtraido.elemento.numero);
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

int evaluarExpresion(struct Nodo* nodo_arbol, int* error,Pila *p){
    char expresion_nodo[50];
    strcpy(expresion_nodo,nodo_arbol->operacion);
    int i;
    char ch;
    int val;
    char A,B;

    for(i = 0; expresion_nodo[i] != '\0'; i++){
        ch = expresion_nodo[i];
        if(isdigit(ch)){
            apilar(p,error,ch - '0');
        }else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            A = desapilar(p,error);
            B = desapilar(p,error);

            switch (ch)
            {
            case '*':
                val = B * A;
                break;
            case '/':
                val = B / A;
                break;
            case '+':
                val = B + A;
                break;
            case '-':
                val = B - A;
                break;
            }
            apilar(p,error,val);
        }
    }
    printf("\n Resultado de la expresion: %s",desapilar(p,error));
}

void inicioOperacion(int argc, char** argv){
    srand(time(NULL));
    int error = 0;
    int cantidad_nodos; 
    struct Nodo* raiz = NULL;
    printf("\nIngresa la cantidad de nodos: ");
    scanf("%d",&cantidad_nodos);
    for(int i=0; i<cantidad_nodos;i++){
        leer(&raiz,&error);
    }
    inOrden(raiz);
    
//
    //
    //insertarElemento(&raiz,&error,7,-1);
    //insertarElemento(&raiz,&error,15,-1);
    //insertarElemento(&raiz,&error,20,-1);
    //insertarElemento(&raiz,&error,3,-1);
    //insertarElemento(&raiz,&error,15,-1);
    //insertarElemento(&raiz,&error,1,-1);
    //insertarElemento(&raiz,&error,9,-1);
    //insertarElemento(&raiz,&error,10,-1);
    //insertarElemento(&raiz,&error,1,-1);
    //insertarElemento(&raiz,&error,13,-1);
    //insertarElemento(&raiz,&error,24,-1);
    //insertarElemento(&raiz,&error,0,-1);
    //insertarElemento(&raiz,&error,-3,-1);
//
    //printf("\nRecorrido Pre-orden: ");
    //preOrden(raiz);
//
    //printf("\nRecorrido In-orden: ");
    //inOrden(raiz);
//
    //printf("\nRecorrido Pos-orden: ");
    //posOrden(raiz);
//
    //printf("\n\nEliminando elemento");
    //printf("\nRecorrido In-orden: ");
    //inOrden(raiz);
//
    //eliminarElemento(&raiz,&error,15);
    
}