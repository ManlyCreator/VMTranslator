#include <stdio.h>
#include <parser.h>
#include <codeWriter.h>

// TODO: Strip whitespace at the end of a line

#define BUFSIZE 256

int main(int argc, char** argv) {
  if (!argv[1]) {
    printf("Source Filename not Provided\n");
    printf("Usage: ./VMTranslator <filename>\n");
    return 1;
  }

  char destFileName[BUFSIZE];
  if (getFileName(argv[1], destFileName) != 0) {
    printf("Failed to Get Filename, Exiting\n");
    return 2;
  }
  printf("%s\n", destFileName);

  command* commandList = NULL;
  parseFile(argv[1], commandList);
  return 0;
}
