#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

void main(){
    char arrayTitulos[33][100];
    char linea[100];
    int indice = 0;
    int arregloIndices[255] = {0};
    int valor = 0;
    char caracter;
    char libroUsuario[100] = {0};
    int limiteInfBusq;
    int limiteSupBusq;
    bool flag = false;
    int j = 0;

    FILE *titulosLibros = fopen("libros.txt","r");
    FILE *indices = fopen("archivoindex.txt","r");

    if(indices == NULL || titulosLibros == NULL){
        perror("Hubo un error al leer alguno de los archivos");
        exit(1);
    }

    while(!feof(titulosLibros)){
        fflush(stdin);
        fgets(linea,100,titulosLibros);

        char *pos = strchr(linea,'\n'); //Devolver un puntero a la posicion del caracter
        if(pos!=NULL){ //Devolver NULL
            *pos = 0;
        }
        strcpy(arrayTitulos[indice],linea);
        indice++;
    }

    while(!feof(indices)){
        fscanf(indices,"%d,%c",&valor,&caracter);
        arregloIndices[(int)caracter] = valor;
    }

    puts("Dame un titulo a buscar");
    fflush(stdin);
    gets(libroUsuario);
    //scanf("%[^\n]%*c",libroUsuario);

    limiteInfBusq = arregloIndices[(int)libroUsuario[0]];
    if(limiteInfBusq > 0){
        for(j=(int)(libroUsuario[0]+1) ; j<255;j++){
            if(arregloIndices[j]>0){
                flag = true;
                break;
            }
        }
        if(flag){
            limiteSupBusq = arregloIndices[j];
        }
        else{
            limiteSupBusq = 33;
        }

    printf("Buscando libro: %s\n",libroUsuario);
    for(int titulo = limiteInfBusq-1; titulo <= (limiteSupBusq-1);titulo++){
        if(strcmp(libroUsuario,arrayTitulos[titulo])== 0){
            printf("El libro se encontro en la pos %d",titulo+1);
            break;
            }
        }
    }
    else{
        puts("No se encontro el libro, indice en 0");
    }
}