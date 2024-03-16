#include "simulation.h"

#include "constants.h"

void Simulation::Draw() {
    grid.drawCells();
}

void Simulation::SetCellValue(int row, int column, int value) {
    grid.setCellValue(row, column, value);
}

int Simulation::CountLiveNeighbors(int row, int column) {
    int liveNeighborsCount = 0;
    std::vector<std::pair<int, int>> neighborOffsets = {
        {-1, 0},   // UP
        {1, 0},    // DOWN
        {0, 1},    // RIGHT
        {0, -1},   // LEFT
        {1, 1},    // UP-RIGHT
        {-1, 1},   // DOWN-RIGHT
        {1, -1},   // UP-LEFT
        {-1, -1},  // UP-RIGHT
    };

    for (const auto& offset : neighborOffsets) {
        int neighborRow = (row + offset.first + grid.getNumRows()) % grid.getNumRows();
        int neighborColumn = (column + offset.second + grid.getNumColumns()) % grid.getNumColumns();

        if (grid.getCellValue(neighborRow, neighborColumn) == CELL_STATE::ALIVE) {
            ++liveNeighborsCount;
        }
    }

    return liveNeighborsCount;
}

void Simulation::Update() {
    if (IsRunning()) {
        for (int row = 0; row < grid.getNumRows(); ++row) {
            for (int col = 0; col < grid.getNumColumns(); ++col) {
                int liveNeighborsCount = CountLiveNeighbors(row, col);
                int cellValue = grid.getCellValue(row, col);

                if (cellValue == CELL_STATE::ALIVE) {
                    if (liveNeighborsCount < 2 || liveNeighborsCount > 3) {
                        temp_grid.setCellValue(row, col, CELL_STATE::DEAD);
                    } else {
                        temp_grid.setCellValue(row, col, CELL_STATE::ALIVE);
                    }
                } else {
                    if (liveNeighborsCount == 3) {
                        temp_grid.setCellValue(row, col, CELL_STATE::ALIVE);
                    } else {
                        temp_grid.setCellValue(row, col, CELL_STATE::DEAD);
                    }
                }
            }
        }
        grid = temp_grid;
    }
}

void Simulation::Init() {
    grid.fillRandom();
}

void Simulation::ClearGrid() {
    if (!IsRunning()) {
        grid.clear();
    }
}

void Simulation::CreateRandomState() {
    if (!IsRunning()) {
        grid.fillRandom();
    }
}

void Simulation::ToggleCells(int row, int col) {
    if (!IsRunning()) {
        grid.toggleCell(row, col);
    }
}