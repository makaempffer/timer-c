#include "timer.h"
#include "raylib.h"
#include <stdbool.h> 
#include <stdio.h>

double getElapsedTimeSeconds(Timer *timer) {  
  return timer->currentTime - timer->startTime;
}

void startTimer(Timer *timer) {
  printf("[DEBUG] Timer started\n");
  // Call this function ONCE to start timer.
  timer->startTime = GetTime();
}

void toggleTimer(Timer *timer) {
  timer->isPaused = !timer->isPaused;
}

void updateCurrentTime(Timer *timer) {
  timer->currentTime = GetTime();
}

void formatTime(Timer *timer) {
  sprintf(timer->formattedTime, "%d", (int) timer->elapsedTime);
}
