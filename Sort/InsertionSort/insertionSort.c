#include <stdio.h>

void insertionSort(int* arr, int n);
void reverseInsertionSort(int *arr, int n);
int main(){
    int arreglo[] = {4,3,2,1};
    const int num = 4;
    //printf("%d\n",num);

    insertionSort(arreglo,num);
    for(int i=0; i<num ; i++){
        printf("%d ",arreglo[i]);
    }
    printf("\n");
    reverseInsertionSort(arreglo,num);

    for(int i=0; i<num ; i++){
        printf("%d ",arreglo[i]);
    }
}
void reverseInsertionSort(int *arr,int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key = arr[i];
        j = i - 1;
        while(j>=0 && arr[j] < key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}
void insertionSort(int* arr, int n){
    int i,j,aux;
    for(i=1; i<n ;i++){
        aux = arr[i];
        j = i - 1;
        while(j>=0 && arr[j] > aux){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = aux;   
    }
}