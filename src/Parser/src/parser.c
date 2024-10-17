#include <ctype.h>
#include <parser.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 256

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

void parseFile(char* filename, command* head) {
  FILE* src = fopen(filename, "r");
  char line[BUFSIZE];
  while (fgets(line, BUFSIZE, src)) {
    if (!isInstructionChar(line[0])) {
      continue;
    }
    strip(line);
    printf("%s\n", line);
    printf("Length: %lu\n", strlen(line));
  }
}

void strip(char* line) {
  int i = 0;
  int k = 0;
  int len = strlen(line);
  char temp[len];
  while (isspace(line[i])) {
    i++;
  }
  for (int j = i;
      k < len - i &&
      isInstructionChar(line[j]);
      j++, k++
      ) 
  {
    temp[k] = line[j]; 
  } 
  temp[k] = '\0';
  strcpy(line, temp);
}

int isInstructionChar(char c) {
  if (c == '\n' || c == '\r' || c == '/') {
    return 0;
  }
  return 1;
}
