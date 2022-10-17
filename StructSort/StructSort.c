#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int valor;
    char caracter;
}Dato;

void imprimirDatos(Dato* datos, int cantidad);
void ordenarDatos(Dato* datos, int cantidad);

int main(int argc, char** argv){
    Dato datos[] = {{5,'a'},{6,'c'},{9,'z'},{-2,'a'},{4,'g'}};
    int n = sizeof(datos) / sizeof(Dato);
    imprimirDatos(datos,n);
    printf("--------------------------\n");
    ordenarDatos(datos,n);
    imprimirDatos(datos,n);
}

void imprimirDatos(Dato* datos, int cantidad){
    for(int i=0; i<cantidad; i++){
        printf("Valor: %d -- Caracter: %c \n",datos[i].valor,datos[i].caracter);
    }
}

void ordenarDatos(Dato* datos, int cantidad){
    //Ordenamiento por seleccion.
    Dato aux;
    int i,j;

    for(i=0;i<cantidad-1;i++){
        for(j=i+1;j<cantidad;j++){
            if(datos[i].valor > datos[j].valor){
                aux = datos[i];
                datos[i] = datos[j];
                datos[j] = aux;
            }
        }
    }
}

