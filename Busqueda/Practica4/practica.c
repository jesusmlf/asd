#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  char PaisOrigen[50];
  char Nombre[50];
  double Alto;
  char Telefono;
} Datos;

typedef struct {
    Datos datos;
}Persona;

int contador = 0;
int main(){
    FILE* archivo = fopen("Data/BD_Personas.csv","r");
    if (archivo == NULL){
        perror("No se pudo abrir el archivo");
        exit(1);
    }
    //Persona* personas23 = (Persona*) malloc(Persona);

    Persona personas[130];
    int read = 0;
    int records = 0;
    char NombreColumnas[100];
    fscanf(archivo,"%99[^\n]",NombreColumnas);
    fflush(stdin);
    do{
        fflush(stdin);
        read = fscanf(archivo,"%49[^,],%49[^,],%lf,%d\n",personas[records].datos.PaisOrigen, personas[records].datos.Nombre, &personas[records].datos.Alto, &personas[records].datos.Telefono);fflush(stdin);printf("%s,%s,%lf,%d\n",personas[records].datos.PaisOrigen, personas[records].datos.Nombre, personas[records].datos.Alto, personas[records].datos.Telefono);  

        if (read == 4) records++;
        if (read != 4 && !feof(archivo)){
            perror("Ero¿rrrrr");
        }

        if (ferror(archivo)){
        printf("Error reading file.\n");
        return 1;
        }
        contador++;

    } while(!feof(archivo));
    fclose(archivo);

    printf("\n%d records read.\n\n", records);
    printf("%d",contador);
}
