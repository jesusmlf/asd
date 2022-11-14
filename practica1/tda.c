/*
* Alumno: López Fabián Jesús Manuel
* Grupo: 2AM1
* Licenciatura en Ciencia de Datos
* Fecha ultima modificación: 5/09/2022
*/
#include "tda.h"

Escuela* crearEscuela(Alumno* alumnos, Salon* salones, char* nombre){
    Escuela* escuela = (Escuela*) malloc(sizeof(Escuela));
    if (escuela == NULL){
        perror("No hay memoria suficiente para la escuela");
    } else{
        for(int i=0; i<TAM_ALUMNOS; i++){
            escuela->alumnos[i] = alumnos[i];
        }
        for(int j=0; j<TAM_SALONES ;j++){
            escuela->salones[j] = salones[j];
        }

        strcpy(escuela->nombre, nombre);
    }
    return escuela;
}

void destruirEscuela(Escuela* escuela){
    free(escuela);
}
 void imprimirEscuela(Escuela escuela){
    printf("\nNombre de la escuela: %s\n",escuela.nombre);
    for(int i=0; i<TAM_SALONES ; i++){
        printf("\nPiso salon : %d - Ancho: %d - Largo: %d\n",escuela.salones[i].numeroPiso,escuela.salones[i].ancho,escuela.salones[i].largo);
    }
    for(int j=0; j<TAM_ALUMNOS ;j++){
        printf("\nAlumno: %s - Altura: %f - Edad: %d\n",escuela.alumnos[j].nombre,escuela.alumnos[j].altura,escuela.alumnos[j].edad);
    }
 }

void copiarEscuela(Escuela* escuelaOriginal, Escuela* escuelaCopia){
    for(int i=0 ; i<TAM_ALUMNOS ; i++){
        escuelaCopia->alumnos[i] = escuelaOriginal->alumnos[i];
    }
    for(int j=0 ; j<TAM_SALONES ; j++){
        escuelaCopia->salones[j] = escuelaOriginal->salones[j];
    }
    strcpy(escuelaCopia->nombre,escuelaOriginal->nombre);
}

void inicioOperacion(int argc, char** argv){
    Alumno* alumnos = (Alumno*) malloc(sizeof(Alumno)*TAM_ALUMNOS);
    Salon* salones = (Salon*) malloc(sizeof(Salon)*TAM_SALONES);
    Escuela *escuela;
    Escuela *escuelaCopia = (Escuela*) malloc(sizeof(Escuela));
    int opcionUsuario=0;

    puts("Programa para gestionar una Escuela");
    do{
        puts("\nSeleccione una opción:");
        puts(" 0.- Salir del programa");
        puts(" 1.- Crear escuela");
        puts(" 2.- Imprimir escuela");
        puts(" 3.- Destruir escuela");
        puts(" 4.- Copiar escuela");
        fflush(stdin);
        scanf("%d", &opcionUsuario);
        switch (opcionUsuario)
        {
            case 1:
                //Crear escuela
                for(int i=0; i<TAM_ALUMNOS; i++){
                    char nombre[NOMBRE_ALUMNO];
                    int edad;
                    float altura;

                    printf("\nIngrese el nombre del alumno %d: ",i+1);
                    fflush(stdin);
                    scanf("%s",nombre);
                    printf("Ingrese la edad del alumno %d: ",i+1);
                    fflush(stdin);
                    scanf("%d",&edad);
                    printf("Ingrese la altura del alumno %d: ",i+1);
                    fflush(stdin);
                    scanf("%f",&altura);

                    strcpy(alumnos[i].nombre,nombre);
                    alumnos[i].edad = edad;
                    alumnos[i].altura = altura;
                }
                int piso, largo, ancho;

                for(int i=0; i<TAM_SALONES; i++){
                    printf("\nIngrese el numero de piso del salon %d: ",i+1);
                    fflush(stdin);
                    scanf("%d",&piso);
                    printf("Ingrese el largo del salon %d: ",i+1);
                    fflush(stdin);
                    scanf("%d",&largo);
                    printf("Ingrese el ancho del salon %d: ",i+1);
                    fflush(stdin);
                    scanf("%d",&ancho);

                    salones[i].numeroPiso = piso;
                    salones[i].largo = largo;
                    salones[i].ancho = ancho;
                }
                char nombre[NOMBRE_ESCUELA];
                printf("Ingrese el nombre de la escuela: ");
                fflush(stdin);
                scanf("%s",nombre);
                escuela = crearEscuela(alumnos,salones,nombre);
                break;
            case 2: 
                //Imprimir escuela
                if(escuela != NULL){ 
                    imprimirEscuela(*escuela);
                }
                break;
            case 3: 
                //Destruir escuela
                if(escuela!= NULL){
                    destruirEscuela(escuela);
                    puts("Escuela destruida");
                }
                break;
            case 4:
                //Copiar escuela.
                copiarEscuela(escuela,escuelaCopia);
                puts("\nEscuela Copiada con exito");
                break;
            default:
                opcionUsuario=0;
                puts("\nTerminando programa...");
                break;
        }
    }while(opcionUsuario!=0);
}