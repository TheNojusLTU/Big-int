#ifndef LIST_H
#define LIST_H

#include <string.h>

typedef struct {
    char *value; //The array size should be the lenght of the number +1 and the last character '\0'
    char sign; //If the value of this is not 0 then it is a negative number
    long NumSize;
    void *IsInitialized;
} BigInt;

#endif