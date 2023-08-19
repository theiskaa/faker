#include "logger.c"
#include "utils.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Default max sleep time is [2m 45s].
// TODO: we should also take this from outside.
int MAX_SLEEP_TIME = 165;

int runCommand(int argc, char *argv[]) {
  int length = argc - 1;
  char **apps = &argv[1];

  int previous = 0;
  while (1) {
    int index = randomizeIndex(previous, length);
    previous = index;
    int sleepTime = prioritizeSleepTime(index, MAX_SLEEP_TIME);

    char command[256];
    snprintf(command, sizeof(command), "open -a \"%s\"", apps[index]);

    logSystem(apps[index], index, sleepTime);

    system(command);
    sleep(sleepTime);
  }

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <app-1> <app-2> ... <app-N>\n", argv[0]);
    return 1;
  }

  return runCommand(argc, argv);
}
