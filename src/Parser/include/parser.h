#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>

#define BUFSIZE 256
#define TYPE_LEN 5
#define MEM_LEN 9

// Command Struct
typedef struct command {
  char type[TYPE_LEN];
  char memorySegment[MEM_LEN];
  char value[BUFSIZE];
  struct command* next;
} command;

// Parses the provided file name and appends .asm
// If 0 is not returned then name parsing failed
int getFileName(char* srcFileName, char* destFileName);
// Extracts just the file name from its path
void stripFileName(char* fileName, char* strippedFileName);
// Breaks each line into its respective components
void parseFile(FILE* src, command** listStart);
// Strips lines of leading and trailing whitespace and comments
void strip(char* line);
// Checks if a character is a valid instruction character
int isInstructionChar(char c);

#endif
