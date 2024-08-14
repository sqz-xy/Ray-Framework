#include <game/game.h>
#include <stdio.h>

#include <raylib/raylib.h>

#ifndef RAYGUI_IMPLEMENTATION
#define RAYGUI_IMPLEMENTATION
#include <raylib/raygui.h>
#endif

#define GRID_WIDTH 10
#define GRID_HEIGHT 10

// Example game state
struct GameState {
    Camera3D camera;
    int num;
};

void* initialise() {
    printf("Initialise\n");
    SetWindowTitle("Video jame!");
    DisableCursor();

    struct GameState *state = malloc(sizeof(struct GameState));
    state->num = 1;
    state->camera.position = (Vector3){ 0.0f, 20.0f, 0.1f }; 
    state->camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      
    state->camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          
    state->camera.fovy = 45.0f;                                
    state->camera.projection = CAMERA_PERSPECTIVE;            
     

    // Return void ptr to state
    return (void*)state;
}

void update(double dt, void* state) {
    // Cast and update state
    struct GameState* game_state = (struct Gamestate*)state;
    fprintf(stdout, "update: %d\n", game_state->num);
    
    game_state->num++;
    UpdateCamera(&game_state->camera, CAMERA_PERSPECTIVE);
    
    if (IsKeyPressed('Z')){
        game_state->camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    }
}

void render(double dt, const void* state) {
    const struct GameState* game_state = (struct Gamestate*)state;
    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    BeginDrawing();

    ClearBackground(RAYWHITE);

    BeginMode3D(game_state->camera);

    DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
    DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

    DrawGrid(10, 1.0f);

    EndMode3D();

    DrawRectangle( 10, 10, 320, 113, Fade(SKYBLUE, 0.5f));
    DrawRectangleLines( 10, 10, 320, 113, BLUE);

    DrawText("Free camera default controls:", 20, 20, 10, BLACK);
    DrawText("- Mouse Wheel to Zoom in-out", 40, 40, 10, DARKGRAY);
    DrawText("- Mouse Wheel Pressed to Pan", 40, 60, 10, DARKGRAY);
    DrawText("- Z to zoom to (0, 0, 0)", 40, 80, 10, DARKGRAY);
    DrawText(TextFormat("FPS: %.2f", 1.0f/dt), 40, 100, 10, DARKGRAY);

    EndDrawing();
    fprintf(stdout, "render: %d\n", ((struct GameState*)state)->num);
}

void cleanup(void* state) {
    // Cleanup state
    free((struct GameState*)state);
    printf("Cleanup\n");
}