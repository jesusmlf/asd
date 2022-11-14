// Problema: Contar de 0 a 100, de 2 en 2, sobre una unica direccion de memoria.

# include <stdio.h>
# define N 2
int main(int argc , char** argv){

    //int i = 0;
//
    //for (i = 0 ; i<= 100; i+= 2){
    //    printf("%d\n",i);
    //}

    int i = 10;
    int *ptr_i = &i;
    for (*ptr_i = 0;*ptr_i <=100 ; *ptr_i += N){
        printf("%d\n",*ptr_i);
    }
    *ptr_i = 5;
    printf("%d",i);
    //Este programa utiliza 8 bytes de memoria.
    return 0;
}