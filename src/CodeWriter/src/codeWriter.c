#include "parser.h"
#include <codeWriter.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char fileName[BUFSIZE];
int condtionalLabelCounter = 0;

void translateFile(FILE* dest, char* destName, command* listStart) {
  // Extracts just the file name from the path and stores it in
  // fileName
  stripFileName(destName, fileName);
  // Starts translating each VM instruction into Hack assembly
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
    command* copy = temp;
    temp = temp->next;
    free(copy);
  }
  free(temp);
}

void translateCommand(char* instructionBuffer, command* currentCommand) {
  if (strcmp(currentCommand->type, "push") == 0) {
    char instruction[BUFSIZE];
    pushValue(currentCommand, instruction);
    sprintf(
        instructionBuffer,
        "%s"
        "@SP\n"
        "A=M\n"
        "M=D\n"
        "@SP\n"
        "M=M+1\n",
        instruction
    );
  } else if (strcmp(currentCommand->type, "pop") == 0) {
    char instruction[BUFSIZE];
    popValue(currentCommand, instruction);
    sprintf(
        instructionBuffer,
        "%s"
        "@addr\n"
        "M=D\n"
        "@SP\n"
        "M=M-1\n"
        "A=M\n"
        "D=M\n"
        "@addr\n"
        "A=M\n"
        "M=D\n",
        instruction
    );
  } else {
    // Handles logical stack operations
    int operationIdx = getOperationIdx(currentCommand);
    // If the operation is a conditional,
    // then a new instruction is generated alongside
    // a template to keep track of conditional labels
    if (operationIdx == CONDITIONAL) {
      int len = strlen(currentCommand->type);
      char operation[len];
      for (int i = 0; i < len; i++) {
        operation[i] = toupper(currentCommand->type[i]);
      }
      operation[len] = '\0';
      sprintf(
          instructionBuffer,
          "%s"
          "@_%s%d_\n"
          "D;J%s\n"
          "@SP\n"
          "M=M-1\n"
          "A=M\n"
          "A=A-1\n"
          "M=0\n"
          "@_END%d_\n"
          "0;JMP\n"
          "(_%s%d_)\n"
          "@SP\n"
          "M=M-1\n"
          "A=M\n"
          "A=A-1\n"
          "M=-1\n"
          "(_END%d_)\n",
          stackOperations[operationIdx],
          operation,
          condtionalLabelCounter,
          operation,
          condtionalLabelCounter,
          operation,
          condtionalLabelCounter,
          condtionalLabelCounter
      );
      condtionalLabelCounter++;
    } else {
      // Other stack operations are indexed from their table 
      // and copied to the instruction
      sprintf(instructionBuffer, "%s", stackOperations[operationIdx]);
    }
  }
}

void pushValue(command* currentCommand, char* instruction) {
  if (strcmp(currentCommand->memorySegment, "constant") == 0) {
    sprintf(
        instruction, 
        "@%s\n"
        "D=A\n",
        currentCommand->value
    );
  } else if (strcmp(currentCommand->memorySegment, "pointer") == 0) {
    char memSegment[5];
    if (atoi(currentCommand->value) == 0) {
      strcpy(memSegment, "THIS");
    } else {
      strcpy(memSegment, "THAT");
    }
    sprintf(
        instruction,
        "@%s\n"
        "D=M\n",
        memSegment
    );
  } else if (strcmp(currentCommand->memorySegment, "temp") == 0) {
    sprintf(
        instruction,
        "@%s\n"
        "D=A\n"
        "@5\n"
        "A=D+A\n"
        "D=M\n",
        currentCommand->value
    );
  } else if (strcmp(currentCommand->memorySegment, "static") == 0) {
      sprintf(
          instruction,
          "@%s.%s\n"
          "D=M\n",
          fileName, currentCommand->value
    );
  } else {
    char memSegment[5];
    getMemorySegment(currentCommand->memorySegment, memSegment);
    sprintf(
        instruction,
        "@%s\n"
        "D=A\n"
        "@%s\n"
        "A=M\n"
        "A=D+A\n"
        "D=M\n",
        currentCommand->value,
        memSegment
    );
  }
}

void popValue(command* currentCommand, char* instruction) {
  if (strcmp(currentCommand->memorySegment, "pointer") == 0) {
    char memSegment[5];
    if (atoi(currentCommand->value) == 0) {
      strcpy(memSegment, "THIS");
    } else {
      strcpy(memSegment, "THAT");
    }
    sprintf(
        instruction,
        "@%s\n"
        "D=A\n",
        memSegment
    );
  } else if (strcmp(currentCommand->memorySegment, "temp") == 0) {
    sprintf(
        instruction,
        "@%s\n"
        "D=A\n"
        "@5\n"
        "D=D+A\n",
        currentCommand->value
    );
  } else if (strcmp(currentCommand->memorySegment, "static") == 0) {
    sprintf(
        instruction,
        "@%s.%s\n"
        "D=A\n",
        fileName, currentCommand->value
    );
  } else {
    char memSegment[5];
    getMemorySegment(currentCommand->memorySegment, memSegment);
    sprintf(
        instruction,
        "@%s\n"
        "D=A\n"
        "@%s\n"
        "D=D+M\n",
        currentCommand->value,
        memSegment
    );
  }
}

void getMemorySegment(char* memorySegment, char* buffer) {
  int index = 0;
  if (strcmp(memorySegment, "local") == 0) {
    index = LCL;
  } else if (strcmp(memorySegment, "argument") == 0) {
    index = ARG;
  } else if (strcmp(memorySegment, "this") == 0) {
    index = THIS;
  } else if (strcmp(memorySegment, "that") == 0) {
    index = THAT;
  }
  strcpy(buffer, memorySegments[index]);
}

int getOperationIdx(command* currentCommand) {
  int operationIdx = 0;
  if (strcmp(currentCommand->type, "add") == 0) {
    operationIdx = ADD;
  } else if (strcmp(currentCommand->type, "sub") == 0) {
    operationIdx = SUB; 
  } else if (strcmp(currentCommand->type, "neg") == 0) {
    operationIdx = NEG;
  } else if (strcmp(currentCommand->type, "eq") == 0) {
    operationIdx = CONDITIONAL;
  } else if (strcmp(currentCommand->type, "gt") == 0) {
    operationIdx = CONDITIONAL;
  } else if (strcmp(currentCommand->type, "lt") == 0) {
    operationIdx = CONDITIONAL;
  } else if (strcmp(currentCommand->type, "and") == 0) {
    operationIdx = AND;
  } else if (strcmp(currentCommand->type, "or") == 0) {
    operationIdx = OR;
  } else if (strcmp(currentCommand->type, "not") == 0) {
    operationIdx = NOT;
  }
  return operationIdx;
}
