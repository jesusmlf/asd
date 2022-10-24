#include <stdio.h>

void sort(int *arreglo, int tam);

void mezcla(int *arrIzq, int tamIzq, int *arrDer, int tamDer, int* arreglo);


void sort(int *arreglo, int tam){
    if(tam>1){
        int i,j,k;
        int mitad=tam/2;
        int arrIzq[mitad];
        int arrDer[tam-mitad];
        for(i=0, k=0; i<mitad; i++, k++){
            arrIzq[i]=arreglo[k];
        }
        for(j=0; j< (tam-mitad); j++, k++){
            arrDer[j]=arreglo[k];
        }
        sort(arrIzq,mitad);
        sort(arrDer,tam-mitad);
        mezcla(arrIzq,mitad, arrDer,tam-mitad,arreglo);
    }
}

void mezcla(int *arrIzq, int tamIzq, int *arrDer, int tamDer, int* arreglo){
    int i=0,j=0,k=0;
    while(i<tamIzq && j<tamDer){
        if(arrIzq[i]<arrDer[j]){
            arreglo[k]=arrIzq[i];
            i++;   
        } else{
            arreglo[k]=arrDer[j];
            j++;  
        }
        k++;
    }
    while(j<tamDer){
        arreglo[k]=arrDer[j];
        j++;
        k++;
    }
    while(i<tamIzq){
        arreglo[k]=arrIzq[i];
        i++;
        k++;
    }
}


void main(){
    puts("Inicio");
    int arreglo[4]={3,2,1,0};
    sort(arreglo,4);
    for (int i=0;i<4;i++){
        printf("%d ",arreglo[i]);
    }
    puts("\nFin");
}
