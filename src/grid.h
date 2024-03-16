#pragma once

#include <iostream>
#include <vector>

class Grid {
   public:
    Grid(const int& width, const int& height, const int& cellSize)
        : rows(height / cellSize), columns(width / cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)){};

    void printCells();
    void drawCells();

   private:
    const int rows;
    const int columns;
    const int cellSize;
    std::vector<std::vector<int> > cells;
};