//
//  StringHelper.c
//  CoreC
//

#include "StringHelper.h"

/** Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 Name : stringBuild
 
 Description : Returns a String which contains a format for the values of each individual variable
 
 Motivation :
 
 API Details :
 
 Returns :
 
 */
char* stringBuild(const char *format, ...)
{
    return "";
}


/*
 Name : stringDisassemble
 
 Description : A procedure that takes elements of a given string and put their values into individual variables
 
 Motivation :
 
 API Details :
 
 Returns :
 
 */
void stringDisassemble(const char* input, const char* format, ...)
{
    return;
}


/*
 Name : stringCopy
 
 Description : Returns the character values in the string
 
 Motivation :
 
 API Details :
 
 Returns :
 
 */
char* stringCopy(const char* input)
{
    const size_t stringSize = strlen(input) + 1;
    char *stringBuffer = malloc(stringSize);
    
    if (stringBuffer == NULL) { return NULL; }
    
    return (char *)memcpy(stringBuffer, input, stringSize);
}


/*
 Name : stringFind
 
 Description : If the substring is found in the searchString then return the index of the first character in the searchString. Otherwise, return -1. Note: This is case-sensitive
 
 Motivation :
 
 API Details :
 
 Returns :
 
 */
int stringFind(const char* searchString, const char* subString)
{
    const int indexAt = (int)(strstr(searchString, subString) - searchString);
    
    return (indexAt < 0) ? -1 : indexAt;
}


/*
 Name : stringReplace
 
 Description : Returns a new string with all matches of the old substring replaced by the new substring
 
 Motivation :
 
 API Details :
 
 Returns :
 
 */
char* stringReplace(char* input, const char* oldSubString, const char* newSubString)
{
    char* startPointer = input;
    
    size_t inputLength = strlen(startPointer);
    const size_t oldLength = strlen(oldSubString);
    const size_t newLength = strlen(newSubString);
    
    char* outputString = malloc((oldLength >= newLength ? inputLength : newLength * inputLength) * sizeof(char));
    
    inputLength = 0;
    
    while (*startPointer)
    {
        if (*startPointer == *oldSubString)
        {
            if (!strncmp(startPointer, oldSubString, oldLength * (sizeof(char))))
            {
                memcpy(outputString + inputLength, newSubString, newLength * sizeof(char));
                
                inputLength += newLength;
                startPointer += oldLength;
                continue;
            }
        }
        
        outputString[inputLength++] = *startPointer;
        startPointer++;
    }
    
    outputString = realloc(outputString, inputLength + 1);
    outputString[inputLength] = '\0';
    
    return outputString;
}


/// Private API (Serves as helper method for stringSplit(...). More documentation in the 'Private API' section below
char** _stringAppend2D(char* startPointer, char* endPointer, char** appendingArray, int* currentSize, int* alertSize);

/*
 Name : stringSplit
 
 Description : Returns a structure with: the array of strings split at each point where the separator occurs in the given input String and the number of strings in a 2D array
 
 Motivation :
 
 API Details :
 
 Returns :
 
 */
StringArray stringSplit(char* inputString, const char* seperatorString)
{
    int stringCount = 0, bufferSize = 10;
    char** output = malloc(bufferSize * sizeof(char*));
    
    char* startPointer = inputString;
    char* endPointer = inputString;
    
    const size_t seperatorSize = strlen(seperatorString);
    
    while (*startPointer)
    {
        if (*startPointer == *seperatorString)
        {
            if (!strncmp(startPointer, seperatorString, seperatorSize))
            {
                output = _stringAppend2D(startPointer, endPointer, output, &stringCount, &bufferSize);
                
                startPointer += seperatorSize;
                endPointer = startPointer;
                continue;
            }
        }
        
        ++startPointer;
    }
    
    output = _stringAppend2D(startPointer, endPointer, output, &stringCount, 0);
    
    return (StringArray){ .length = stringCount, .values = output };
}


/*
 Name : stringLength
 
 Description : Returns the number of characters in the string
 
 Motivation :
 
 API Details :
 
 Returns :
 
 */
int stringLength(const char* input)
{
    return (int)strlen(input);
}


/*
 Name : freeStringArray
 
 Description : Frees the memory used by a given StringArray input. Upon successful free-ing, length = -1.
 
 Motivation :
 
 API Details :
 
 Returns :
 
 */
void freeStringArray(StringArray* input)
{
    while ((input->length)--)
    {
        free(input->values[input->length]);
    }
    
    free(input->values);
}


/// Private APIs

/*
 Name : _stringAppend2D
 
 Description :
 
 Motivation :
 
 API Details :
 
 Returns :
 
 */
char** _stringAppend2D(char* startPointer, char* endPointer, char** appendingArray, int* currentSize, int* alertSize)
{
    if (alertSize)
    {
        if (*alertSize - *currentSize < 3)
        {
            appendingArray = realloc(appendingArray, sizeof(char*) * (*currentSize + *alertSize));
            *alertSize += *alertSize;
        }
    }
    
    else {
        appendingArray = realloc(appendingArray, sizeof(char*) * (*currentSize + 1));
    }
    
    const size_t stringSize = startPointer - endPointer;
    appendingArray[*currentSize] = malloc((stringSize + 1) * sizeof(char));
    
    memcpy(appendingArray[*currentSize], endPointer, stringSize * sizeof(char));
    appendingArray[(*currentSize)++][stringSize] = '\0';
    
    return appendingArray;
}
