#include "biblioteca.h"

FILE* LeerArchivo(char* ruta){
    
    FILE* archivo = (FILE*) malloc(sizeof(FILE));
    archivo = fopen("./input.txt","r");
    if (archivo == NULL){
        perror("No hay memoria para el archivo");
        exit(1);
    }

    
    return archivo;
}

int* GenerarArreglo(FILE* archivo){
    int* arr = (int*) malloc(sizeof(int) * NUMS);
    for(int i=0; i<NUMS; i++){
        fflush(stdin);
        fscanf(archivo,"%d[^\n]",&arr[i]);
    }
    //arr = realloc(arr,sizeof(arr) / sizeof(arr[0]));

    return arr;
}

void InsertionSort(int* arr,int n){
    int i,j,aux;

    for(i=1; i<n ;i++){
        aux = arr[i];
        j = i - 1;
        while(j>=0 && arr[j] > aux){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = aux;
    }
}

void ImprimirDatos(int* arr, int n){
    for(int i=0 ;i<n; i++){
        printf("%d ",arr[i]);
    }
}

void InicioOperacion(int argc, char** argv){
    char ruta[100] = "./input.txt";
    FILE* archivo = LeerArchivo(ruta);
    int* arreglo = GenerarArreglo(archivo);
    int n = 13;
    InsertionSort(arreglo,n);
    ImprimirDatos(arreglo,n);
    fclose(archivo);
    free(arreglo);
}