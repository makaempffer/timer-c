#ifndef TIMER_H
#define TIMER_H
#include <stdbool.h>

typedef struct {
  int seconds;
  bool isPaused;
  int tick;
} Timer;

void toggleTimer(Timer *timer);
void updateCurrentTime(Timer *timer); // Sets current time to the variable
void tick(Timer *timer);
void setupTimer(Timer *timer);
#endif

