#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOWER 1
#define UPPER 5

#include "mylib/mylib.h"

int generateRandomInt(int lower, int upper){
    return (rand() % (upper-lower+1)) + lower;
}

void initMat(int* M, int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            M[N * i + j] = generateRandomInt(LOWER,UPPER);
        }
    }
}

void initVec(int* v, int N){
    for(int i=0; i<N; i++){
        v[i] = generateRandomInt(LOWER,UPPER);
    }
}

int main(void){

    int N = 5;
    int* M = (int *) malloc(N * N * sizeof(int));
    int* v = (int *) malloc(N * sizeof(int));
    int* output_v = (int *) malloc(N * sizeof(int));

    
    
    initMat(M, N);
    initVec(v, N);
    matVecMult(M, v, output_v, N);
    
    printMat(M, N);
    printVec(v, N);
    printVec(output_v, N);

    free(M);
    free(v);
    free(output_v);

    return 0;
}
