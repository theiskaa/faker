#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// TODO: take apps from arguments.
// TODO: generate sleep duration based on order of apps.

int randomizeIndex(int current, int total) {
  srand(time(NULL));

  int index;
  do {
    index = rand() % total;
  } while (index == current);

  return index;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <app-1> <app-2> ... <app-N>\n", argv[0]);
    return 1;
  }

  int length = argc - 1;
  char **apps = &argv[1];

  int previous = 0;
  while (1) {
    int index = randomizeIndex(previous, length);
    previous = index;

    char command[256];
    snprintf(command, sizeof(command), "open -a \"%s\"", apps[index]);

    printf("> moving to::%d -> %s\n", index, apps[index]);
    system(command);

    sleep(10);
  }

  return 0;
}
