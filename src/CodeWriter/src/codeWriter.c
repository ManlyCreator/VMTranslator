#include <codeWriter.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: Move stack operations over to header file
// TODO: Implement logical operations
// TODO: Implement memory segments
// TODO: Implement pop
char stackOperations[9][BUFSIZE] = {
  // [0] ADD
  {
    "@SP\n"
    "A=M\n"
    "A=A-1\n"
    "D=M\n"
    "A=A-1\n"
    "M=D+M\n"
    "@SP\n"
    "M=M-1\n"
  },
  // [1] SUB
  {
    "@SP\n"
    "A=M\n"
    "A=A-1\n"
    "D=M\n"
    "A=A-1\n"
    "M=M-D\n"
    "@SP\n"
    "M=M-1\n"
  },
  // [2] NEG
  {
    "@SP\n"
    "A=M\n"
    "A=A-1\n"
    "M=-M\n"
  },
  // [3] EQ
  {
    // TODO: Use JEQ to branch to the correct output
    "@SP\n"
    "A=M\n"
    "A=A-1\n"
    "D=M\n"
    "A=A-1\n"
    "D=M-D\n"
    "@SP\n"
    "M=M-1\n"
  },
  // [4] GT
  {

  },
  // [5] LT
  {

  },
  // [6] AND
  {
    "@SP\n"
    "A=M\n"
    "A=A-1\n"
    "D=M\n"
    "A=A-1\n"
    "D=D&M\n"
    "M=-D\n"
    "@SP\n"
    "M=M-1\n"
  },
  // [7] OR
  {
    "@SP\n"
    "A=M\n"
    "A=A-1\n"
    "D=M\n"
    "A=A-1\n"
    "D=D|M\n"
    "M=-D\n"
    "@SP\n"
    "M=M-1\n"
  },
  // [8] NOT
  {
    "@SP\n"
    "A=M\n"
    "A=A-1\n"
    "M=!M\n"
  }
};

void translateFile(FILE* dest, command* listStart) {
  command* temp = listStart;
  while (temp->next) {
    char instruction[BUFSIZE];
    translateCommand(instruction, temp);
    fprintf(
        dest,
        "// %s %s %s\n"
        "%s", 
        temp->type, temp->memorySegment, temp->value, instruction
    );
    temp = temp->next;
  }
}

void translateCommand(char* instructionBuffer, command* currentCommand) {
  if (strcmp(currentCommand->type, "push") == 0) {
    // TODO: Create a function that retrieves the value 
    // from a memory segment
    sprintf(
        instructionBuffer,
        "@%d\n"
        "D=A\n"
        "@SP\n"
        "A=M\n"
        "M=D\n"
        "@SP\n"
        "M=M+1\n",
        atoi(currentCommand->value)
    );
  } else if (strcmp(currentCommand->type, "pop") == 0) {

  } else {
    int operationIdx = 0;
    if (strcmp(currentCommand->type, "add") == 0) {
      operationIdx = ADD;
    } else if (strcmp(currentCommand->type, "sub") == 0) {
      operationIdx = SUB; 
    } else if (strcmp(currentCommand->type, "neg") == 0) {
      operationIdx = NEG;
    } else if (strcmp(currentCommand->type, "eq") == 0) {
      operationIdx = EQ;
    } else if (strcmp(currentCommand->type, "gt") == 0) {
      operationIdx = GT;
    } else if (strcmp(currentCommand->type, "lt") == 0) {
      operationIdx = LT;
    } else if (strcmp(currentCommand->type, "and") == 0) {
      operationIdx = AND;
    } else if (strcmp(currentCommand->type, "or") == 0) {
      operationIdx = OR;
    } else if (strcmp(currentCommand->type, "not") == 0) {
      operationIdx = NOT;
    }
    sprintf(instructionBuffer, "%s", stackOperations[operationIdx]);
  }
}
