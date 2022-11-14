# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct Fruta{
    char nombre[20];
    char color[10];
    int cantidad;
    int precioUnidad;
};

struct Fruta* entradaDatos();
struct Fruta* generarFruta(char*,char*,int,int);
void listaFrutas(struct Fruta**,int);

struct Fruta* generarFruta(char* nombre,char* color,int cantidad,int precioUnidad){
    struct Fruta* fruta = (struct Fruta*) malloc(sizeof(struct Fruta));
    strcpy(fruta->nombre,nombre);
    strcpy(fruta->color,color);

    fruta->cantidad = cantidad;
    fruta->precioUnidad= precioUnidad;

    return fruta;
}

struct Fruta* entradaDatos(){

    struct Fruta* fruta = (struct Fruta*) malloc(sizeof(struct Fruta));
    char nombre[20];
    char color[10];
    int cantidad;
    int precioUnidad;

    printf("Ingrese el nombre de la fruta: ");
    fflush(stdin);
    scanf("%s",nombre);
    
    printf("Ingrese el color: ");
    fflush(stdin);
    scanf("%s",color);

    printf("Ingrese la cantidad: ");
    fflush(stdin);
    scanf("%d",&cantidad);

    printf("Ingrese el precio por unidad: ");
    fflush(stdin);
    scanf("%d",&precioUnidad);

    fruta = generarFruta(nombre,color,cantidad,precioUnidad);

    return fruta;
}

void listaFrutas(struct Fruta** lista_frutas,int cantidad){
    for(int i=0; i<cantidad ; i++){
        lista_frutas[i] = (struct Fruta *) malloc(sizeof(struct Fruta));
        lista_frutas[i] = entradaDatos();
    }
}

void main(){
    printf("Ingrese la cantidad de frutas: ");
    int cantidad = scanf("%d",&cantidad);

    struct Fruta** lista_frutas = (struct Fruta**) malloc((sizeof(struct Fruta*))*cantidad);
    listaFrutas(lista_frutas,cantidad);

}