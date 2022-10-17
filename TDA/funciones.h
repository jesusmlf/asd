# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# define TAM 50

# define TAM_ESTRELLAS 10
# define TAM_PLANETAS 10

typedef struct{
    char nombre[TAM];
    float masa;
    float radio;
}Planeta;

typedef struct{
    char nombre[TAM];
    int tiempoVida;
}Estrella;

typedef struct{
    char nombre[TAM];
    Estrella estrellas[TAM_ESTRELLAS];
    Planeta planetas[TAM_PLANETAS];
}Galaxia;

Galaxia* crearGalaxia(Estrella*, Planeta*, char*);
void destruirGalaxia(Galaxia*);
void agregarPlaneta(Galaxia*, Planeta, int);
void agregarEstrella(Galaxia*, Estrella, int);

void inicioOperacion(int, char**);
