// 128. Longest Consecutive Sequence
// Solved
// Medium
// Topics
// Companies
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

 

// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
 

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
using namespace std;
#include <iostream>
#include<unordered_set>
#include<vector>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end()); // Initialize the set with all elements
        int maxSize = 0;

        for (int num : nums) {
            // Assume 'num' is the largest number in the subsequence
            if (!s.count(num + 1)) {
                int currentNum = num;
                int currSize = 1;
                
                // Count the consecutive numbers downwards
                while (s.count(currentNum - 1)) {
                    currentNum--;
                    currSize++;
                    s.erase(currentNum+1);
                }
                
                // Update the maximum size
                maxSize = max(maxSize, currSize);
            }
        }
        
        return maxSize;
    }
};