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