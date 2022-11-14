#include "biblioteca.h" //Biblioteca no compilada o biblioteca de usuario.

void imprimeArreglo(int* arreglo,int pos){
    if(pos < TAM){
        printf("Pos %d=%d\n", pos, arreglo[pos]);
        imprimeArreglo(arreglo,++pos); //Operaciones prefijo y posfijo
        //Primero llama a la funcion.
        //++p Primero hace la operacion y luego hace la llama a la funcion.
    }
}

void inicioOperacion(int argc, char** argv){
    int arreglo[TAM] = {0};
    FILE* archivo = fopen("./datos.txt","r");
    if(archivo == NULL){
        puts("No se pudo encontrar el archibo datos.txt");
        exit(1);
    }
    for(int i=0; i<TAM ;i++){
        fflush(stdin);
        fscanf(archivo,"%d[^\n]",&arreglo[i]);
    }
    
    imprimeArreglo(arreglo,0);
}

//gcc biblioteca.h biblioteca.c test.c -O2
//Orden de operacion 2

//Tipos de recursividad: 
//Lineal final
//Lineal no final
//Multiple
//Mutuo