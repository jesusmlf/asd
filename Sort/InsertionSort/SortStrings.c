#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InsertionSortStrings(char** unsorted, int n);

int main(){
    int n = 4;
    char** unsorted = malloc(n*sizeof(char*));
    char numbers[][100] = {"4","312","234","10"};
    for(int i=0;i<n;i++){
        unsorted[i] = numbers[i];
    }
    InsertionSortStrings(unsorted,n);
    return 0;
}

void InsertionSortStrings(char** unsorted, int n){
    int num;
    printf("%d",(unsorted[0]-0));
}