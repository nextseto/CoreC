//
//  main.c
//  CoreC
//

/** Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** CoreC Libraries */
#include "ArrayHelperTests.h"
#include "StringHelper.h"
#include "ConsoleTests.h"


int main(int argc, const char * argv[])
{
    // === Prototyping Area ===

    // ====== Run Tests =======
    
    /*
    runTests();
    */
    
    /// Test 1 : stringSplit
    
    char* temp = "abc.def.ghi.abc.def.ghi.abc.def.ghi.abc.def.ghi";
    StringArray output = stringSplit(temp, ".");
    
    printf("Result Array of Strings from stringSplit > \n");
    
    int count, count2;
    for(count = 0; count < output.length; count++)
    {
        printf("temp[%i] = ", count);
        
        for(count2 = 0; count2 < strlen(output.values[count]); count2++)
        {
            printf("%c", output.values[count][count2]);
        }
        printf("\n");
    }
    
    
    freeStringArray(&output);
    
    
    /// Test 2 : stringSplit
    
    char* newString = stringReplace(temp, ".", " ");

    printf("\nResult String from stringRepalce > {%s} \n\n", newString);
    
    free(newString);
    
    // ========================
    
    return 0;
}
