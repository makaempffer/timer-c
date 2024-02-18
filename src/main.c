#include "raylib.h"
#include <stdio.h>
#include <stdbool.h>
#include "constants.h"

typedef struct {
  char* text;
  bool isPressed;
  Rectangle rect;
  Color color;
  bool isHovered;
} ButtonData;

bool checkCollisionPointRec(Vector2 point, Rectangle rect) {
  return (point.x >= rect.x && point.x <= (rect.x + rect.width) &&
          point.y >= rect.y && point.y <= (rect.y + rect.height));
}

void drawButton(ButtonData data) {
  DrawRectangle(data.rect.x, data.rect.y, data.rect.width, data.rect.height, data.color);
  DrawText(data.text, data.rect.x + (data.rect.width / 3) - FONT_SIZE, data.rect.y + (data.rect.height / 2.0) - FONT_SIZE / 2.0, FONT_SIZE, WHITE);
}

void checkButtonState(ButtonData *button) { 
  Vector2 mousePos = GetMousePosition();
  bool isButtonHovered = checkCollisionPointRec(mousePos, button->rect);
  button->isHovered = isButtonHovered;
  if (button->isHovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    printf("Button Was Pressed!:%d\n", isButtonHovered);
  }
}

int main(void) {
  InitWindow(800, 600, "raylib [core] example - basic window");
  SetTargetFPS(60);
  Rectangle rect1 = {100, 100, 100, 50};
  ButtonData button = {"Hello World", false, rect1, GREEN, false};

  while (!WindowShouldClose())
  { 
    BeginDrawing();
    ClearBackground(RAYWHITE);
    checkButtonState(&button);
    drawButton(button);
    DrawText("Congrats! You created your first window!", 180, 200, 20, LIGHTGRAY);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
