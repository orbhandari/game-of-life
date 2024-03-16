#pragma once

#include <iostream>
#include <vector>

class Grid {
   public:
    Grid(int width, int height, int cellSize)
        : rows(height / cellSize), columns(width / cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)){};

    void printCells();
    void drawCells();
    void setCellValue(int row, int column, int value);
    int getCellValue(int row, int column);
    int getNumRows();
    int getNumColumns();
    bool isWithinBounds(int row, int column);
    void fillRandom();
    void clear();
    void toggleCell(int row, int column);

   private:
    int rows;
    int columns;
    int cellSize;
    std::vector<std::vector<int>> cells;
};