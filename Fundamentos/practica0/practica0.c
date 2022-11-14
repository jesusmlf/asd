# include <stdio.h>
# include <stdlib.h>

int* ValoresHexadecimal(){
    int * listaHexadecimal = (int*) malloc(sizeof(int)*255);
    int i = 0;
    while(i< 255){
        listaHexadecimal[i] = 0;
    }
}
int main(){
    int i = 0;
    int num = '64';
    printf("%s",num);
    while(i<255){
        //printf("\n%d,%x,%c",i,i,i+'0');
        i++;
    }
    return 0;
}
