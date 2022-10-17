#include <stdio.h>

void BubbleSort2(int* arr,int n);

int main(){
    int A[] = {14,13,11,10};
    int n = sizeof(A) / sizeof(A[0]);
    for(int i=0; i<n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    BubbleSort2(A,n);
    for(int i=0; i<n; i++){
        printf("%d ",A[i]);
    }
}
void BubbleSort2(int* arr,int n){
    int aux;
    for(int i=0;i<n;i++){
        for (int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }
}