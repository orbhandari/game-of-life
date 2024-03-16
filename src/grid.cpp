#include "grid.h"
#include "../include/raylib.h"

enum CellState {
    DEAD = 0,
    ALIVE = 1
};

void Grid::printCells() {
    for (auto& row : cells) {
        for (auto& column : row) {
            std::cout << column << ' ';
        }
        std::cout << '\n';
    }
};

void Grid::drawCells() {
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            Color color = cells[row][column] == ALIVE ? Color{0, 255, 0, 255} : Color{55, 55, 55, 255};
            DrawRectangle(column * cellSize, row * cellSize, cellSize, cellSize, color);
        }
    }
};