#ifndef PARSER_H
#define PARSER_H

// Command Struct
typedef struct command {
  char* type;
  char* memorySegment;
  int value;
  struct command* next;
} command;

// Parses the provided filename and appends .asm
// If 0 is not returned then name parsing failed
int getFileName(char* srcFileName, char* destFileName);
// Breaks each line into its respective components
void parseFile(char* filename, command* head);
// Strips lines of leading and trailing whitespace and comments
void strip(char* line);
// Checks if a character is a valid instruction character
int isInstructionChar(char c);

#endif
