#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TDA
typedef struct {
  char PaisOrigen[50];
  char Nombre[50];
  double Alto;
  int Telefono;
} Datos;

typedef struct {
    Datos datos;
}Persona;


//Prototipos
void OrdenamientoAltura(Persona*,int);
void imprimir(Persona*, int);
void OrdenamientoSegundaLetra(Persona*,int, int);
void merge(Persona*, int l, int m, int r);
void OrdenamientoTelefono(Persona*,int);
void OrdenamientoPais(Persona*,int);
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}



int main(){
    // Archivo
    printf("aaaaaaa");

    FILE *file;
    
    file = fopen("C:\\Users\\saulg\\Downloads\\BD_Personas.xlsx - Hoja1.csv", "r"); 
    
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    
    Persona personas[100];
    
    int read = 0;
    int records = 0;
            char NombreColumnas[100];
            fscanf(file,"%99[^\n]",NombreColumnas);
    do 
    {

        read = fscanf(file,
                    "%49[^,],%49[^,],%lf,%d\n",
                    personas[records].datos.PaisOrigen, 
                    personas[records].datos.Nombre, 
                    &personas[records].datos.Alto, 
                    &personas[records].datos.Telefono);
                    fflush(stdin);
                    printf("%s,%s,%lf,%d\n",
                    personas[records].datos.PaisOrigen, 
                    personas[records].datos.Nombre, 
                    personas[records].datos.Alto, 
                    personas[records].datos.Telefono);  

        if (read == 4) records++;


        if (read != 4 && !feof(file))
        {
            perror("Ero¿rrrrr");
        }

        if (ferror(file))
        {
        printf("Error reading file.\n");
        return 1;
        }

    } while (!feof(file));


    fclose(file);

    printf("\n%d records read.\n\n", records);

    
}


void imrpimir(Persona* personas,int records){
    for(int i = 0; i<=records; i++)
    printf("%s,%s,%lf,%d\n",
                    personas[i].datos.PaisOrigen, 
                    personas[i].datos.Nombre, 
                    personas[i].datos.Alto, 
                    personas[i].datos.Telefono);  
}

void OrdenamientoAltura(Persona* personas, int records){

    //selection sort
    {
    int i, j, min_idx;
 
    for (i = 0; i < records-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < records; j++)
          if (personas[j].datos.Alto < personas[min_idx].datos.Alto)
            min_idx = j;
 
           if(min_idx != i)
            swap(&personas[min_idx], &personas[i]);
    }
}
}


void OrdenamientoSegundaLetra(Persona* personas,int left, int right){

    //merge sort
    if (left < right)
    {

    int m = left+(right-left)/2;

    OrdenamientoSegundaLetra(personas, left, m);
    OrdenamientoSegundaLetra(personas, m+1, right);
 
    merge(personas, left, m, right);
}
}




void OrdenamientoTelefono(Persona* personas,int records){

  for (int step = 0; step < records - 1; ++step) {
      
    for (int i = 0; i < records - step - 1; ++i) {
      
      if (personas[i].datos.Telefono > personas[i + 1].datos.Telefono) {
        
        Persona temp = personas[i];
        personas[i] = personas[i + 1];
        personas[i + 1] = temp;
      }
    }
  }
}


//void OrdenamientoPais(Persona* personas,int records){

    //insertion sort
//}


