//
//  StringHelper.c
//  CoreC
//

#include "StringHelper.h"

/** Standard Library Headers */
#include <string.h>
#include <stdlib.h>

/*
 
*/
int stringLength(char* input)
{
    return (int)strlen(input);
}

/*
 
 */
int stringFind(char* searchString, char* subString)
{
    int indexAt = (int)(strstr(searchString, subString) - searchString);
    
    return (indexAt < 0) ? -1 : indexAt;
}

/*
 
 */
char* stringCopy(char* input)
{
    size_t stringSize = strlen(input) + 1;
    char *tempString = malloc(stringSize);
    
    if (tempString == NULL) { return NULL; }
    
    return (char *)memcpy(tempString, input, stringSize);
}

/*
 
 */
char* stringSplit(char* inputString, char* seperatorString, int resultSizePtr)
{
    return "Not here";
}
