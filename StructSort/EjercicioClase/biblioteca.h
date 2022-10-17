#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NOMBRE 30
#define EDAD_MAX 99
#define MAX_PERSONAS 100

typedef struct{
    char Nombre[MAX_NOMBRE];
    int Edad;
}Persona;

Persona* generarPersona();
char* generarNombreAleatorio();
int generarEdadAleatoria();
void imprimirPersona(Persona persona);
void OrdenarPorEdad(Persona** personas);
void OrdenarPorNombre(Persona** personas);
void inicioOperacion(int argc, char** argv);