#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomizeIndex(int current, int total) {
  srand(time(NULL));

  int index;
  do {
    index = rand() % total;
  } while (index == current);

  return index;
}

// TODO: we need to also mix up prioritizing randomly.
int prioritizeSleepTime(int index, int max) { return max / (index + 1); }
