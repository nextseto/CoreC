//
//  tests.c
//  CoreC
//

#include <stdio.h>
#include <string.h>

/*  */

#include "ArrayHelper.h"
#include "Console.h"
#include "StringHelper.h"

// TODO : Write Tests

int consoleTest()
{
    return 0;
}

int stringTest()
{
    return 0;
}

int assert1DArray(void* expected, void* result, int numElements, size_t sizePerElement)
{
    return !memcmp(expected, result, sizePerElement * numElements);
}

int arrayTest()
{
    int verify = 1;
    
    /* arraySlice(...) */
    
    int test1[] = {1,2,3,4,5};
    int testExpect[] = {1,2,3};
    verify = assert1DArray(testExpect, arraySlice(test1, 0, 2, sizeof(int)), 3, sizeof(int)) && verify;
    printf("%i - ", verify);
    
    int test2[] = {1,2,3,4,5,6,7,8,9,10};
    int test2Expect[] = {4,5,6,7,8,9,10};
    verify = assert1DArray(test2Expect, arraySlice(test2, 3, 9, sizeof(int)), 6, sizeof(int)) && verify;
    printf("%i - ", verify);
    
    int test3[] = {100,2,300,4,500,6,7,800,9,10};
    int test3Expect[] = {4};
    verify = assert1DArray(test3Expect, arraySlice(test3, 3, 3, sizeof(int)), 1, sizeof(int)) && verify;
    printf("%i - ", verify);
    
    char* test4 = "Hello w";
    char* test4Expect = "ello w";
    verify = assert1DArray(test4Expect, arraySlice(test4, 1, 6, sizeof(char)), 6, sizeof(char)) && verify;
    printf("%i - ", verify);
    
    char* test5 = "Dr. Li is the best professor. Give us 10 minute break~";
    char* test5Expect = "professor. Give us 10 minute break~";
    verify = assert1DArray(test5Expect, arraySlice(test5, 19, (int)strlen(test5), sizeof(char)), (int)strlen(test5Expect), sizeof(char)) && verify;
    printf("%i - ", verify);
    
    double test6[] = {9.2, 7.6, 4.2};
    double test6Expect[] = {9.2, 7.6, 4.2};
    verify = assert1DArray(test6Expect, arraySlice(test6, 0, 2, sizeof(double)), 3, sizeof(double)) && verify;
    printf("%i", verify);

    return verify;
}

/* */
extern void runTests()
{
    printf("----- arrayTest ------\n");
    arrayTest();
    printf("\n----------------------\n");
}

