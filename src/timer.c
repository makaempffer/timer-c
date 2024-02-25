#include "timer.h"
#include <stdbool.h> 
#include <stdio.h>
#include "constants.h"

void setupTimer(Timer *timer) {
  printf("[DEBUG] Timer set up\n");
  timer->tick = 0;
  timer->seconds = 0;
  timer->isPaused = false;
}

void toggleTimer(Timer *timer) {
  printf("[DEBUG] Timer toggled: %d\n", timer->isPaused);
  timer->isPaused = !timer->isPaused;
}

void updateCurrentTime(Timer *timer) {
  if (timer->isPaused) return;
  if (timer->tick >= FPS) {    
    printf("[DEBUG] Timer - second elapsed\n");
    timer->seconds++;
    timer->tick = 0;
  }
}

void tick(Timer *timer) {
  if (!timer->isPaused) {
    timer->tick++;
  }
}
