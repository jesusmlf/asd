#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int* arr,int n);
int main(){ 
    int A[] = {14,33,27,10,35,19,42,44};
    int n = 8;
    for (int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    SelectionSort(A,n);

    printf("\n");
    for (int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}

void SelectionSort(int* arr,int n){
    int i,j,min;
    for(i=0;i<n;i++){
        j = i + 1;
        while(j<n){
            if(arr[j] < arr[i]){
                min = arr[i];
                arr[i] = arr[j];
                arr[j] = min;
            }
            j+=1;
        }
    }
}