#ifndef CODE_WRITER_H
#define CODE_WRITER_H

#include <parser.h>

// (Function signatures subject to change)
// Iterates through each command in the linked list
void translateFile(command* commandStart);
// Translates individual commands
void translateCommand(command* currentCommand);

#endif
