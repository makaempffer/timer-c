#include "raylib.h"
#include <stdbool.h>
#include <stdio.h>
#include "constants.h"
#include "timer.h"
#include "functions.h"
#include "button_data.h"
#include <string.h>

int main(void) {
  InitWindow(800, 600, "raylib [core] example - basic window");
  SetTargetFPS(60);
  Timer timer;
  startTimer(&timer);
  Rectangle rect1 = {100, 100, 100, 50};
  ButtonData button = {"", false, rect1, GREEN, false};

  while (!WindowShouldClose())
  { 
    BeginDrawing();
    updateCurrentTime(&timer);
    ClearBackground(RAYWHITE);
    checkButtonState(&button);
    formatTime(&timer);
    printf("Time: %s", timer.formattedTime);
    strcpy(button.text, timer.formattedTime);
    if (getButtonPressed(&button)) {
      button.color = RED; 
    } else {
      button.color = GREEN;
    }
    drawButton(button);
    DrawText("Congrats! You created your first window!", 180, 200, 20, LIGHTGRAY);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
