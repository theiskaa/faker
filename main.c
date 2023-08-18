#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// TODO: take apps from arguments.
// TODO: generate sleep duration based on order of apps.
char *apps[] = {"Alacritty", "Safari", "Discord"};

int randomizeIndex(int current) {
  int index;
  do {
    index = rand() % (sizeof(apps) / sizeof(apps[0]));
  } while (index == current);

  return index;
}

int main() {
  srand(time(NULL));

  int previous = 0;
  while (1) {
    int index = randomizeIndex(previous);
    previous = index;

    char command[256];
    snprintf(command, sizeof(command), "open -a \"%s\"", apps[index]);

    printf("> moving to::%d -> %s\n", index, apps[index]);
    system(command);

    sleep(10);
  }

  return 0;
}
