#include "grid.h"

#include "../include/raylib.h"
#include "constants.h"

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
            Color color = cells[row][column] == CELL_STATE::ALIVE ? Color{0, 255, 0, 255} : Color{55, 55, 55, 255};
            DrawRectangle(column * cellSize, row * cellSize, cellSize - 1, cellSize - 1, color);
        }
    }
}

bool Grid::isWithinBounds(int row, int column) {
    if (row < 0 || row > rows || column < 0 || column > columns) {
        std::cout << "Cell out of bounds!\n";
        return false;
    }
    return true;
}

void Grid::setCellValue(int row, int column, int value) {
    if (isWithinBounds(row, column)) {
        cells[row][column] = value;
    } else {
        std::cout << "Cell value not modified.\n!";
    }
};

int Grid::getCellValue(int row, int column) {
    if (isWithinBounds(row, column)) {
        return cells[row][column];
    }
    return 0;
}

int Grid::getNumRows() {
    return rows;
}

int Grid::getNumColumns() {
    return columns;
}

void Grid::fillRandom() {
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            cells[row][column] = GetRandomValue(0, 4) == 4 ? CELL_STATE::ALIVE : CELL_STATE::DEAD;
        }
    }
}

void Grid::clear() {
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            cells[row][column] = 0;
        }
    }
}

void Grid::toggleCell(int row, int column) {
    if (isWithinBounds(row, column)) {
        cells[row][column] = !cells[row][column];
    }
}