//
//  ArrayHelper.c
//  CoreC
//

#include "ArrayHelper.h"

/** Standard Libraries */
#include <stdlib.h>
#include <string.h>

/*
 Name : arraySlice
 
 Description : Returns a generic array that contains the elements inputArray[start] ... inputArray[end] inclusively
 
 Motivation :
 
 API Details :
 
 Returns :
 
 */
void* arraySlice(const void* inputArray, int startIndex, int endIndex, int sizePerElement)
{
    const size_t bufferSize = (endIndex - startIndex + 1) * sizePerElement;
    void* tempBuffer = malloc(bufferSize);
    
    if (tempBuffer == NULL) { return NULL; }
    
    return memcpy(tempBuffer, (char*)inputArray + startIndex * sizePerElement, bufferSize);
}
