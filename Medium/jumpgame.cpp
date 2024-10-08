// 55. Jump Game
// Solved
// Medium
// Topics
// Companies
// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

 

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

// Constraints:

// 1 <= nums.length <= 104
// 0 <= nums[i] <= 10
using namespace std;
#include <iostream>
#include <vector>
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;

        // Check if the current index i can reach or exceed the goal.
        // If so, update the goal to the current index i.
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }
        
        // If the goal has been updated to 0, it means we can reach the last index from the first index.
        // Return true if the goal is 0, otherwise false.
        return goal == 0;        
    }
};