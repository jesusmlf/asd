#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TELEFONO

typedef struct {
  char PaisOrigen[50];
  char Nombre[50];
  double Alto;
  char Telefono[50];
} Datos;

typedef struct {
    Datos datos;
}Persona;

Persona* crearPersona(Datos datos);
void imprimirPersonas(Persona** personas,int tam);

void OrdenarAltura(Persona** personas, int tam);

void OrdenarNombre(Persona** personas, int tam);
void mezclaPorEdad(Persona** arrIzq, int tamIzq, Persona** arrDer, int tamDer, Persona** arreglo);

void OrdenarTelefono(Persona personas, int tam);
void OrdenarPais(Persona personas, int tam);

Persona* buscarTelefono(Persona** personas,int tam,char* telefono);
void inicioOperacion(int, char**);