#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

void imprimeTitulos(char titulos[33][100]){
    for(int i=0; i<33; i++){
        printf("El titulo en la pos=%d es %s",i,titulos[i]);
    }
}

void main(){
    FILE *titulosLibros=fopen("C:\\Users\\gusta\\Desktop\\BD_Libros.txt","r");
    FILE *indices=fopen("G:\\Programas_ESCOM\\workspace_Gustavo_G3\\Algoritmos y Estructuras de datos\\2AM1\\archivoIndices.txt","r");
    char arrayTitulos[33][100];
    char libroUsuario[100]={0};
    char linea[100];
    int arregloIndices[255]={0}; 
    int indice=0;
    int j=0;
    int valor=0;
    int caracter=0;
    int limiteInfBusq;
    int limiteSupBusq;
    bool flag=false;
    if(indices==NULL || titulosLibros==NULL){
        perror("Hubo un error al leer alguno de los archivos");
        exit(1);
    }

    while(!feof(titulosLibros)){
        printf("Estado del indice=%d",indice);
        fgets(linea,100,titulosLibros);
        printf("Linea leida: %s",linea);
        //Eliminar salto de linea:
        puts("Eliminando salto de linea");
        char *pos=strchr(linea,'\n');
        if(pos!=NULL)
            *pos=0;
        printf("Linea leida: %s",linea);
        strcpy(arrayTitulos[indice],linea);
        indice++;
    }
    //imprimeTitulos(arrayTitulos);
    puts("transfiriendo indices");
    while(!feof(indices)){
        fscanf(indices,"%c,%d",&caracter,&valor);
        arregloIndices[(int)caracter]=valor;
    }
    puts("Dame un titulo a buscar");
    fflush(stdin);
    scanf("%s",libroUsuario);

    //Procedimiento para reducir la busqueda a través de iun índice
    limiteInfBusq=arregloIndices[(int)libroUsuario[0]];
    if(limiteInfBusq>0){
        for(j=(int)(libroUsuario[0]+1);j<255;j++){
            if(arregloIndices[j]>0){
                flag=true;
                break;
            }
        }
        if(flag)
            limiteSupBusq=arregloIndices[j];
        else{
            //El limite superior estaria dado por el ultimo título
            limiteSupBusq=33;
        }

        //Utilizando los indices inf y sup para buscar el elemento n particular
        //en el archivo de libros (arreglo de titulos)

        for(int titulo=limiteInfBusq-1;titulo<(limiteSupBusq-1);titulo++){
            printf("Buscando libro %s\n",libroUsuario);
            if(strcmp(libroUsuario,arrayTitulos[titulo])==0){
                printf("El libro se encontro en la pos %d",titulo+1);
            } else{
                printf("----El libro no se ha encontro en pos %d\n\n", titulo);
            }
        }
    } else{
        puts("No se encontro el libro, indice en 0");
    }

   
}