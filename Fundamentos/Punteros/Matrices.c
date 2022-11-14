/* Problema: El usuario recopilará los siguientes datos tabulares y el programa
los mostrara como un sistema de registros: 

Nombre(char)      Edad(char)
    (X)               (Y)
    ... (cantidad de registros de acuerdo al usuario)       
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
    int tamFilas = 0;
    puts("Dame la cantidad de registros que se guardaran: ");
    fflush(stdin); //Siempre usar antes de cualquier scanf.
    scanf("%d",&tamFilas);

    char tablaNombres[10][50] = {0}; //[filas][] //No podemos mandar a un corchete una variable
    //Igualamos a 0 para almacenar el fin de cadena en la tabla.
    char tablaEdades[10][3] = {0};
    for (int i = 0; i<tamFilas; i++){
        
        puts ("Dame el nombre: ");
        fflush(stdin);
        gets(tablaNombres[i]); //Maneja cadenas
        
        
        puts ("Dame la edad: ");
        fflush(stdin);
        gets(tablaEdades[i]);

    }
    for (int j = 0; j<tamFilas;j++){
        printf("Nombre: %s - Edad: %s \n",tablaNombres[j],tablaEdades[j]);
    }
}