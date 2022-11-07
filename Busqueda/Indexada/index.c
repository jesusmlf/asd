#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int busquedaBinaria(int arreglo[26][2], int tam, int dato){
    int inicio=0;
    int final=tam-1;
    int mitad=0;
    while (inicio<=final){
        mitad=(inicio+final)/2;
        if (arreglo[mitad][2]==dato){
            return mitad;
        } else if (arreglo[mitad][2]>dato){
            inicio=mitad+1;
        } else if (arreglo[mitad][2]<dato){
            final=mitad-1;
        }

    }
    return -1;
}

void main(int argc, char**argv){

    //Transferencia de datos de archivo a arreglo
    char arregloLibros[33][100];
    int arregloIndex[255]; // Capacidad de un char, ascii del char y se guarda en esa posicion el numero
    char buffer[100];
    char* pathIndices="archivoindex.txt";
    char* pathLibros="libros.txt";
    int posFilaLibros=0, valorInicialIndex;
    char asciiLetra;
    char cadenaUsuario[100];   
    int posInicialBusqueda;
    int posFInalBusqueda;

    FILE* archivoLibros=fopen(pathLibros,"r");
    FILE* archivoIndex=fopen(pathIndices,"r");

    if (archivoIndex==NULL || archivoLibros==NULL){
        perror("Archivos no disponibes");
        exit(1);
    }
    while(!feof(archivoLibros)){
        fgets(buffer,100,archivoLibros);
        strcpy(arregloLibros[posFilaLibros],buffer);
        posFilaLibros++;
    }
    while(!feof(archivoIndex)){
        fscanf(archivoIndex,"%d,%c",&valorInicialIndex,&asciiLetra);
        arregloIndex[(int)asciiLetra]=valorInicialIndex;
    }

    //Busqueda
    puts("Dame un titulo a buscar");
    scanf("%s",cadenaUsuario);
    posInicialBusqueda=arregloIndex[(int)cadenaUsuario[0]];    
    posFInalBusqueda=arregloIndex[((int)cadenaUsuario[0])];
    int aux=(int)cadenaUsuario[0];
    do{        
        aux++;
        posFInalBusqueda=arregloIndex[aux];
    }while(posFInalBusqueda==0&&aux<255);
    if(posFInalBusqueda){
        posFInalBusqueda=33; // tamaÃ±o final de libros
    }

    for(int i=posInicialBusqueda;posInicialBusqueda<posFInalBusqueda;i){
        
    }
}