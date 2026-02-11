#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bigint.h"

void BigIntInitialization(BigInt *A){
    A->IsInitialized = NULL;
    A->NumSize = 0;
    A->sign = 0;
    A->value = NULL;
}

int IsNumber(char number[]){//neveikia kolkas
    int n = strlen(number);
    int test = 0;
    for(int i = 0; i < n; i++){
        if((i == n-1)){
            test++;
        }
        else if(number[i] >= '0' && number[i] <= '9' && (i != n-1)){
            test++;
            printf("%d:%d\n", n, i);
        }
    }
    return test;
}