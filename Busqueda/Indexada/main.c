#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

void main(){
    int indice=0;
    char linea[100];
    char arrayTitulos[33][100]; //33 libros y 100 palabras por titulo
    int arregloIndices[255] = {0};
    char caracter;
    int valor = 0;
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

    //Transferir los titulos de libros
    while(!feof(titulosLibros)){
        fgets(linea,100,titulosLibros);
        //Eliminar salto de linea:
        char *pos=strchr(linea,'\n');
        if(pos!=NULL){
            *pos=0;
        }
        strcpy(arrayTitulos[indice],linea);
        indice++;
    }

    //Transferir los indices
    while(!feof(indices)){  
        fscanf(indices,"%d,%c",&valor,&caracter);
        arregloIndices[(int)caracter] = valor;
    }
    puts("Dame un titulo a buscar");
    fflush(stdin);
    scanf("%s",libroUsuario);

    //Procedimiento para reducir la busqueda a traves de un indice.
    limiteInfBusq = arregloIndices[(int)libroUsuario[0]];
    if(limiteInfBusq > 0){
        for(j = (int)(libroUsuario[0]+1);j<255;j++){
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
    
        for(int titulo = limiteInfBusq-1; titulo<(limiteSupBusq-1);titulo++){
            printf("%d",titulo);
            printf("Buscando libro %s\n",libroUsuario);
            if(strcmp(libroUsuario,arrayTitulos[titulo]) == 0){
                printf("El libro se encontro en la pos %d",titulo+1);
            }
            else{
                printf("----El libro no se ha encontrado en pos %d\n\n",titulo);
            }
        }
    }
    else{
        puts("No se encontro el libro, indice en 0");
    }
}
