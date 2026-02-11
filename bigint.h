#ifndef LIST_H
#define LIST_H

#include <string.h>

typedef struct {
    char *value;
    char sign;
    long NumSize;
    void *isInitialised;
} BigInt;

#endif