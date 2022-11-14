/*
* Alumno: López Fabián Jesús Manuel
* Grupo: 2AM1
* Licenciatura en Ciencia de Datos
* Fecha ultima modificación: 5/09/2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_ALUMNOS 2
#define TAM_SALONES 2
#define NOMBRE_ALUMNO 50
#define NOMBRE_ESCUELA 50

typedef struct{
    char nombre[NOMBRE_ALUMNO];
    int edad;
    float altura;
}Alumno;

typedef struct{
    int numeroPiso;
    int largo;
    int ancho;
}Salon;

typedef struct{
    Alumno alumnos[TAM_ALUMNOS];
    Salon salones[TAM_SALONES];
    char nombre[NOMBRE_ESCUELA];
}Escuela;

Escuela* crearEscuela(Alumno*, Salon*, char*);
void destruirEscuela(Escuela*);
void imprimirEscuela(Escuela);
void copiarEscuela(Escuela*, Escuela*);
void inicioOperacion(int, char**);