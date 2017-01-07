//
//  StringHelper.h
//  CoreC
//

#ifndef StringHelper_h
#define StringHelper_h

/** Structure that allows 2D arrays (with the number of Strings) to be passed by value */
typedef struct Array {
    int length;
    char** values;
} StringArray;


/** Returns a String which contains a format for the values of each individual variable */
char* stringBuild(const char *format, ...);


/** A procedure that takes elements of a given string and put their values into individual variables */
void stringDisassemble(const char* input, const char* format, ...);


/** Returns the character values in the string */
char* stringCopy(const char* input);


/** If the substring is found in the searchString then return the index of the first character in the searchString. Otherwise, return -1. Note: This is case-sensitive */
int stringFind(const char* searchString, const char* subString);


/** Returns a new string with all matches of the old substring replaced by the new substring */
char* stringReplace(char* input, const char* oldSubString, const char* newSubString);


/** Returns a structure with: the array of strings split at each point where the separator occurs in the given input String and the number of strings in a 2D array. */
StringArray stringSplit(char* inputString, const char* seperatorString);


/** Returns the number of characters in the string */
int stringLength(const char* input);


/** Frees the memory used by a given StringArray input. Upon successful free-ing, num = -1. */
void freeStringArray(StringArray* input);


#endif /* StringHelper_h */
