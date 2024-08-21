
// 739. Daily Temperatures
// Solved
// Medium
// Topics
// Companies
// Hint
// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
// Example 2:

// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]
// Example 3:

// Input: temperatures = [30,60,90]
// Output: [1,1,0]
 

// Constraints:

// 1 <= temperatures.length <= 105
// 30 <= temperatures[i] <= 100

using namespace std;
#include <iostream>
#include <stack>
#include<vector>
class Solution {
public:
    // Function to find the number of days until a warmer temperature for each day.
    vector<int> dailyTemperatures(vector<int>& s) {
        // Initialize the results vector with the same size as input 's' and fill it with 0s.
        vector<int> results(s.size(), 0);
        
        // Stack to keep track of indices of days with unresolved temperatures.
        stack<int> stk;

        // Edge case: If the input size is 1, the result is simply {0}, since no future days exist.
        if(s.size() == 1) {
            return {0};
        }

        // Iterate through each day in the input vector.
        for(int i = 0; i < s.size(); i++) {
            // While the stack is not empty and the current day's temperature is greater than
            // the temperature at the index stored at the top of the stack.
            while(!stk.empty() && s[i] > s[stk.top()]) {
                // Get the index from the top of the stack.
                auto f = stk.top();

                // Calculate the number of days until a warmer temperature and store it in the correct position.
                results[f] = abs(i - f);
                
                // Pop the index from the stack as it is now resolved.
                stk.pop();
            }
            // Push the current index onto the stack.
            stk.push(i);
        }
        
        // Return the results vector which contains the number of days until a warmer temperature for each day.
        return results;
    }
};
