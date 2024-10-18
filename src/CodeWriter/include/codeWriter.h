#ifndef CODE_WRITER_H
#define CODE_WRITER_H

#include <parser.h>

#define ADD 0
#define SUB 1
#define NEG 2
#define CONDITIONAL 3
#define AND 4
#define OR 5
#define NOT 6

// (Function signatures subject to change)
// Iterates through each command in the linked list
void translateFile(FILE* dest, command* listStart);
// Translates individual commands
void translateCommand(char* instructionBuffer, command* currentCommand, int instructionNumber);
// Retrieves the value from a given memory segment
int getValue(char* memorySegment, char* value);
// Indexes into the respective memory segment of a memory segments array
int getMemorySegment(char* memorySegment);

#endif
