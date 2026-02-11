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

int IsNumber(char number[]){
    int n = strlen(number);
    int test = 0;
    for(int i = 0; i < n; i++){
        if(!(((i == 0)&&((number[i] >= '0' && number[i] <= '9')||number[i] == '-'))||(number[i] >= '0' && number[i] <= '9'))){
            return 0;
        }
    }
    return 1;
}