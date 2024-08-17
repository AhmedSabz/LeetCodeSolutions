// 45. Jump Game II
// Solved
// Medium
// Topics
// Companies
// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: nums = [2,3,0,1,4]
// Output: 2
 

// Constraints:

// 1 <= nums.length <= 104
// 0 <= nums[i] <= 1000
// It's guaranteed that you can reach nums[n - 1].

using namespace std;
#include <iostream>
#include <vector>
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int jumps=0; // number of minimum jumps to reach the last element
        int currFarthest=0; //the farthest point we can reach with current number of jumps
        int farthest=0; //farthest point we can reach overall
        for(int i=0; i<nums.size()-1;i++){
            farthest=max(farthest,i+nums[i]); 
            if(i ==currFarthest){ // reached the end of our current range
                jumps++;
                currFarthest=farthest;
            }
            if(currFarthest >= nums.size()-1){ //curent end is at last index or beyond
                return jumps;
            }
        }
     return -1;
    }
};