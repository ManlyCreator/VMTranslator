#ifndef PARSER_H
#define PARSER_H

// Command Struct
typedef struct command {
  char* type;
  char* memorySegment;
  int value;
  struct command* next;
} command;

// Breaks each line into its respective components
void parseCommand(command* head, char* line);
// Strips lines of leading and trailing whitespace and comments
void strip(char* line);

#endif
