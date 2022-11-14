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
    //malloc -> Memory local (Reserva la memoria con datos basura)
    //calloc -> Memoria inicializada en 0 (Elimina la basura de la memoria)
    //realloc -> Reajustar la memoria para aumentarla o reducirla.


    int tamFilas = 0;
    puts("Dame la cantidad de registros que se guardaran: ");
    fflush(stdin); //Siempre usar antes de cualquier scanf.
    scanf("%d",&tamFilas);

    char** tablaNombres;
    char** tablaEdades;

    tablaNombres = (char **) calloc(tamFilas, sizeof(char*));
    tablaEdades = (char **) calloc(tamFilas, sizeof(char*));

    //Cada vez que llamemos a calloc haremos
    if (tablaEdades == NULL || tablaNombres == NULL){
        perror("No hay memoria suficiente para guardar los datos");
        exit(1); //Cierra todos los flujos que hicieron "algo"
    }
    for(int t = 0; t<tamFilas; t++){
        tablaNombres[t] = (char *) calloc(50,sizeof(char));
        tablaEdades[t] = (char *) calloc(3,sizeof(char));
        
        if (tablaEdades == NULL || tablaNombres == NULL){
            perror("No hay memoria suficiente para guardar los datos");
            exit(1); //Cierra todos los flujos que hicieron "algo"
        }
    }
    for(int i = 0; i<tamFilas; i++){
        puts ("Dame el nombre: ");
        fflush(stdin);
        gets(tablaNombres[i]); //Maneja cadenas
        tablaNombres[i] = realloc(tablaNombres[i],strlen(tablaNombres[i])* sizeof(char));
        if (tablaNombres[i] == NULL){
            perror("No hay memoria suficiente para realloc");
        }
        puts ("Dame la edad: ");
        fflush(stdin);
        gets(tablaEdades[i]);
        tablaEdades[i] = realloc(tablaEdades[i],strlen(tablaEdades[i])* sizeof(char));
        if (tablaEdades[i] == NULL){
            perror("No hay memoria suficiente para realloc");
        }
    }
    for (int i = 0; i<tamFilas ; i++){
        free(tablaNombres[i]);
        free(tablaEdades[i]);

    }
    free(tablaNombres);
    free(tablaEdades);
}
