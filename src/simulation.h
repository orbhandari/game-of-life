#pragma once
#include "grid.h"

class Simulation {
   public:
    Simulation(int width, int height, int cellSize)
        : grid(width, height, cellSize), temp_grid(width, height, cellSize), run(false){};

    void Draw();
    void SetCellValue(int row, int column, int value);
    int CountLiveNeighbors(int row, int column);
    void Init(); /* Fills the grid with random values */
    void Update(); /* Updates the grid if simulation is running */
    bool IsRunning() { return run; };
    void ToggleSimulation() { run = !run; } 
    void ClearGrid();
    void CreateRandomState();
    void ToggleCells(int row, int col);

   private:
    Grid grid;
    Grid temp_grid;
    bool run;
};