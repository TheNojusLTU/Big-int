#ifndef LIST_H
#define LIST_H

#include <string.h>

typedef struct {
    char *value; //The array size should be the lenght of the number +1 and the last character '\0'
    char sign; //If the value of this is not 0 then it is a negative number
    long NumSize;
    void *IsInitialized;
} BigInt;

int IsNumber(char number[]);
void BigIntInitialization(BigInt *A);
int SaveNumber(BigInt *A, char number[]);
int SubtractBigInt(BigInt *result, const BigInt *A, const BigInt *B);
int SubtractFunc(BigInt *result, const BigInt *A, const BigInt *B);
int CompareNum(const BigInt *A, const BigInt *B);
int AddBigInt(BigInt *result, const BigInt *A, const BigInt *B);
int AddFunc(BigInt *result, const BigInt *A, const BigInt *B);
char* ReturnBigInt(BigInt *A);


#endif