#ifndef CODE_WRITER_H
#define CODE_WRITER_H

#include <parser.h>

// Memory Segment Indices
#define LCL 0
#define ARG 1
#define THIS 2
#define THAT 3

// Logical Operation Indices
#define ADD 0
#define SUB 1
#define NEG 2
#define CONDITIONAL 3
#define AND 4
#define OR 5
#define NOT 6

// Iterates through each command in the linked list
void translateFile(FILE* dest, char* destName, command* listStart);
// Translates individual commands
void translateCommand(char* instructionBuffer, command* currentCommand, int instructionNumber);
// Generates an assembly instruction to push 
// a value on to the stack depending on the 
// respective memory segment rules
void pushValue(command* currentCommand, char* instruction);
// Generates an assembly instruction to pop a value off the stack
// to the respective memory segment
void popValue(command* currentCommand, char* instruction);
// Returns the assembly label for the respective memory segment
void getMemorySegment(char* memorySegment, char* buffer);
// Returns the index of the respective stack operation to be retrieved from
// its array
int getOperationIdx(command* currentCommand);

#endif
