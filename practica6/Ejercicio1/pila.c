#include "pila.h"

void crearTDA(Pila* p, int* error){
    p->cima = -1;
    *error = 0;
}

void apilar(Pila *p, int* error, Nodo dato){
    if(!isFull(*p,error)){
        (*p).cima++;
        p->elementos[p->cima] = dato;
        *error = 0;
    }else{
        puts("Pila llena");
        *error = -1;
    }
}

void desapilar(Pila *p,int* error, Nodo *datoExtraido){
    if(!isEmpty(*p,error)){
        *datoExtraido = p->elementos[p->cima];
        p->cima--;
        *error = 0;
    }else{
        puts("Pila vacia, no hay elementos para extraer");
        *error = -2;
    }
}

char consultarCima(Pila *p, int *error){
    //printf("\nEl valor de la cima es %d y contiene el valor: %d", p->cima,p->elementos[p->cima].valor);
    return p->elementos[p->cima].parentesis;
}

bool isEmpty(Pila p, int *error){
    if(p.cima == -1){
        *error = -2;
        return true;
    }else{
        *error = 0;
        return false;
    }
}

bool isFull(Pila p, int *error){
    if(p.cima == MAX-1){
        *error = -1;
        return true;
    }else{
        *error = 0;
        return false;
    }
}

//void vaciarPila(Pila *p, int *error){
//    Nodo datoAuxiliar;
//    puts("Comienza el proceso de vaciado");
//    while(!isEmpty(*p,error)){
//        desapilar(p,error,&datoAuxiliar);
//        printf("El valor extraido es: %d\n",datoAuxiliar.valor);
//    }
//    puts("Se termino de vaciar la pila");
//}

void inicioOperacion(int argv,char** argc){
    printf("Iniciando");
    Pila* p;
    int error = 0;
    
    
    char arregloOperaciones[8][50];
    char linea[50];
    int contador = 0;
    int opcion = 0;
    int iterador = 0;
    Nodo datoEntrada;
    Nodo datoSalida;
    
    //Leyendo el archivo.
    
    FILE* archivo = fopen("expresiones.txt","r");
    if (archivo == NULL){
        puts("No se puede leer el archivo");
    }
    while(!feof(archivo)){
        fscanf(archivo,"%s",linea);
        strcpy(arregloOperaciones[contador],linea);
        //printf("\n%s",arregloOperaciones[contador]);
        contador++;
    }
    
    strcpy(linea,"(a+b+(c*d))");
    
    //do{
    //    switch (linea[iterador])
    //    {
    //    case '(':
    //        datoEntrada.parentesis = '(';
    //        apilar(p,&error,datoEntrada);
    //        break;
    //    case '{':
    //        datoEntrada.parentesis = '{';
    //        apilar(p,&error,datoEntrada);
    //        break;
    //    case '[':
    //        datoEntrada.parentesis = '[';
    //        apilar(p,&error,datoEntrada);
    //        break;
    //    default:
    //        if(linea[iterador] == ')' || linea[iterador] =='}' || linea[iterador] ==']'){
    //            desapilar(p,&error,&datoSalida);
    //        }
    //        break;
    //}
    //iterador++;
    //}while(linea[iterador]!='\0');
//
    //printf("--%c--",consultarCima(p,&error));
    //printf("Cima: %d",p->cima);
//
    //if(isEmpty(*p,&error) == false){
    //    printf("False");
    //}
    //else{
    //    printf("True");
    //}
//

    for(int i=0;i<contador;i++){
        crearTDA(p,&error);
        iterador = 0;
        do{
            switch (arregloOperaciones[i][iterador])
            {
            case '(':
                datoEntrada.parentesis = '(';
                apilar(p,&error,datoEntrada);
                break;
            case '{':
                datoEntrada.parentesis = '{';
                apilar(p,&error,datoEntrada);
                break;
            case '[':
                datoEntrada.parentesis = '[';
                apilar(p,&error,datoEntrada);
            default:
                if(arregloOperaciones[i][iterador] == ')' || arregloOperaciones[i][iterador] == '}' || arregloOperaciones[i][iterador] == ']'){
                    if(isEmpty(*p,&error) == true){
                        break;
                    }
                    else{ 
                    desapilar(p,&error,&datoSalida);
                    }
                    
                }
                
                break;
            }
            iterador++;
        }while(arregloOperaciones[i][iterador]!= '\0');

        if(isEmpty(*p,&error) == false){
            printf("\nOperacion: %s             --      Valor: Falso",arregloOperaciones[i]);
        }else{
            printf("\nOperacion: %s             --      Valor: Verdadero",arregloOperaciones[i]);
        }
    }
}