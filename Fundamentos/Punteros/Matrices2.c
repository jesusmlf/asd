# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(){
    int filas = 0;
    char **FilaNombre = NULL;
    char **FilaEdades = NULL;

    FilaNombre = (char**) calloc(filas,sizeof(char*));
    FilaEdades = (char**) calloc(filas,sizeof(char*));

    if(FilaNombre == NULL || FilaEdades == NULL){
        printf("No hay memoria suficiente");
        exit(1);
    }
    printf("Ingrese el numero de datos a ingresar: ");
    fflush(stdin);
    scanf("%d",&filas);
    
    for (int i=0;i<filas ;i++){
        FilaNombre[i] = (char *) calloc(50,sizeof(char));
        FilaEdades[i] = (char *) calloc(3,sizeof(char));
        if(FilaNombre == NULL || FilaEdades == NULL){
        perror("No hay memoria suficiente");
        exit(1);
    }
    }

    for(int i=0; i<filas; i++){
        printf("Ingrese el nombre: ");
        fflush(stdin); 
        scanf("%s",FilaNombre[i]);
        FilaNombre[i] = realloc(FilaNombre[i],strlen(FilaNombre[i])*sizeof(char));
        if(FilaNombre[i] == NULL){
            perror("No hay memoria suficiente para realloc");
            exit(1);
        }

        printf("Ingrese la edad: ");
        fflush(stdin);
        scanf("%s",FilaEdades[i]);
        FilaEdades[i] = realloc(FilaEdades[i],strlen(FilaEdades[i])*sizeof(char));
        if(FilaEdades[i] == NULL){
            perror("No hay memoria suficiente para realloc");
            exit(1);
        }
    }
    for(int i=0 ; i<filas; i++){
        printf("\nNombre: %s - Edad: %s",FilaNombre[i],FilaEdades[i]);
    }
    for(int i=0 ; i<filas; i++){
        free(FilaEdades[i]);
        free(FilaNombre[i]);
    }
    
}