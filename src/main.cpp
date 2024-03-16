#include <iostream>

#include "../include/raylib.h"
#include "simulation.h"

int main() {
    Color GREY = {29, 29, 29, 255};

    /* PX */
    const int WINDOW_WIDTH{1000};
    const int WINDOW_HEIGHT{750};
    const int CELL_SIZE{4};

    int FPS = 12;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);

    Simulation simulation(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);
    simulation.Init();

    /* Simulation loop */
    while (!WindowShouldClose()) {
        /* 1. Event handling */
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Vector2 mousePosition = GetMousePosition();
            int row = mousePosition.y / CELL_SIZE;
            int column = mousePosition.x / CELL_SIZE;
            simulation.ToggleCells(row, column);
        }
        if (IsKeyPressed(KEY_P)) {
            simulation.ToggleSimulation();
            SetWindowTitle(simulation.IsRunning() ? "Running..." : "Stopped!");
        } else if (IsKeyPressed(KEY_UP)) {
            FPS += 1;
            SetTargetFPS(FPS);

        } else if (IsKeyPressed(KEY_DOWN)) {
            /* Set minimum FPS as window becomes too unresponsive at low FPS */
            if (FPS > 5) {
                FPS -= 1;
                SetTargetFPS(FPS);
            }
        } else if (IsKeyPressed(KEY_C)) {
            simulation.ClearGrid();
        } else if (IsKeyPressed(KEY_R)) {
            simulation.CreateRandomState();
        }

        /* 2. Updating state */
        simulation.Update();

        /* 3. Draw objects */
        BeginDrawing();
        ClearBackground(GREY);
        simulation.Draw();
        EndDrawing();
    }

    return 0;
}
