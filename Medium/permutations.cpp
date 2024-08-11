// 46. Permutations
// Solved
// Medium
// Topics
// Companies
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]
 

// Constraints:

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.


using namespace std;
#include <iostream>
#include <vector>
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> inter; // Temporary vector to store the current permutation
        vector<bool> used(nums.size(), false); // Boolean vector to track which elements are used, initialized to 'false'
        vector<vector<int>> ret; // Result vector to store all permutations
        solve(nums, inter, ret, used); // Start the backtracking process
        return ret; // Return all possible permutations
    }

    void solve(vector<int>& nums, vector<int>& inter, vector<vector<int>>& ret, vector<bool>& used) {
        // Base case: if the current permutation has the same size as nums
        if (inter.size() == nums.size()) {
            ret.push_back(inter); // Add the current permutation to the result
            return;
        }
        
        // Loop through all elements in nums
        for (int i = 0; i < nums.size(); i++) {
            // If the element is not yet used in the current permutation
            if (!used[i]) {
                used[i] = true; // Mark it as used
                inter.push_back(nums[i]); // Add it to the current permutation
                solve(nums, inter, ret, used); // Recur to build the next part of the permutation
                used[i] = false; // Backtrack: unmark the element as used
                inter.pop_back(); // Backtrack: remove the last element added and try the next one
            }
        }
    }
};
