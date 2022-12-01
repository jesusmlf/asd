#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Dato;

struct Nodo
{
    struct Nodo* siguiente;
    int pos;
    Dato dato;
};

typedef struct Nodo* cabecera;
void InsertarporIzq(cabecera *l, int *error,Dato datou);
struct Nodo * CrearrNodo(cabecera *l, int *error, Dato datou);

int main(int argc, char const *argv[])
{
    cabecera *l ;
    int error =0;

    InsertarporIzq(l,&error,5);
    InsertarporIzq(l,&error,6);
    InsertarporIzq(l,&error,7);


    printf("el numero %d esta en pos : %d\n",(*l)->dato,(*l)->pos);
    printf("el numero %d esta en pos : %d\n",(*l)->siguiente->dato,(*l)->siguiente->pos);
    printf("el numero %d esta en pos : %d\n",(*l)->siguiente->siguiente->dato,(*l)->siguiente->siguiente->pos);

    

    return 0;
}

struct Nodo * CrearrNodo(cabecera *l, int *error, Dato datou){

    struct  Nodo* new = (struct Nodo*)malloc(sizeof(struct Nodo));

    if (new == NULL)
    {
        perror("no se pudo crear el nodo\n");
    }
    else{
        new->dato=datou;
        new->siguiente=NULL;
    }
    return new;
}

void InsertarporIzq(cabecera *l, int *error,Dato datou){
    struct Nodo* porinsert = CrearrNodo(l,error,datou);
    if (*l == NULL)
    {
        printf("l esta vacia \n");
        porinsert->pos=0;
        *l = porinsert;
    }
    else{
        porinsert->siguiente=*l;
        porinsert->pos=0;
        *l=porinsert;
        
        for (struct Nodo* actual = (*l)->siguiente; actual!=NULL; actual=actual->siguiente)
        {
            actual->pos=(actual->pos)+1;
        }
    }
}