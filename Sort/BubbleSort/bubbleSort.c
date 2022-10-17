#include <stdio.h>

void BubbleSort(int*,int);

int main(){
    int A[] = {14,13,11,10};
    int n = sizeof(A) / sizeof(A[0]);
    for(int i=0; i<n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    BubbleSort(A,n);
    for(int i=0; i<n; i++){
        printf("%d ",A[i]);
    }
}
void BubbleSort(int* arr,int n){
    int i,j,aux;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(arr[j] > arr[j+1]){
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }
}