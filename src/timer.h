#ifndef TIMER_H
#define TIMER_H
#include <stdbool.h>

typedef struct {
  double startTime;
  double currentTime;
  double elapsedTime;
  bool isPaused;
  char formattedTime[8];
} Timer;

double getElapsedTimeSeconds(Timer *timer); // Returns the elapsed time in seconds.
void startTimer(Timer *timer);
void toggleTimer(Timer *timer);
void updateCurrentTime(Timer *timer); // Sets current time to the variable
void formatTime(Timer *timer);
#endif

