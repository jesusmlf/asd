# include "biblioteca.h"

void inicioOperacion(int argc, char** argv){
    int i = 0;
    FILE* archivo = fopen("tabla.txt","w+r");
    if(archivo == NULL){
        puts("No se encuentra el archivo 'tabla.txt'");
        exit(1);
    }

    while (i<=TOTAL){
        fprintf(archivo,"\n%d     -%x     -%c",i,i,i);
        i++;
    }
    fclose(archivo);
}

