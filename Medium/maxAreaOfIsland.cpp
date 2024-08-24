// 695. Max Area of Island
// Solved
// Medium
// Topics
// Companies
// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid. If there is no island, return 0.

//  Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must be connected 4-directionally.
// Example 2:

// Input: grid = [[0,0,0,0,0,0,0,0]]
// Output: 0
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// grid[i][j] is either 0 or 1.


using namespace std;
#include <iostream>
#include <vector>
#include <queue>
class Solution {
public:
    // Function to calculate the length of an island using BFS
    int lengthOfIsland(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
        int lengthOfIsland = 0; // Variable to store the size of the current island
        queue<pair<int,int>> q; // Queue for BFS traversal
        q.push({x, y}); // Start BFS from the given (x, y) coordinate
        visited[x][y] = 1; // Mark the starting cell as visited

        while (!q.empty()) { // Continue until the queue is empty
            x = q.front().first; // Get the current cell's x-coordinate
            y = q.front().second; // Get the current cell's y-coordinate
            q.pop(); // Remove the current cell from the queue
            lengthOfIsland++; // Increment the island size

            // Check the cell below the current cell
            if (x + 1 >= 0 && x + 1 < grid.size() && !visited[x + 1][y] && grid[x + 1][y] == 1) {
                q.push({x + 1, y}); // Add the cell to the queue
                visited[x + 1][y] = 1; // Mark the cell as visited
            }

            // Check the cell above the current cell
            if (x - 1 >= 0 && x - 1 < grid.size() && !visited[x - 1][y] && grid[x - 1][y] == 1) {
                q.push({x - 1, y}); // Add the cell to the queue
                visited[x - 1][y] = 1; // Mark the cell as visited
            }

            // Check the cell to the right of the current cell
            if (y + 1 >= 0 && y + 1 < grid[0].size() && !visited[x][y + 1] && grid[x][y + 1] == 1) {
                q.push({x, y + 1}); // Add the cell to the queue
                visited[x][y + 1] = 1; // Mark the cell as visited
            }

            // Check the cell to the left of the current cell
            if (y - 1 >= 0 && y - 1 < grid[0].size() && !visited[x][y - 1] && grid[x][y - 1] == 1) {
                q.push({x, y - 1}); // Add the cell to the queue
                visited[x][y - 1] = 1; // Mark the cell as visited
            }
        }
        return lengthOfIsland; // Return the size of the island found
    }

    // Function to find the maximum area of an island in the grid
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxIsland = 0; // Variable to store the maximum island size found
        int currIsland = 0; // Variable to store the current island size during traversal
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), 0)); // 2D visited array

        // Traverse the entire grid
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // If a land cell is found and it is not visited
                if (grid[i][j] == 1 && !visited[i][j]) {
                    // Calculate the size of the island
                    currIsland = lengthOfIsland(grid, visited, i, j);
                    // Update the maximum island size if the current island is larger
                    maxIsland = max(currIsland, maxIsland);
                }
            }
        }
        return maxIsland; // Return the maximum island size found
    }
};
