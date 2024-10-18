#include <ctype.h>
#include <parser.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getFileName(char* srcFileName, char* destFileName) {
  int i = 0;
  int len = strlen(srcFileName);
  // Checks for valid file extension
  if (srcFileName[len - 2] != 'v' && srcFileName[len - 1] != 'm') {
    printf("File Extension not Recognized\n");
    return 1;
  }
  // Copies src to dest, omitting the extension
  while (i < len - 2) {
    destFileName[i] = srcFileName[i];
    i++;
  }
  destFileName[i] = '\0';
  // Appends "asm" to dest
  strcat(destFileName, "asm");
  return 0;
}

void parseFile(FILE* src, command** listStart) {
  char line[BUFSIZE];
  command* listPtr = malloc(sizeof(command));
  while (fgets(line, BUFSIZE, src)) {
    if (!isInstructionChar(line[0])) {
      continue;
    }
    strip(line);
    // Command Argument Parsing
    int lineIdx = 0;
    for (int i = 0; i < 3; i++) {
      int argIdx = 0;
      while (lineIdx < strlen(line) && !isspace(line[lineIdx])) {
        switch (i) {
          case 0:
            listPtr->type[argIdx] = line[lineIdx];
            break;
          case 1:
            listPtr->memorySegment[argIdx] = line[lineIdx];
            break;
          case 2:
            listPtr->value[argIdx] = line[lineIdx];
            break;
        }
        lineIdx++;
        argIdx++;
      }
      // Increments past whitespace
      lineIdx++;
    }
    // Linked List Logic
    if (*listStart == NULL) {
      *listStart = listPtr;
    }  
    listPtr->next = malloc(sizeof(command));
    listPtr = listPtr->next;
  }
}

void strip(char* line) {
  int i = 0;
  int k = 0;
  int whitespaceCounter = 0;
  int len = strlen(line);
  char temp[len];
  while (isspace(line[i])) {
    i++;
  }
  for (int j = i; k < len - i && isInstructionChar(line[j]); j++, k++) {
    if (isspace(line[j])) {
      whitespaceCounter++;
    } else {
      whitespaceCounter = 0;
    }
    temp[k] = line[j]; 
  } 
  temp[k - whitespaceCounter] = '\0';
  strcpy(line, temp);
}

int isInstructionChar(char c) {
  if (c == '\n' || c == '\r' || c == '/') {
    return 0;
  }
  return 1;
}
