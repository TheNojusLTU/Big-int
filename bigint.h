#ifndef LIST_H
#define LIST_H

#include <string.h>

typedef struct BigInt{
    char *value; //The array size should be the lenght of the number +1 and the last character '\0'
    char sign; //If the value of this is not 0 then it is a negative number
    long NumSize; //Holds the size of the BigInt and does not include the - and \0 symbols
    void *IsInitialized; //Used to check if it has been initialized
} BigInt;// !!!!!!!!!!!!! DO NOT CHANGE THESE VALUES MANUALLY

int IsNumber(char number[]);
void BigIntInitialization(BigInt *A);// USE THIS FUNCTION BEFORE DOING ANYTHING WITH THE BIG INT
int SaveNumber(BigInt *A, char number[]);//This is used to set a big int to a number. It accepts both negative and positive numbers
int SubtractBigInt(BigInt *result, const BigInt *A, const BigInt *B);// Use this function for subtraction
int SubtractFunc(BigInt *result, const BigInt *A, const BigInt *B);
int CompareNum(const BigInt *A, const BigInt *B);
int AddBigInt(BigInt *result, const BigInt *A, const BigInt *B);// Use this function for addition
int AddFunc(BigInt *result, const BigInt *A, const BigInt *B);
char* ReturnBigInt(BigInt *A);// This function returns big int as a string that you can print
void DestroyBigInt(BigInt *A);// Use this function when you dont need the BigInt anymore. BEFORE USING AGAIN INITIALIZE IT AGAIN
int MultiplyBigInt(BigInt *result, const BigInt *A, const BigInt *B);// Use this function to multiply two big ints
int DivideBigInt(BigInt *quotient,BigInt *remainder,const BigInt *A, const BigInt *B);// Use this function to divide two big ints

#endif