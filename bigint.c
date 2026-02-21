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
        A->sign = 1;
        start = 1;
    } else {
        A->sign = 0;
    }
    A->NumSize = n - start;

    char *temp = realloc(A->value, A->NumSize*sizeof(char));
    if (temp == NULL)
        return 0;

    A->value=temp;

    int index = 0;
    for (int i = n - 1; i >= start; i--) {
        A->value[index++] = number[i];
    }

    A->IsInitialized = (void*)1;

    return 1;

}
int SubtractBigInt(BigInt *result, const BigInt *A, const BigInt *B){

    if(A->IsInitialized==NULL || B->IsInitialized==NULL)
        return 0;

    //   + -
    if(A->sign ==0 && B->sign == 1){
      //  return SUDETIES FUNKC
    }

    // - +
    if(A->sign == 1 && B->sign == 0)
    {
        // sudetis
    }

    // - -
    if(A->sign == 1 && B->sign == 1){
        return SubtractFunc(result,A,B);
    }

    // + +
    if(A->sign == 0 && B->sign == 0){
        int cmp = CompareNum(A, B);

        if (cmp == 0)
        {
            SaveNumber(result, "0");
            return 1;
        }
        else if (cmp > 0)
        {
            SubtractFunc(result, A, B);
            result->sign = 0;
        }
        else
        {
            SubtractFunc(result, B, A);
            result->sign = 1;
        }
        return 1;
    }

}
int SubtractFunc(BigInt *result, const BigInt *A, const BigInt *B){

    char *temp = realloc(result->value, A->NumSize * sizeof(char));

    if (temp == NULL) 
        return 0;

    result->value = temp;

    int borrow = 0;

    for (int i = 0; i < A->NumSize; i++)
    {
        int digitA = A->value[i] - '0';
        int digitB = (i < B->NumSize) ? B->value[i] - '0' : 0;

        int diff = digitA - digitB - borrow;

        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        result->value[i] = diff + '0';
    }


    int size = A->NumSize;
    while (size > 1 && result->value[size - 1] == '0')
        size--;

    result->NumSize = size;
    result->sign = 0;
    result->IsInitialized = (void*)1;

    return 1;
}
int CompareNum(const BigInt *A, const BigInt *B)
{
    if (A->NumSize > B->NumSize)
        return 1;

    if (A->NumSize < B->NumSize)
        return -1;

    for (int i = A->NumSize - 1; i >= 0; i--)
    {
        if (A->value[i] > B->value[i])
            return 1;
            
        if (A->value[i] < B->value[i])
            return -1;
    }

    return 0;
}