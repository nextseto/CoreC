//
//  ArrayHelper.c
//  CoreC
//

#include "ArrayHelper.h"

/** Standard Library Headers */
#include <stdlib.h>
#include <string.h>

/*
 
 */
void* arraySlice(const void* inputArray, int startIndex, int endIndex, int sizePerElement)
{
    const size_t bufferSize = (endIndex - startIndex + 1) * sizePerElement;
    void* tempBuffer = malloc(bufferSize);
    
    if (tempBuffer == NULL) { return NULL; }
    
    return memcpy(tempBuffer, (char*)inputArray + startIndex * sizePerElement, bufferSize);
}
