#include <stdio.h>
#include <stdlib.h>

void insertionSort(int* arr, int n){
    int i,j,aux;
    
    for(i=1 ; i<n ; i++){
        aux = arr[i];
        j = i - 1;
        while(j>=0 && arr[j] > aux){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = aux;
    }
}

int main(){
    char ca;
    int cont = 1,i = 0;
    FILE* archivo = fopen("Ejercico1/input.txt","r");
    if(archivo == NULL){
        puts("No se pudo encontrar el archivo");
        exit(1);
    }
   while((ca == fgetc(archivo)) != EOF){
        if(ca == '\n'){
            cont++;
            
        }
   }
    int arr[cont];
    
    for(int i=0; i<cont; i++){
        fflush(stdin);
        fscanf(archivo,"%d[^\n]",&arr[i]);
        printf("%d\n",arr[i]);
    }
}