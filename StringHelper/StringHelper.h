//
//  StringHelper.h
//  CoreC
//

#ifndef StringHelper_h
#define StringHelper_h

/** Returns the number of characters in the string */
int stringLength(char* input);

/** If the substring is found in the searchString then return the index of the first character in the searchString. Otherwise, return -1. Note: This is case-sensitive */
int stringFind(char* searchString, char* subString);

/** Returns the character values in the string */
char* stringCopy(char* input);

/** Returns an array of strings split at each point where the separator occurs in the given input String. Note: Pass a int pointer to get the size of 1D pointers. */
char* stringSplit(char* inputString, char* seperatorString, int resultSizePtr);

#endif /* StringHelper_h */
