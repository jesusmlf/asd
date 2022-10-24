#include <stdio.h>
#include <string.h>
#define MAX_NOMBRE 30

typedef struct{
    int edad;
    char nombre[MAX_NOMBRE];
}Persona;

void sortPorEdad(Persona *arreglo, int tam);
void mezclaPorEdad(Persona *arrIzq, int tamIzq, Persona *arrDer, int tamDer, Persona* arreglo);

void sortPorNombre(Persona *arreglo, int tam);
void mezclaPorNombre(Persona *arrIzq, int tamIzq, Persona *arrDer, int tamDer, Persona* arreglo);

void imprimirStruct(Persona *personas, int tam);


void sortPorNombre(Persona *arreglo, int tam){
    if(tam>1){
        int i,j,k;
        int mitad=tam/2;
        Persona arrIzq[mitad];
        Persona arrDer[tam-mitad];
        for(i=0, k=0; i<mitad; i++, k++){
            arrIzq[i]=arreglo[k];
        }
        for(j=0; j< (tam-mitad); j++, k++){
            arrDer[j]=arreglo[k];
        }
        sortPorNombre(arrIzq,mitad);
        sortPorNombre(arrDer,tam-mitad);
        mezclaPorNombre(arrIzq,mitad, arrDer,tam-mitad,arreglo);
    }
}

void mezclaPorNombre(Persona *arrIzq, int tamIzq, Persona *arrDer, int tamDer, Persona* arreglo){
    int i=0,j=0,k=0;
    while(i<tamIzq && j<tamDer){
        if(strcmp(arrIzq[i].nombre,arrDer[j].nombre)<0){
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
void sortPorEdad(Persona *arreglo, int tam){
    if(tam>1){
        int i,j,k;
        int mitad=tam/2;
        Persona arrIzq[mitad];
        Persona arrDer[tam-mitad];
        for(i=0, k=0; i<mitad; i++, k++){
            arrIzq[i]=arreglo[k];
        }
        for(j=0; j< (tam-mitad); j++, k++){
            arrDer[j]=arreglo[k];
        }
        sortPorEdad(arrIzq,mitad);
        sortPorEdad(arrDer,tam-mitad);
        mezclaPorEdad(arrIzq,mitad, arrDer,tam-mitad,arreglo);
    }
}

void mezclaPorEdad(Persona *arrIzq, int tamIzq, Persona *arrDer, int tamDer, Persona* arreglo){
    int i=0,j=0,k=0;
    while(i<tamIzq && j<tamDer){
        if(arrIzq[i].edad<arrDer[j].edad){
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

void imprimirStruct(Persona *personas, int tam){
    for(int i=0; i<tam; i++){
        printf("Edad: %d  --  Nombre: %s\n",personas[i].edad,personas[i].nombre);
    }
}

void main(){
    puts("Inicio");
    Persona personas[7] = {{4,"alejandro"},{5,"alejandra"},{6,"pika"},{7,"gotenPi"},{14,"josh"},{4,"jesu"},{15,"li"}};
    
    printf("------------Arreglo ordenado por edades------------");
    printf("\n");
    sortPorEdad(personas,7);
    imprimirStruct(personas,7);

    printf("\n");
    printf("------------Arreglo ordenado por nombres------------");
    printf("\n");
    sortPorNombre(personas,7);
    imprimirStruct(personas,7);
    puts("\nFin");
}
