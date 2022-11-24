#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// hola gsu :^)c buenos dias :3 animo :33 !! hiiii !! haii!! hii:333 yippe!!! 

int main(){
    int semilla = 13;
    int numero;
    int numero2;
    for(int i=0;i<80;i++){

        //numero = (int)(pow(2,2) * ((pow(semilla,7)) + (pow(semilla,2)) +1))%19;
        //numero = (int)(pow(2,2)* pow(semilla,5) +1 ) % 13;
        //numero = (4 * (semilla+1)) % 100;
        //numero = (1091 * (semilla)) % 19;
        numero = (int)(1091 * pow(semilla,5) + 17 ) % 19;
        //numero = (203 * (semilla)) % 1000; Genera 100 numeros aleatorios entre 0-1000
        printf("%d\n",numero);

        //printf("Semilla: %d",semilla);
        semilla = numero;
    }
}