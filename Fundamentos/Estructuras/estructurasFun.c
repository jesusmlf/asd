/* Problema: Capturar en una estructura  Persona, los siguientes datos:
     Edad, Nombre, Peso

     Se deben crear dos funcines, una de ellas para crear la estructura
     y otra para modificar el atributo Nombre.

*/

# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdalign.h>
# include <string.h>
# include <stdio.h>
typedef struct 
{
    int8_t edad; //Entero de 8 bits
    char nombre[100];
    float peso;

} Persona;

Persona* crearPersona(int8_t, char*,float);
void modificarNombrePersona(Persona*,char*);

void main(){
    puts("Iniciando programa: ");
    Persona* persona1 = crearPersona(20,"Jesus",65);
    printf("Edad: %d - Nombre: %s - Peso: %f",persona1->edad,persona1->nombre,persona1->peso);
    modificarNombrePersona(persona1,"Josue");
    printf("\nEdad: %d - Nombre: %s - Peso: %f",persona1->edad,persona1->nombre,persona1->peso);

    free(persona1); //Libera memoria.
}

Persona* crearPersona(int8_t edad, char* name,float peso){
    Persona* juanito = (Persona*) malloc(sizeof(Persona));
    if(juanito == NULL){
    perror("No hay memoria para la persona ");
    exit(1);
    }
    juanito -> edad = edad; //Asignamos un valor a las instancias de la estructura (atributos).
    (*juanito).peso = peso;
    strcpy(juanito -> nombre,name);
    return juanito;
}
void modificarNombrePersona(Persona* persona, char* new_name){
    strcpy(persona->nombre,new_name);
}