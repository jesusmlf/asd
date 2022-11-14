/*
Grupo: 2AM1

Intregrantes:
-Aguilar Hernández Rodrigo Javier
-López Fabián Jesús Manuel
-Rico Mendoza Josué
*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 100000
int GenerarNumero(int N, int M);
void LlenarArreglo(int *Arreglo);
void Imprimir(int *Arreglo, int tam);
void OrdenarSelection(int * Arreglo);
void ObtenerPare(int *Arreglo);
void OrdenaInsert(int *Arreglo);
void ObtenerImpares(int *Arreglo);

int main(int argc, char const *argv[])
{
    int Arreglo[TAM]={};
    LlenarArreglo(Arreglo);

    printf("Arreglo sin ordenar: \n");
    Imprimir(Arreglo, TAM);

    printf("Arreglo ordenado por numeros pares de menor a mayor: \n");
    OrdenarSelection(Arreglo);

    printf("Arreglo ordenado por numero impares de mayor a menor \n");
    OrdenaInsert(Arreglo);

    
    return 0;
}




int GenerarNumero(int N, int M){
    int numero =0;
    numero = rand () % (N-M+1) + M;   // Este está entre M y N
    return numero;
}

void LlenarArreglo(int *Arreglo){

    for(int i =0; i<TAM; i++){
        Arreglo[i] = GenerarNumero(459565, 0);
    }

}
void Imprimir(int *Arreglo, int tam){
    for (int i = 0; i < tam; i++)
    {
        printf("%d \n",Arreglo[i] );
    }
    
}

void OrdenarSelection(int * Arreglo){
    int aux;


    for (int i = 0; i < TAM-1; i++)
    {
        for (int j = i+1; j < TAM; j++)
        {
            if (Arreglo[i]>Arreglo[j])
            {
                aux = Arreglo[i];
                Arreglo[i]= Arreglo[j];
                Arreglo[j]= aux;
            }
            
        }
        
    }

    ObtenerPare(Arreglo);
}

void ObtenerPare(int *Arreglo){
    int cont=0;
    for (int i = 0; i < TAM; i++)
    {
        if (Arreglo[i]%2==0)
        {
            cont++;
        }
        
    }

    int *Arreglopares= (int*)calloc(cont,sizeof(int));

    for (int i = 0, k=0; i < TAM; i++)
    {
        if (Arreglo[i]%2==0)
        {
             Arreglopares[k]=Arreglo[i];
             k++;
        }
        
    }

    Imprimir(Arreglopares,cont);

}

void OrdenaInsert(int *Arreglo){
    int pivote, i , j;
    for ( i = 0; i < TAM; i++)
    {
        pivote = Arreglo[i];

        j =i-1;
        while (j>=0 && pivote>Arreglo[j])
        {
            Arreglo[j+1] = Arreglo[j];
            j--;
        }

        Arreglo[j+1]=pivote;
        
    }

    ObtenerImpares(Arreglo);
    
}

void ObtenerImpares(int *Arreglo){

    int cont=0;
    for (int i = 0; i < TAM; i++)
    {
        if (Arreglo[i]%2!=0)
        {
            cont++;
        }
        
    }

    int *ArregloImpares= (int*)calloc(cont,sizeof(int));

    for (int i = 0, k=0; i < TAM; i++)
    {
        if (Arreglo[i]%2!=0)
        {
             ArregloImpares[k]=Arreglo[i];
             k++;
        }
        
    }

    Imprimir(ArregloImpares,cont);

}