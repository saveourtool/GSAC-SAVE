/*
 * Based on CVE-2022-26768
 */
#include "HARD02.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char initialLogFileName[FILENAMESIZE] = "";

void EXPORT_CALL lou_logFile(const char *fileName) {
  if (fileName == NULL || fileName[0] == 0)
    return;
  if (initialLogFileName[0] == 0)
    // Size of 'fileName' is greater than 'FILENAMESIZE'
    strcpy(initialLogFileName, fileName); // buffer-overflow
  logFile = fopen(fileName, "a");
  if (logFile == NULL && initialLogFileName[0] != 0)
    logFile = fopen(initialLogFileName, "a");
  if (logFile == NULL) {
    fprintf(stderr, "Cannot open log file %s\n", fileName);
    logFile = stderr;
  }
}

int main() {
  const int sz = 260;
  char *fileName = malloc(sz + 1); // Allocate 261 bytes of memory
  memset(fileName, 's', sz);
  fileName[sz] = '\0';
  lou_logFile(fileName);
  free(fileName);
}
