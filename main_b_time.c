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


    float startTime = (float)clock()/CLOCKS_PER_SEC;
    initMat(M, N);
    printf("M=");
    printMat(M, N);
    initVec(v, N);
    printf("v=");
    printVec(v, N);
    matVecMult(M,v,b,N);
    printf("b=");
    printVec(b, N);
    float endTime  = (float)clock()/CLOCKS_PER_SEC;
    float out = endTime - startTime;
    free(M);
    free(v);
    free(b);
    return out;

}

int main(void){
    int loop_until = 50;
    float times[loop_until];
    for(int N=1; N <= loop_until; N++){
        times[N - 1] = mult(N);
    }
    FILE *fptr;
    fptr = fopen("file.txt","a");
    for(int N=0; N < loop_until; N++){
        fprintf(fptr, "%f\n", times[N]);
    }
    fprintf(fptr, "\n");
    fclose(fptr);
    return 0;
}