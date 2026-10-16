#include <vector>
#include <assert.h>
#include <iostream>
#include "Position.hpp"
#include <set>

/*
 * To analyze satellite images, a geospatial company studies maps of remote ocean regions.
 * Each map is represented as a grid where land and water are identified.
 *
 * Your task is to determine how many separate islands are present on a given map.
 * The map is represented as a 2D grid of characters :
 *    - '1' represents land
 *    - '0' represents water
 *
 * An island is defined as a group of connected land cells.
 * Cells are considered connected if they are adjacent horizontally or vertically(not diagonally).
 * The grid is surrounded by water.
 * 
 * Implement the function count_islands which returns the total number of islands present in the map.
 */

void checkNeighbor(Position pos, std::vector<std::vector<char>>& grid, std::set<Position>& allPos, std::set<Position>& alreadyCheckPos) {
    std::vector<Position> offsets = { Position(1,0),Position(0,1), Position(-1,0), Position(0,-1) };
    for (Position offset : offsets) {
        Position neighbor = pos + offset;
        if (allPos.find(neighbor) == allPos.end()) continue;
        if (alreadyCheckPos.find(neighbor) == alreadyCheckPos.end()) {
            alreadyCheckPos.insert(neighbor);
            if (grid[neighbor.x][neighbor.y] == '1') {
                checkNeighbor(neighbor, grid, allPos, alreadyCheckPos);
            }
        }
    }
}

int count_islands(std::vector<std::vector<char>>& grid)
{
    int nmbIslands = 0;
    std::set<Position> allPos;
    std::set<Position> alreadyCheckPos;

    for (int x = 0; x < grid.size(); x++)
        for (int y = 0; y < grid[0].size(); y++)
            allPos.insert(Position(x, y));

    for (Position pos : allPos) {

        if (alreadyCheckPos.find(pos) == alreadyCheckPos.end()){
            alreadyCheckPos.insert(pos);
            if (grid[pos.x][pos.y] == '1') {
                nmbIslands++;
                checkNeighbor(pos, grid, allPos, alreadyCheckPos);
            }
        }
    }

	return nmbIslands;
}

int main()
{
    {
        std::vector<std::vector<char>> grid = {
            {'1','1','0','0'},
            {'1','1','0','0'},
            {'0','0','1','0'},
            {'0','0','0','1'}
        };
        std::cout << count_islands(grid) << std::endl;
    }
    {
        std::vector<std::vector<char>> grid = {
            {'1','1','0','0'},
            {'1','1','0','0'},
            {'0','0','1','0'},
            {'0','0','0','1'}
        };
        assert(count_islands(grid) == 3);
    }

    return 0;
}