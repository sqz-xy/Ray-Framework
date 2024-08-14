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
    struct Player {
        Camera3D player_cam;
        Vector3 player_pos;
        float player_speed;
    } player;
    int num;
};

void* initialise() {
    printf("Initialise\n");
    SetWindowTitle("Video jame!");
    DisableCursor();

    struct GameState *state = malloc(sizeof(struct GameState));
    state->player.player_pos = (Vector3){ 0.0f, 0.0f, 0.0f };   
    state->player.player_speed = 3.0f;

    state->num = 1;
    state->player.player_cam.position = (Vector3){ 
        state->player.player_pos.x, 
        state->player.player_pos.y + 20.0f, 
        state->player.player_pos.z + 0.1f }; 

    state->player.player_cam.target = (Vector3){ 0.0f, 0.0f, 0.0f };      
    state->player.player_cam.up = (Vector3){ 0.0f, 1.0f, 0.0f };          
    state->player.player_cam.fovy = 45.0f;                                
    state->player.player_cam.projection = CAMERA_PERSPECTIVE;    

    // Return void ptr to state
    return (void*)state;
}

void update(double dt, void* state) {
    // Cast and update state
    struct GameState* game_state = (struct Gamestate*)state;
    fprintf(stdout, "update: %d\n", game_state->num);
    
    game_state->num++;

    if (IsKeyDown('W')) {
        game_state->player.player_pos.z -= game_state->player.player_speed * dt;
    } 
    if (IsKeyDown('S')) {
        game_state->player.player_pos.z += game_state->player.player_speed * dt;
    }  
    if (IsKeyDown('A')) {
        game_state->player.player_pos.x -= game_state->player.player_speed * dt;
    }  
    if (IsKeyDown('D')) {
        game_state->player.player_pos.x += game_state->player.player_speed * dt;
    }
    
    game_state->player.player_cam.position = (Vector3) { 
        game_state->player.player_pos.x, 
        game_state->player.player_pos.y + 20.0f, 
        game_state->player.player_pos.z + 0.1f }; 
    game_state->player.player_cam.target = game_state->player.player_pos;
}

void render(double dt, const void* state) {
    const struct GameState* game_state = (struct Gamestate*)state;
    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    BeginDrawing();

    ClearBackground(RAYWHITE);

    BeginMode3D(game_state->player.player_cam);

    DrawCylinder(game_state->player.player_pos, 1.0f, 1.0f, 3.0f, 100, RED);

    DrawGrid(10, 1.0f);

    EndMode3D();

    DrawRectangle( 10, 10, 100, 33, Fade(SKYBLUE, 0.5f));
    DrawRectangleLines( 10, 10, 100, 33, BLUE);

    DrawText(TextFormat("FPS: %.2f", 1.0f/dt), 40, 20, 10, DARKGRAY);

    EndDrawing();
    fprintf(stdout, "render: %d\n", ((struct GameState*)state)->num);
}

void cleanup(void* state) {
    // Cleanup state
    free((struct GameState*)state);
    printf("Cleanup\n");
}