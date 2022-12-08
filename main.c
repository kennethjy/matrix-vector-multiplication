#include "multiplier.h"
#include <stdio.h>

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