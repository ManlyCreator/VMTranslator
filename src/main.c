#include <stdio.h>
#include <parser.h>
#include <codeWriter.h>
#include <string.h>

// TODO: Review video and make next steps

int main(int argc, char** argv) {
  if (!argv[1]) {
    printf("Source Filename not Provided\n");
    printf("Usage: ./VMTranslator <filename>\n");
    return 1;
  }

  // Parses filename and creates the .asm counterpart
  char destFileName[BUFSIZE];
  if (getFileName(argv[1], destFileName) != 0) {
    printf("Invalid Filename Format, Exiting\n");
    return 2;
  }
  // Removes .asm file if it exists
  remove(destFileName);
  // Opens input & output file
  FILE* srcFile = fopen(argv[1], "r");
  FILE* destFile = fopen(destFileName, "w");

  // Stores instructions from src in a linked list
  command* commandList = NULL;
  parseFile(srcFile, &commandList);
  // command* temp = commandList;
  // while (temp->next) {
  //   printf("Command Type: %s\n", temp->type);
  //   printf("Length: %lu\n", strlen(temp->type));
  //   printf("Memory Segment: %s\n", temp->memorySegment);
  //   printf("Length: %lu\n", strlen(temp->memorySegment));
  //   printf("Value: %s\n", temp->value);
  //   printf("Length: %lu\n", strlen(temp->value));
  //   temp = temp->next;
  // }
  translateFile(destFile, commandList);
  fclose(srcFile);
  fclose(destFile);
  return 0;
}
