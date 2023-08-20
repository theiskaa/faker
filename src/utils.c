#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomizeIndex(int current, int total) {
  int index;
  do {
    index = rand() % total;
  } while (index == current);

  return index;
}

// A sleep time prioritizer/mixer that takes index and maximum value
// of an one-time sleep time, and gets a "random" value, based on
// range of low and high values.
//
// • max / (index + 1) ... (max / (max / (index + 2)))
//
int prioritizeSleepTime(int index, int max) {
  int low = max / (index + 2);
  int high = max / (index + 1);
  return (rand() % (high - low + 1)) + low;
}
