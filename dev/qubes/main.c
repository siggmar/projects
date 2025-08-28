#include "raylib.h"

#define MAX_RECT 10

const int screenWidth = 800;
const int screenHeight = 450;

struct cube {
    int x, y, w, h;
    Color c;
};

struct cube cubes[MAX_RECT];

void grid() {}

int main(void) {

  InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

  SetTargetFPS(60);

  Color qube_color = {255, 0, 0, 255};

  for (int i = 0; i <= MAX_RECT; i++) {
      cubes[i].x
  };

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update

    BeginDrawing();

    ClearBackground(BLACK);
    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}
