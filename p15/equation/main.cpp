#include <iostream>

int main(int argc, char** argv) {
  const int COLUMNS = 21;
  const int ROWS = 21;

  long grid[COLUMNS][ROWS];

  // Initialize edge nodes to have 1 path.
  for (int y = 0; y < ROWS; y++)
    grid[0][y] = 1;
  for (int x = 0; x < COLUMNS; x++)
    grid[x][0] = 1;

  for (int x = 1; x < COLUMNS; x++) {
    for (int y = 1; y < ROWS; y++) {
      grid[x][y] = grid[x - 1][y] + grid[x][y - 1];
      /*
      std::cout << "grid[" << x << "][" << y << "] = " << grid[x][y] << std::endl;
      std::cout << " grid[" << x - 1 << "][" << y << "] = " << grid[x - 1][y] << std::endl;
      std::cout << " grid[" << x << "][" << y - 1 << "] = " << grid[x][y - 1] << std::endl;
      */
    }
  }

  std::cout << "count: " << grid[COLUMNS - 1][ROWS - 1] << std::endl;

  return 0;
}
