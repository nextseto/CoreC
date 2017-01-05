//
//  StringHelper.h
//  CoreC
//

#ifndef StringHelper_h
#define StringHelper_h

/** Structure that allows 2D arrays (with the number of Strings) to be passed by value */
typedef struct Array {
    int stringNum;
    char** value;
} StringArray;

/** Returns the number of characters in the string */
int stringLength(const char* input);

/** If the substring is found in the searchString then return the index of the first character in the searchString. Otherwise, return -1. Note: This is case-sensitive */
int stringFind(const char* searchString, const char* subString);

/** Returns the character values in the string */
char* stringCopy(const char* input);

/** Returns a structure with: the array of strings split at each point where the separator occurs in the given input String and the number of strings in a 2D array. */
StringArray stringSplit(char* inputString, const char* seperatorString);

#endif /* StringHelper_h */
