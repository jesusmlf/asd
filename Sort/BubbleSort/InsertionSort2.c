#include <stdio.h>

void InsertionSort2(int* arr, int n);
int main(){
    int A[] = {14,13,11,10};
    int n = sizeof(A) / sizeof(A[0]);

    for(int i=0; i<n; i++){
        printf("%d ",A[i]);
    }

    printf("\n");
    InsertionSort2(A,n);
    
    for(int i=0; i<n; i++){
        printf("%d ",A[i]);
    }
}
void InsertionSort2(int* arr, int n){
    int i,j,key;
    for(i=1; i<n; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j -= 1;
        }
        arr[j+1] = key;
    }
}