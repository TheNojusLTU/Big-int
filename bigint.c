#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bigint.h"

void BigIntInitialization(BigInt *A){
    A->IsInitialized = 0;
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
int SaveNumber(BigInt *A, char number[]){
    if(IsNumber(number)==0)
        return 0;
    
    int n = strlen(number);
    int start = 0;

    if(number[0] == '-'){
        A->sign = -1;
        start = 1;
    } else {
        A->sign = 1;
    }
    A->NumSize = n - start;

    A->value = malloc(A->NumSize * sizeof(char));

    if (A->value == NULL)
        return 0;

    int index = 0;
    for (int i = n - 1; i >= start; i--) {
        A->value[index++] = number[i];
    }

    A->IsInitialized = (void*)1;

    return 1;

}