#include <stdio.h>
#include <stdlib.h>

#define NUMS 50
FILE* LeerArchivo(char*);
int* GenerarArreglo(FILE*);
void InsertionSort(int*,int);
void ImprimirDatos(int*, int);

void InicioOperacion(int argc, char** argv);