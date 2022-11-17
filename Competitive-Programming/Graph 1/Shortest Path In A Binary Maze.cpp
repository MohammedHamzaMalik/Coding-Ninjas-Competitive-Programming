/*
Shortest Path In A Binary Maze
Send Feedback
Given a maze in the form of a binary rectangular matrix of size M*N, where each element can either be 0 or 1, the task is to find the length of the shortest path in a maze from a given source cell to a destination cell.
The path can only be created out of a cell if its value is 1 and at any given moment, we can only move one step in one of the four directions. The valid moves are:
Up: (x, y) -> (x - 1, y)
Left: (x, y) -> (x, y - 1)
Down: (x, y) -> (x + 1, y)
Right: (x, y) -> (x, y + 1)
If there is no path from a given source cell to a destination cell, return -1.
For example :
consider the binary matrix below. If source = (0, 0) and destination = (3, 4), the shortest path from source to destination has length 11.
example

Input Format :
The first line of input contains an integer ‘T’ representing the number of test cases. Then the test cases follow.

The first line of each test case contains two space-separated integers M and N, representing the number of rows and columns respectively.

Each of the next M lines contains N space-separated integers representing the matrix.

The last second line of each test case contains two space-separated integers denoting the coordinates of the source cell.

The last line of each test case contains two space-separated integers denoting the coordinates of the destination cell.

For example, the input for the binary matrix depicted in the below image would be:
example

3 4
1 1 1 1
0 1 1 0
0 0 1 1
0 0
2 3
Explanation :
The first line represents that the given matrix has 3 rows and 4 columns.
Each of the next 3 lines contains 4 space-separated integers representing a row.
Last second line contains two space-separated integers representing coordinates of the source cell, i.e. (0, 0).
The last line contains two space-separated integers representing coordinates of the destination cell, i.e. (2, 3).
Output Format :
For each test case, print a single integer denoting the length of the shortest path between a given source cell to a destination cell. If such a path does not exist, print -1.

The output for each test case is in a separate line.
Note :
You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 10
1 <= M, N <= 100

Time Limit: 1sec
Sample Input 1 :
2
3 4
1 1 1 1
0 1 1 0
0 0 1 1
0 0
2 3
2 2
1 1
0 1
0 0
1 1
Sample Output 1 :
5
2
Explanation of Sample Input 1 :
For the first test case, the shortest path between the source cell (0, 0) and destination cell (2,3) is highlighted in the figure below, having a length of 5.
example

For the second test case, the only path from the source cell to the destination cell has a length of 2.
Sample Input 2 :
2
2 2
1 1
1 1
0 1
1 1
2 2
1 0
0 1
0 0
1 1
Sample Output 2 :
1
-1
*/


/*
        Time complexity : O(4 ^ (M * N))
        Space complexity : O(M * N)

        Where M is number of rows and N is number of columns in the matrix
 */

#include <limits.h>

// ROW x COL matrix
int ROW, COL;

// Check if it is possible to go to (x, y) from current position.
bool isSafe(vector<vector<int>> &matrix, int **visited, int x, int y) {
  // Returns false if the cell has value 0 or already visited
  return !(matrix[x][y] == 0 || visited[x][y] != 0);
}

// Check whether given cell (row, col) is a valid cell or not.
bool isValid(int row, int col) {
  // Return true if row number and column number is in range
  return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// Find Shortest Possible Route in the matrix from source cell (0, 0) to
// destination cell (x, y)

// 'min_dist' stores length of longest path from source to destination found so
// far and 'dist' maintains length of path from source cell to the current cell
// (i, j)
int shortestPathBinaryMatrixHelper(vector<vector<int>> &matrix, int **visited,
                                   int i, int j, int x, int y, int min_dist,
                                   int dist) {
  // If destination is found, update min_dist
  if (i == x && j == y) {
    return min(dist, min_dist);
  }

  // Set (i, j) cell as visited
  visited[i][j] = 1;

  // Go to bottom cell
  if (isValid(i + 1, j) && isSafe(matrix, visited, i + 1, j)) {
    min_dist = shortestPathBinaryMatrixHelper(matrix, visited, i + 1, j, x, y,
                                              min_dist, dist + 1);
  }

  // Go to right cell
  if (isValid(i, j + 1) && isSafe(matrix, visited, i, j + 1)) {
    min_dist = shortestPathBinaryMatrixHelper(matrix, visited, i, j + 1, x, y,
                                              min_dist, dist + 1);
  }

  // Go to top cell
  if (isValid(i - 1, j) && isSafe(matrix, visited, i - 1, j)) {
    min_dist = shortestPathBinaryMatrixHelper(matrix, visited, i - 1, j, x, y,
                                              min_dist, dist + 1);
  }

  // Go to left cell
  if (isValid(i, j - 1) && isSafe(matrix, visited, i, j - 1)) {
    min_dist = shortestPathBinaryMatrixHelper(matrix, visited, i, j - 1, x, y,
                                              min_dist, dist + 1);
  }

  // Backtrack - Remove (i, j) from visited matrix
  visited[i][j] = 0;

  return min_dist;
}

int shortestPathBinaryMatrix(vector<vector<int>> &matrix, pair<int, int> src,
                             pair<int, int> dest) {
  ROW = matrix.size();
  COL = matrix[0].size();

  // Check source and destination cell of the matrix have value 1
  if (matrix[src.first][src.second] != 1 ||
      matrix[dest.first][dest.second] != 1) {
    return -1;
  }

  int **visited = new int *[ROW];
  for (int i = 0; i < ROW; ++i) {
    visited[i] = new int[COL];
  }

  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      visited[i][j] = 0;
    }
  }

  int min_dist =
      shortestPathBinaryMatrixHelper(matrix, visited, src.first, src.second,
                                     dest.first, dest.second, INT_MAX, 0);

  // If min_dist doesn't change
  if (min_dist == INT_MAX) {
    return -1;
  }
  return min_dist;
}
