#include "biblioteca.h"

Persona* crearPersona(Datos datos){
    Persona* persona = (Persona*) malloc(sizeof(Persona));
    if(persona == NULL){
        perror("No hay memoria suficiente para crear persona");
    }else{
        for(int i=0; i<MAX_PERSONAS;i++){
            strcpy(persona->datos.pais,datos.pais);
            strcpy(persona->datos.nomre,datos.nomre);
            persona->datos.altura = datos.altura;
            strcpy(persona->datos.telefono,datos.telefono);
        }
    }
}
void inicioOperacion(int argc,char** argv){
    char buf[BUFFER_SIZE];
    char paisOrigen[MAX_PAIS] = {0};
    char nombre[MAX_NOMBRE] = {0};
    int altura = 0;
    char telefono[MAX_TELEFONO] = {0};
    char* tok = strtok(buf,"");

    FILE* archivo = fopen("BD_Personas.csv","r");
    if(archivo == NULL){
        puts("Error al ller el archivo");
        exit(1);
    }
    getline(archivo,buf);
}