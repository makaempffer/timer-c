#include "raylib.h"
#include <stdbool.h>
#include <stdio.h>
#include "constants.h"
#include "timer.h"
#include "functions.h"
#include "button_data.h"

int main(void) {
  InitWindow(800, 600, "raylib [core] example - basic window");
  SetTargetFPS(FPS);
  Timer timer;
  setupTimer(&timer);
  Rectangle rect1 = {100, 100, 100, 50};
  ButtonData button = {"HOla", false, rect1, BLUE, false};

  while (!WindowShouldClose())
  { 
    BeginDrawing();
    // Timer
    tick(&timer);
    updateCurrentTime(&timer);
    // 
    ClearBackground(RAYWHITE);
    checkButtonState(&button);
    // This line sets the button text to an int.
    sprintf(button.text, "%d", timer.seconds);
  
    // strcpy(button.text, timer.formattedTime);
    if (getButtonPressed(&button)) {
      toggleTimer(&timer);
      button.color = RED; 
    } else {
      button.color = BLUE;
    }
    drawButton(button);
    DrawText("Congrats! You created your first window!", 180, 200, 20, LIGHTGRAY);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
