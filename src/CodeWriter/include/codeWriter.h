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
void translateFile(FILE* dest, command* listStart);
// Translates individual commands
void translateCommand(char* instructionBuffer, command* currentCommand, int instructionNumber);
// Retrieves a value from the given memory segment to be pushed to the stack
void pushValue(command* currentCommand, char* instruction);
// Pops a value from the stack to the given memory segment at the given index
void popValue(command* currentCommand, char* instruction);
// Indexes into the respective memory segment of a memory segments array
void getMemorySegment(char* memorySegment, char* buffer);

#endif
