//
//  FileSystem.h
//  CoreC
//


#ifndef FileSystem_h
#define FileSystem_h

#include "StringHelper.h"

/*
 Section : FileSystem File Methods
 Dependency : StringHelper library
 */


/**  */
char* fileNew(char* path, char* name);


/**  */
int fileExist(char* path);


/**  */
int fileRename(char* oldPath, char* newName);


/**  */
int fileCopy(char* sourcePath, char* destinationPath);


/**  */
int fileMove(char* oldPath, char* newPath);


/**  */
int fileSize(char* path);


/**  */
StringArray fileRead(char* path);


/**  */
int fileWriteLine(char* path, char* writeString);


/**  */
int fileWrite(char* path, StringArray* writeData);


/**  */
int fileDelete(char* path);


/*
 Section : FileSystem Folder Methods
 Dependency : None
 */


/**  */
char* folderNew(char* path, char* name);


/**  */
int folderExist(char* path);


/**  */
int folderRename(char* oldPath, char* newName);


/**  */
int folderCopy(char* sourcePath, char* destinationPath);


/**  */
int folderMove(char* oldPath, char* newPath);


/**  */
int folderSize(char* path);


/**  */
int folderDelete(char* path);


/*
 Section : FileSystem General Methods
 Dependency : StringHelper library
 */


/**  */
StringArray listFiles(char* folderPath);


/**  */
char* currentDirectory();


#endif /* FileSystem_h */

