/**
 * Project Euler p15
 *
 * Starting in the top left corner of a 2×2 grid, and only being able to move 
 *  to the right and down, there are exactly 6 routes to the bottom right 
 *  corner. How many such routes are there through a 20×20 grid? 
 */

#include "graph.h"
#include <iostream>

int main(int argc, char** argv) {

  const int MAX_COLUMNS = 4;
  const int MAX_ROWS = 4;

  Graph graph;  
  node_handle grid[MAX_COLUMNS][MAX_ROWS];

  // Construct 20x20 grid.
  for (unsigned int x = 0; x < MAX_COLUMNS; x++) {
    for (unsigned int y = 0; y < MAX_ROWS; y++) {

      // Create new node.
      node_handle newNode = graph.addNode();
      grid[x][y] = newNode;

    }
  }

  // Add adjacencies to grid.
  for (int x = 0; x < MAX_COLUMNS; x++) {
    for (int y = 0; y < MAX_ROWS; y++) {

      /*
      if ((x - 1) >= 0)
        graph.addAdjacency(grid[x][y], grid[x - 1][y]);
        */
      if ((x + 1) < (MAX_COLUMNS))
        graph.addAdjacency(grid[x][y], grid[x + 1][y]);
      /*
      if ((y - 1) >= 0)
        graph.addAdjacency(grid[x][y], grid[x][y - 1]);
        */
      if ((y + 1) < (MAX_ROWS))
        graph.addAdjacency(grid[x][y], grid[x][y + 1]);

    }
  }

  graph.printAdjList();

  std::cout << "count: " << graph.countPaths() << std::endl;

}
