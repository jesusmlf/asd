#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 30
#define MAX_TELEFONO 15
#define MAX_PAIS 15

typedef struct{
    int altura;
    char nomre[MAX_NOMBRE];
    char telefono[MAX_TELEFONO];
    char pais[MAX_PAIS];
}Datos;

typedef struct{
    Datos datos;
}Persona;

Persona* crearPersona(Datos datos);
void inicioOperacion(int, char**);