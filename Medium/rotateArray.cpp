// 189. Rotate Array
// Solved
// Medium
// Topics
// Companies
// Hint
// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// Example 2:

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]

// code:
using namespace std;
#include <iostream>
#include <vector>

class Solution {
public:
    void rotate(vector<int>& nums, int k) {// reverse whole array
                // 2,3 k =3                           //reverse 0 to k-1
                // 3 ,2                           // reverse k to n-1
        //7 6 5 4 3 2 1
        //5 6 7 4 3 2 1
        // 5 6 7 1 2 3 4
    if(nums.size()<= 1 || k==0){
        return;
    }
    k%=nums.size();
        int s= 0;
        int e= nums.size()-1;
        while(e >=s){
            swap(nums[s],nums[e]);
            s++;
            e--;
        }

         s=0;
         e = k-1;
          while(e >=s){
            swap(nums[s],nums[e]);
            s++;
            e--;
        }

         s =k;
        e= nums.size()-1;
          while(e >=s){
            swap(nums[s],nums[e]);
            s++;
            e--;
        }

    }
};