#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mylib/mylib.h"

#define LOWER 1
#define UPPER 5

int generateRandomInt(int lower, int upper){
    return (rand() % (upper-lower+1)) + lower;
}

void initMat(int* M, int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            M[N*i+j] = generateRandomInt(LOWER,UPPER);
        }
    }
}

void initVec(int* v, int N){
    for(int i=0; i<N; i++){
        v[i] = generateRandomInt(LOWER,UPPER);
    }
}

float mult(int N){

    int* M = (int *) malloc(N*N*sizeof(int));
    int* v = (int *) malloc(N*sizeof(int));
    int* b = (int *) malloc(N*sizeof(int));

    initMat(M, N);
    initVec(v, N);
    matVecMult(M,v,b,N);
    free(M);
    free(v);
    free(b);

    return 0;
}

int main(void){
    int loop_until = 50;
    float times[loop_until];
    while(loop_until < 51){
        for(int N=1; N <= loop_until; N++){
            times[N - 1] = mult(N);
        }
    }
    return 0;
}