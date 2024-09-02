// 289. Game of Life
// Solved
// Medium
// Topics
// Companies
// According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

// The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

// Any live cell with fewer than two live neighbors dies as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

 

// Example 1:


// Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
// Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
// Example 2:


// Input: board = [[1,1],[1,0]]
// Output: [[1,1],[1,1]]
 

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 25
// board[i][j] is 0 or 1.
 
using namespace std;
#include <iostream>
#include<set>
#include<vector>
class Solution {
public:
    void gameOfLife(vector<vector<int>>& mat) {
        // Sets to track cells that will become 1 or 0 in the next state
        set<pair<int,int>> newOnes;
        set<pair<int,int>> newZeros;

        // Iterate through each cell in the matrix
        for(int r = 0; r < mat.size(); r++) {
            for(int c = 0; c < mat[0].size(); c++) {
                int count = 0;  // Variable to count the number of live neighbors

                // If the current cell is dead (0)
                if(mat[r][c] == 0) {
                    // Check all 8 possible neighbors and count live ones
                    if(r-1 >= 0 && mat[r-1][c] == 1) {
                        count++;
                    }
                    if(c-1 >= 0 && mat[r][c-1] == 1) {
                        count++;
                    }
                    if(r+1 < mat.size() && mat[r+1][c] == 1) {
                        count++;
                    }
                    if(c+1 < mat[0].size() && mat[r][c+1] == 1) {
                        count++;
                    }
                    if(r-1 >= 0 && c+1 < mat[0].size() && mat[r-1][c+1] == 1) {
                        count++;
                    }
                    if(c-1 >= 0 && r+1 < mat.size() && mat[r+1][c-1] == 1) {
                        count++;
                    }
                    if(r+1 < mat.size() && c+1 < mat[0].size() && mat[r+1][c+1] == 1) {
                        count++;
                    }
                    if(c-1 >= 0 && r-1 >= 0 && mat[r-1][c-1] == 1) {
                        count++;
                    }
                    
                    // If the dead cell has exactly 3 live neighbors, it will come to life
                    if(count == 3) {
                        newOnes.insert({r, c});
                    }
                    count = 0;  // Reset count for the next cell
                }

                // If the current cell is alive (1)
                if(mat[r][c] == 1) {
                    // Check all 8 possible neighbors and count live ones
                    if(r-1 >= 0 && mat[r-1][c] == 1) {
                        count++;
                    }
                    if(c-1 >= 0 && mat[r][c-1] == 1) {
                        count++;
                    }
                    if(r+1 < mat.size() && mat[r+1][c] == 1) {
                        count++;
                    }
                    if(c+1 < mat[0].size() && mat[r][c+1] == 1) {
                        count++;
                    }
                    if(r-1 >= 0 && c+1 < mat[0].size() && mat[r-1][c+1] == 1) {
                        count++;
                    }
                    if(c-1 >= 0 && r+1 < mat.size() && mat[r+1][c-1] == 1) {
                        count++;
                    }
                    if(r+1 < mat.size() && c+1 < mat[0].size() && mat[r+1][c+1] == 1) {
                        count++;
                    }
                    if(c-1 >= 0 && r-1 >= 0 && mat[r-1][c-1] == 1) {
                        count++;
                    }
                    
                    // If the live cell has fewer than 2 live neighbors, it dies
                    if(count < 2) {
                        newZeros.insert({r, c});
                        count = 0;
                    }
                    // If the live cell has 2 or 3 live neighbors, it stays alive
                    else if(count == 2 || count == 3) {
                        newOnes.insert({r, c});
                        count = 0;
                    }
                    // If the live cell has more than 3 live neighbors, it dies
                    else if(count > 3) {
                        newZeros.insert({r, c});
                        count = 0;
                    }
                }
            }
        }

        // Update the matrix with the new state based on the computed sets
        for(int rows = 0; rows < mat.size(); rows++) {
            for(int cols = 0; cols < mat[0].size(); cols++) {
                // If the cell is marked to become 0, update it
                if(newZeros.count({rows, cols})) {
                    mat[rows][cols] = 0;
                }
                // If the cell is marked to become 1, update it
                else if(newOnes.count({rows, cols})) {
                    mat[rows][cols] = 1;
                }
            }
        }
    }
};
