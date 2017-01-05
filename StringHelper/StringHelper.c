//
//  StringHelper.c
//  CoreC
//

#include "StringHelper.h"

/** Standard Library Headers */
#include <stdlib.h>
#include <string.h>

char** _stringAppend2D(char* startPointer, char* endPointer, char** appendingArray, int* currentSize, int* alertSize);

/*
 
 */
int stringLength(const char* input)
{
    return (int)strlen(input);
}


/*
 
 */
int stringFind(const char* searchString, const char* subString)
{
    const int indexAt = (int)(strstr(searchString, subString) - searchString);
    
    return (indexAt < 0) ? -1 : indexAt;
}


/*
 
 */
char* stringCopy(const char* input)
{
    const size_t stringSize = strlen(input) + 1;
    char *stringBuffer = malloc(stringSize);
    
    if (stringBuffer == NULL) { return NULL; }
    
    return (char *)memcpy(stringBuffer, input, stringSize);
}


/*
 
 */
StringArray stringSplit(char* inputString, const char* seperatorString)
{
    int stringCount = 0, startSize = 10;
    char** output = malloc(startSize * sizeof(char*));
    
    char* startPointer = inputString;
    char* endPointer = inputString;
    
    const size_t seperatorSize = strlen(seperatorString);
    
    while (*startPointer)
    {
        if (*startPointer == *seperatorString)
        {
            if (!memcmp(startPointer, seperatorString, seperatorSize))
            {
                output = _stringAppend2D(startPointer, endPointer, output, &stringCount, &startSize);
                
                startPointer += seperatorSize;
                endPointer = startPointer;
                continue;
            }
        }
        
        ++startPointer;
    }
    
    output = _stringAppend2D(startPointer, endPointer, output, &stringCount, 0);
    
    return (StringArray){ .num = stringCount, .values = output };
}


/// Helper Functions

/*

 */
char** _stringAppend2D(char* startPointer, char* endPointer, char** appendingArray, int* currentSize, int* alertSize)
{
    if (alertSize)
    {
        if (*alertSize - *currentSize < 3)
        {
            appendingArray = realloc(appendingArray, sizeof(char*) * (*currentSize + *alertSize));
            (*alertSize)++;
        }
    }
    
    else {
        appendingArray = realloc(appendingArray, sizeof(char*) * (*currentSize + 1));
    }
    
    const size_t stringSize = startPointer - endPointer;
    appendingArray[*currentSize] = malloc((stringSize + 1) * sizeof(char));
    
    memcpy(appendingArray[*currentSize], endPointer, stringSize * sizeof(char));
    appendingArray[*currentSize][stringSize] = '\0';
    
    (*currentSize)++;
    
    return appendingArray;
}
