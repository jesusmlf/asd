#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool ExisteDato(int* arr,int dato, int tam);
int posDato(int* arr,int dato, int tam);

int main(){
    int arr[] = {3,1,2,4,5,1,2,4,5,7,8,5,1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int dato;

    printf("Ingrese el dato a buscar: ");
    fflush(stdin);
    scanf("%d",&dato);
    
    printf("El dato esta en la posición: %d",posDato(arr,dato,n));
    if(ExisteDato(arr,dato,n) == true){
        printf("\nEl %d existe en el arreglo",dato);
    }
    else{
        printf("\nEl %d NO existe en el arreglo",dato);
    }

}

bool ExisteDato(int* arr, int dato,int tam){
    bool flag = false;

    for(int i=0; i<tam; i++){
        if (dato == arr[i]){
            flag = true;
            break;
        }
        else{
            flag = false;
        }
    }
    return flag;
}
int posDato(int* arr,int dato, int tam){
    int pos = 0;

    for(int i=0; i<tam; i++){
        if (dato == arr[i]){
            return i;
        }
    }
    return -1;
}