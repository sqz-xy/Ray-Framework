#include <game/game.h>
#include <stdio.h>

#include <raylib/raylib.h>

#ifndef RAYGUI_IMPLEMENTATION
#define RAYGUI_IMPLEMENTATION
#include <raylib/raygui.h>
#endif

// Example game state
struct GameState {
    int num;
};

void* initialise() {
    printf("Initialise\n");
    struct GameState *state = malloc(sizeof(struct GameState));
    state->num = 1;
    // Return void ptr to state
    return (void*)state;
}

void update(double dt, void* state) {
    fprintf(stdout, "update: %d\n", ((struct GameState*)state)->num);
    // Cast and update state
    ((struct GameState*)state)->num++;
}

void render(double dt, const void* state) {
    BeginDrawing();
    ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

    DrawText("some basic shapes available on raylib", 20, 20, 20, DARKGRAY);

    // Circle shapes and lines
    DrawCircle(400/5, 120, 35, DARKBLUE);
    EndDrawing();
    fprintf(stdout, "render: %d\n", ((struct GameState*)state)->num);
}

void cleanup(void* state) {
    // Cleanup state
    free((struct GameState*)state);
    printf("Cleanup\n");
}