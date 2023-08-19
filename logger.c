#include <stdio.h>

void logSystem(char *app, int index, int sleepTime) {
  printf("> moving to: %s | index {%d} | sleep time {%d}s\n", app, index,
         sleepTime);
}
