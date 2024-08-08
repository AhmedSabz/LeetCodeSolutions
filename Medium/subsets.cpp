// 78. Subsets
// Solved
// Medium
// Topics
// Companies
// Given an integer array nums of unique elements, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 
//  Code:
using namespace std;
#include <iostream>
#include <vector>

 class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;  // This vector will store all the subsets.
        vector<int> path;         // Temporary vector to store the current subset being constructed.
        
        // Start the backtracking process from index 0
        backtrack(0, path, ret, nums);
        
        return ret;  // Return the final list of subsets.
    }
    
    // Helper function to perform the backtracking
    void backtrack(int start, vector<int>& path, vector<vector<int>>& ret, vector<int>& nums) {
        ret.push_back(path);  // Add the current subset to the result vector.

        // Iterate through the elements starting from the current index
        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);  // Include nums[i] in the current subset.
            
            // Recursively call backtrack with the next index (i + 1)
            backtrack(i + 1, path, ret, nums);
            
            path.pop_back();  // Remove the last element to backtrack and explore other subsets.
        }
    }
};
