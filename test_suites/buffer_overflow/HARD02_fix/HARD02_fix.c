/*
 * Based on CVE-2022-26768 (fixed)
 */
#include "HARD02_fix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char initialLogFileName[FILENAMESIZE] = "";

void EXPORT_CALL lou_logFile(const char *fileName) {
  if (fileName == NULL || fileName[0] == 0 || strlen(fileName) >= FILENAMESIZE)
    return;
  if (initialLogFileName[0] == 0)
    strcpy(initialLogFileName, fileName);
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
  char *fileName = malloc(sz + 1);
  memset(fileName, 's', sz);
  fileName[sz] = '\0';
  lou_logFile(fileName);
  free(fileName);
}
