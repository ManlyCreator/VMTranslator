#include <codeWriter.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: Fix file name parsing so that the whole path name is included, omitting slashes


char memorySegments[4][BUFSIZE] = { "LCL", "ARG", "THIS", "THAT" };

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
  // [3] CONDITIONAL
  {
    "@SP\n"
    "A=M\n"
    "A=A-1\n"
    "D=M\n"
    "A=A-1\n"
    "D=M-D\n"
  },
  // [4] AND
  {
    "@SP\n"
    "A=M\n"
    "A=A-1\n"
    "D=M\n"
    "A=A-1\n"
    "D=D&M\n"
    "M=D\n"
    "@SP\n"
    "M=M-1\n"
  },
  // [5] OR
  {
    "@SP\n"
    "A=M\n"
    "A=A-1\n"
    "D=M\n"
    "A=A-1\n"
    "D=D|M\n"
    "M=D\n"
    "@SP\n"
    "M=M-1\n"
  },
  // [6] NOT
  {
    "@SP\n"
    "A=M\n"
    "A=A-1\n"
    "M=!M\n"
  }
};

char fileName[BUFSIZE];

void translateFile(FILE* dest, char* destName, command* listStart) {
  // Parses the file's name
  for (int i = 0; i < strlen(destName) - 4; i++) {
    if (destName[i] == '/') {
      continue;
    }
    fileName[i] = destName[i];
  }
  fileName[strlen(destName) - 4] = '\0';
  command* temp = listStart;
  int instructionCounter = 0;
  while (temp->next) {
    instructionCounter++;
    char instruction[BUFSIZE];
    translateCommand(instruction, temp, instructionCounter);
    fprintf(
        dest,
        "// %s %s %s\n"
        "%s", 
        temp->type, temp->memorySegment, temp->value, instruction
    );
    temp = temp->next;
  }
}

void translateCommand(char* instructionBuffer, command* currentCommand, int instructionNumber) {
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
          "@%s%d\n"
          "D;J%s\n"
          "@SP\n"
          "M=M-1\n"
          "A=M\n"
          "A=A-1\n"
          "M=0\n"
          "@END%d\n"
          "0;JMP\n"
          "(%s%d)\n"
          "@SP\n"
          "M=M-1\n"
          "A=M\n"
          "A=A-1\n"
          "M=-1\n"
          "(END%d)\n",
          stackOperations[operationIdx],
          operation,
          instructionNumber,
          operation,
          instructionNumber,
          operation,
          instructionNumber,
          instructionNumber
      );
    } else {
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
