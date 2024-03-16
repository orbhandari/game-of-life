#include "../include/raylib.h"
#include "grid.h"

int main() {
    Color GREY = {29, 29, 29, 255};

    /* PX */
    const int WINDOW_WIDTH{750};
    const int WINDOW_HEIGHT{750};
    const int CELL_SIZE{25};

    int FPS = 12;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);

    Grid gameGrid =  Grid(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);
    gameGrid.printCells(); 
    gameGrid.drawCells(); 

    /* Simulation loop */
    while (!WindowShouldClose()) {
        /* 1. Event handling */
        /* 2. Updating state */
        /* 3. Draw objects */

        BeginDrawing();
        ClearBackground(GREY);
        gameGrid.drawCells();
        EndDrawing();
    }

    return 0;
}
