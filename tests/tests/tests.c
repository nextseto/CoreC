//
//  tests.c
//  CoreC
//

#include <stdio.h>
#include <string.h>

/*  */

#include "ArrayHelperTests.h"
#include "ConsoleTests.h"
#include "StringHelperTests.h"

// TODO : Write Tests



int assert1DArray(void* expected, void* result, int numElements, size_t sizePerElement)
{
    return !memcmp(expected, result, sizePerElement * numElements);
}



/* */
extern void runTests()
{
    printf("----- arrayTest ------\n");
    arrayTest();
    printf("\n----------------------\n");
}

