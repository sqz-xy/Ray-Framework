#include <stdio.h>
#include <game/game.h>

#include <raylib/raylib.h>

int main(int argc, char *argv[]) {
   InitWindow(600, 400, "Framework Window!");
   SetTargetFPS(60);

   void* state = initialise();
   while (!WindowShouldClose())
   {
      update(GetFrameTime(), state);
      render(GetFrameTime(), state);
   }
   cleanup(state);
   CloseWindow();
}
