#include "biblioteca.h"

char* generarNombreAleatorio(){
    char *lista_nombres[MAX_NOMBRE] ={"Pedro","Jose","Maria","Antonio","Marco","Jesus"};
    int random_idx = rand() % 6; //Genera un numero aleatorio entre [0,5]
    return lista_nombres[random_idx];
}

int generarEdadAleatoria(){
    int random_age = rand() % EDAD_MAX; //Generar un numero aleatorio entre [0,EDAD_MAX]
    return random_age;
}

Persona* generarPersona(char* nombre, int edad){
    Persona* persona = (Persona*) malloc(sizeof(Persona));
    strcpy(persona->Nombre,nombre);
    persona->Edad = edad;
    return persona;
}

void imprimirPersona(Persona persona){
    printf("Nombre: %s -- Edad: %d\n",persona.Nombre,persona.Edad);
}

void OrdenarPorEdad(Persona** personas){
    //Selection sort
    int i,j;
    Persona* aux;
    for (i=0; i<MAX_PERSONAS-1; i++){
        for(j=i+1; j<MAX_PERSONAS; j++){
            if(personas[i]->Edad > personas[j]->Edad){
                aux = personas[i];
                personas[i] = personas[j];
                personas[j] = aux;
            }
        }
    }
}

void OrdenarPorNombre(Persona** personas){
    int i,j;
    Persona* aux;
    
    for(i=0; i<MAX_PERSONAS; i++){
        for(j=i+1; j<MAX_PERSONAS; j++){
            if(strcmp(personas[i]->Nombre,personas[j]->Nombre)>0){ //Si el nombre en i es mayor que nombre en j
                aux = personas[i];
                personas[i] = personas[j];
                personas[j] = aux;
            }
        }
    }
}
void inicioOperacion(int argc, char** argv){
    srand(time(NULL));
    Persona** personas = (Persona**) malloc(sizeof(Persona*)*MAX_PERSONAS);
    
    for(int i=0; i<MAX_PERSONAS; i++){
        int edad = generarEdadAleatoria();
        char* nombre = generarNombreAleatorio();
        personas[i] = generarPersona(nombre,edad);
    }

    OrdenarPorNombre(personas);

    printf("------------DATOS ORDENADOS POR NOMBRE------------\n");
    
    for(int i=0; i<MAX_PERSONAS; i++){
        imprimirPersona(*personas[i]);
    }
    OrdenarPorEdad(personas);

    printf("------------DATOS ORDENADOS POR EDAD------------\n");
    
    for(int i=0; i<MAX_PERSONAS; i++){
        imprimirPersona(*personas[i]);
    }
}
