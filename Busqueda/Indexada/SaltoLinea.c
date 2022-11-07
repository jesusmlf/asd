#include <stdio.h>
#include <string.h>
#include <string.h>

void main(){
    char nombresTitulos[33][100];
    char linea[100];
    FILE *titulos = fopen("libros.txt","r");

    while(!feof(titulos)){
        fgets(linea,100,titulos);
        printf("Linea leida: %s",linea);

        //Elimando salto de linea:
        //strchr Devuelve un puntero a la primera aparición del carácter en la cadena C str.
        char *pos = strchr(linea,'\n'); //Devuelve NULL -> Caracter no fue encontrado
                            //Devuele la posicion del caracter en caso contrario
        printf("%s",pos);
        if(pos != NULL){
            *pos = 0;
        }
        printf("Linea leida: %s",linea);
    }
    
    char letra = 'A';
    int ascii = (int) letra;
    printf("%d",ascii);
}