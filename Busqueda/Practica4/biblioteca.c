#include "biblioteca.h"

Persona* crearPersona(Datos datos){
    Persona* persona = (Persona*) malloc(sizeof(Persona));

    strcpy(persona->datos.PaisOrigen,datos.PaisOrigen);
    strcpy(persona->datos.Nombre,datos.Nombre);
    strcpy(persona->datos.Telefono,datos.Telefono);
    persona->datos.Alto = datos.Alto;
    return persona;
}

void imprimirPersonas(Persona** personas,int tam){
    for(int i=0;i<tam;i++){
        printf("\nNombre: %s\nPais de origen: %s\nAltura: %f\nTelefono: %s\n",personas[i]->datos.Nombre,personas[i]->datos.PaisOrigen,personas[i]->datos.Alto,personas[i]->datos.Telefono);
    }
}
void OrdenarAltura(Persona** personas, int tam){
    //Selection sort
    int i,j;
    Persona* min;
    for(i=0;i<tam;i++){
        j = i + 1;
        while(j<tam){
            if(personas[j]->datos.Alto < personas[i]->datos.Alto){
                min = personas[i];
                personas[i] = personas[j];
                personas[j] = min;
            }
            j+=1;
        }
    }
}
void mezclaPorNombre(Persona** arrIzq, int tamIzq, Persona** arrDer, int tamDer, Persona** personas){
    int i=0,j=0,k=0;
    while(i<tamIzq && j<tamDer){
        if(strcmp(arrIzq[i]->datos.Nombre,arrDer[j]->datos.Nombre)<0){
            personas[k]=arrIzq[i];
            i++;   
        } else{
            personas[k]=arrDer[j];
            j++;  
        }
        k++;
    }
    while(j<tamDer){
        personas[k]=arrDer[j];
        j++;
        k++;
    }
    while(i<tamIzq){
        personas[k]=arrIzq[i];
        i++;
        k++;
    }
}

void OrdenarNombre(Persona** personas, int tam){
    if(tam>1){
        int i,j,k;
        int mitad=tam/2;

        Persona* arrIzq[mitad];
        Persona* arrDer[tam-mitad];
        for(i=0, k=0; i<mitad; i++, k++){
            arrIzq[i]=personas[k];
        }
        for(j=0; j< (tam-mitad); j++, k++){
            arrDer[j] = personas[k];
        }
        OrdenarNombre(arrIzq,mitad);
        OrdenarNombre(arrDer,tam-mitad);
        mezclaPorNombre(arrIzq,mitad, arrDer,tam-mitad,personas);
    }
}

void OrdenarTelefono(Persona personas, int tam){}
void OrdenarPais(Persona personas, int tam){}

Persona* buscarTelefono(Persona** personas,int tam,char* telefono){
    //Busqueda secuencial
    int pos = 0;

    while(pos<tam){
        if (strcmp(personas[pos]->datos.Telefono,telefono) == 0){
            return personas[pos];
        }
        else{
            pos++;
        }
    }
    puts("No se encontro la persona");
}
void inicioOperacion(int argc, char** argv){
    int opcion = 0;

    FILE* archivo = fopen("Data/BD_Personas.csv","r");

    if (archivo == NULL){
        perror("No se pudo abrir el archivo");
        exit(1);
    }
    Persona** personas = (Persona**) malloc(sizeof(Persona)*130);
    Datos* datos = (Datos*) malloc(sizeof(Datos)*130);

    //Persona personas[130];
    int read = 0;
    int records = 0;
    int contador = 0;
    char NombreColumnas[100];
    fscanf(archivo,"%99[^\n]",NombreColumnas);
    fflush(stdin);
    do{
        fflush(stdin);
        read = fscanf(archivo,"%49[^,],%49[^,],%lf,%49[^\n]\n",datos[records].PaisOrigen, datos[records].Nombre, &datos[records].Alto, datos[records].Telefono);
        fflush(stdin);
        //printf("%s,%s,%lf,%s\n",datos[records].PaisOrigen, datos[records].Nombre, datos[records].Alto, datos[records].Telefono);  
        personas[records] = crearPersona(datos[records]);
        //printf("\n%s %f %s",personas[records]->datos.Nombre,personas[records]->datos.Alto,personas[records]->datos.Telefono);
        if (read == 4) records++;
        if (read != 4 && !feof(archivo)){
            perror("Ero¿rrrrr");
        }

        if (ferror(archivo)){
        printf("Error reading file.\n");
        exit(1);
        }
        contador++;

    } while(!feof(archivo));

    fclose(archivo);
    printf("\n%d records read.\n\n", records);

    puts("1.- Imprimir personas.");
    puts("2.- Ordenar lista por altura.");
    puts("3.- Ordenar lista por segunda letra del nombre.");
    puts("4.- Ordenar lista por numero de telefono.");
    puts("5.- Ordenar lista por pais de origen.");
    printf("Elige una opcion: ");
    scanf("%d",&opcion);

    switch (opcion)
    {
    case 1:
        printf("--Imprimir personas--");
        //for(int i=0;i<contador;i++){
        //    printf("Nombre: %s\nPais de origen: %s\nAltura: %f\nTelefono: %s",personas[i]->datos.Nombre,personas[i]->datos.PaisOrigen,personas[i]->datos.Alto,personas[i]->datos.Telefono);
        //}
        imprimirPersonas(personas,contador);
        break;
    case 2:
        //Selection sort
        printf("asd");
        OrdenarAltura(personas,contador);
        imprimirPersonas(personas,contador);
        printf("Buscando telefono");
        Persona* personaBuscada = buscarTelefono(personas,contador,"558208054");
        printf("%s",personaBuscada->datos.Nombre);
        break;
    case 3:
        OrdenarNombre(personas,contador);
        imprimirPersonas(personas,contador);
    default:
        break;
    }
}