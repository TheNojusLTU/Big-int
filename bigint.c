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
        if(!(((i == 0)&&((number[i] >= '0' && number[i] <= '9')||(number[i] == '-'&& n != 1)))||(number[i] >= '0' && number[i] <= '9'))){
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

    while (start < n - 1 && number[start] == '0') {
        start++;
    }//skip the leazing zeros

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
        return AddFunc(result, A, B);
    }

    // - +
    if(A->sign == 1 && B->sign == 0)
    {
        return AddFunc(result, A, B);
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

    if (size == 1 && result->value[0] == '0') {
        result->sign = 0;
    }

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
int AddBigInt(BigInt *result, const BigInt *A, const BigInt *B){

    if(A->IsInitialized==NULL || B->IsInitialized==NULL)
        return 0;

    //   + -  -
    if(A->sign ==0 && B->sign == 1){
        int cmp = CompareNum(A, B);

        if (cmp == 0) {
            SaveNumber(result, "0");
            return 1;
        } 
        else if (cmp > 0) {
            SubtractFunc(result, A, B);
            result->sign = A->sign; 
        } 
        else {
            SubtractFunc(result, B, A);
            result->sign = B->sign; 
        }
        return 1;
        }

    //   - +  -
    else if(A->sign == 1 && B->sign == 0)
    {
        int cmp = CompareNum(A, B);

        if (cmp == 0) {
            SaveNumber(result, "0");
            return 1;
        } 
        else if (cmp > 0) {
            SubtractFunc(result, A, B);
            result->sign = A->sign; 
        } 
        else {
            SubtractFunc(result, B, A);
            result->sign = B->sign; 
        }
        return 1;
    }

    //   - -  +
    else if(A->sign == 1 && B->sign == 1){
        return AddFunc(result, A, B);
    }

    //   + +  +
    else if(A->sign == 0 && B->sign == 0){
        return AddFunc(result, A, B);
    }
    return 0;
}
int AddFunc(BigInt *result, const BigInt *A, const BigInt *B){
    int carry = 0;
    int n;
    char *temp = NULL;
    int resultSize;
    if(A->NumSize >= B->NumSize){
        n = B->NumSize;
        resultSize = A->NumSize;
    }else{
        n = A->NumSize;
        resultSize = B->NumSize;
    }
    temp = malloc(sizeof(char)*resultSize+1);
    if (temp == NULL) 
        return 0;

    for(int i = 0; i < n; i++){
        temp[i] = A->value[i] + B->value[i] - '0' + carry;
        if(temp[i] > '9'){
            temp[i] = temp[i] - 10;
            carry = 1;
        }else carry = 0;
    }
    if(A->NumSize > B->NumSize){
        for(int i = n; i < A->NumSize; i++){
            temp[i] = A->value[i] + carry;
            if(temp[i] > '9'){
                temp[i] = temp[i] - 10;
                carry = 1;
            }else carry = 0;
        }
    }
    if(A->NumSize < B->NumSize){
        for(int i = n; i < B->NumSize; i++){
            temp[i] = B->value[i] + carry;
            if(temp[i] > '9'){
                temp[i] = temp[i] - 10;
                carry = 1;
            }else carry = 0;
        }
    }
    if(carry == 1){
        resultSize++;
        temp[resultSize-1] = '1';
    }

    result->NumSize = resultSize;
    free(result->value);
    result->value = temp;
    if(A->sign == B->sign)
        result->sign = A->sign;
    else 
        result->sign = 0;

    if (resultSize == 1 && result->value[0] == '0') {
        result->sign = 0;
    }

    return 1;
}
char* ReturnBigInt(BigInt *A){
    char *temp = malloc(sizeof(char)*A->NumSize+2);
    if(temp == NULL)
        return NULL;
    int offset = 0;
    if(A->sign == 1)
        temp[offset++] = '-';
    for(int i = 0; i < A->NumSize; i++){
        temp[i+offset] = A->value[A->NumSize-1-i];
    }
    temp[A->NumSize+offset] = '\0';
    
    return temp;
}