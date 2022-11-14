/*
    (Uso del paradigma imperativo)
    Biblioteca,libreria o directiva

    Archivos.h o Archivo Header, se utiliza para guardar la siguiente información del
    programa.

        -Librerias externas o std (estandarizadas)
        -Variables globales
        -Constantes
        -Prototipo de funciones
        -Definicion de estructuras/uniones

    Nos acerca al paradigma orientado a objetos.
    Lo mejor es tener prototipos en el punto h
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define TAM 10 //Macro: Define el tamaño del arreglo

char var1;

void imprimirArreglo(int*, int);
void inicioOperacion(int,char**);//Funcion principal que va a sustituir a la principal.