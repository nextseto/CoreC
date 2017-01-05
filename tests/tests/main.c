//
//  main.c
//  CoreC
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "StringHelper.h"


int main(int argc, const char * argv[])
{
    // ====== Run Tests =======
    
    //runTests();
    
    // ========================
    
    // === Prototyping Area ===
    
    char* temp = "abc.def.ghi.abc.def.ghi.abc.def.ghi.abc.def.ghi";
    StringArray output = stringSplit(temp, ".");
    
    int count, count2;
    for(count = 0; count < output.stringNum; count++)
    {
        printf("temp[%i] = ", count);
        
        for(count2 = 0; count2 < output.stringNum; count2++)
        {
            printf("%c", output.value[count][count2]);
        }
        printf("\n");
    }
    
    // ========================
    
    return 0;
}
