# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct Fruta{
    char nombre[20];
    int cantidad;
    int precioUnitario;
};

struct Fruta* generarFruta();
struct Fruta** generarListaFrutas(int);

int pedirCantidadFrutas();
void ImprimirDatos(struct Fruta**, int);


void main(){
    int cantidad = pedirCantidadFrutas();
    struct Fruta** lista_frutas = generarListaFrutas(cantidad);
    ImprimirDatos(lista_frutas,cantidad);
}

struct Fruta* generarFruta(){
    char nombre[20];
    int cantidad, precioUnitario;
    printf("\nIngrese el nombre de la fruta: ");
    scanf("%s",nombre);

    printf("Ingrese la cantidad: ");
    scanf("%d",&cantidad);

    printf("Ingrese el precio unitario de la fruta: ");
    scanf("%d",&precioUnitario);

    struct Fruta* fruta_generada = (struct Fruta*) malloc(sizeof(struct Fruta));
    
    if (fruta_generada == NULL){
        perror("No hay memoria suficiente para generar la instancia");
        exit(1);
    }

    strcpy(fruta_generada->nombre,nombre);
    fruta_generada->cantidad = cantidad; 
    fruta_generada->precioUnitario = precioUnitario;

    return fruta_generada;
}
struct Fruta** generarListaFrutas(int cantidad){
    struct Fruta** lista_frutas = (struct Fruta**) malloc(sizeof(struct Fruta*) * cantidad);
    if(lista_frutas == NULL){
        perror("No hay memoria para la lista de frutas");
        exit(1);
    }
    for(int i=0 ; i<cantidad ; i++){
        lista_frutas[i] = (struct Fruta*) malloc(sizeof(struct Fruta));
        if(lista_frutas[i] == NULL){
            perror("No hay memoria para el elemento dentro de la lista");
            exit(1);
        }
        lista_frutas[i] = generarFruta("Manzana",2,3);
    }
    return lista_frutas;
}

int pedirCantidadFrutas(){
    int cantidad;
    printf("Ingrese la cantidad de frutas que desea agregar: ");
    scanf("%d",&cantidad);
    return cantidad;
}

void ImprimirDatos(struct Fruta** lista_frutas, int cantidad){
    for(int i=0; i<cantidad; i++){
        printf("\nNombre: %s      -   Cantidad: %d    -   Precio Unitario: %d",lista_frutas[i]->nombre,lista_frutas[i]->cantidad,lista_frutas[i]->precioUnitario);
    }
}