#include "biblioteca.h"

void inicioOperacion(int argc, char** argv){
    
    FILE* archivo = fopen("./tabla.txt","w");
    if(archivo == NULL){
        exit(1);
    }
    int i = 0;
    while(i<255){
        fprintf(archivo,"\n%d - %x - %c",i,i,i+0);
        i++;
    }
    fclose(archivo);
}