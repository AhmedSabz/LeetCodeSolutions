// 216. Combination Sum III
// Solved
// Medium
// Topics
// Companies
// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.
// Example 2:

// Input: k = 3, n = 9
// Output: [[1,2,6],[1,3,5],[2,3,4]]
// Explanation:
// 1 + 2 + 6 = 9
// 1 + 3 + 5 = 9
// 2 + 3 + 4 = 9
// There are no other valid combinations.
// Example 3:

// Input: k = 4, n = 1
// Output: []
// Explanation: There are no valid combinations.
// Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
 

// Constraints:

// 2 <= k <= 9
// 1 <= n <= 60
using namespace std;
#include <iostream>
#include <vector>
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        // Create a temporary vector to store a combination and a vector to store all combinations
        vector<int> temp;
        vector<vector<int>> ret;
        // Call the recursive helper function to find all combinations
        solve(k, n, temp, ret, 1);
        return ret;
    }

    // Recursive function to find combinations
    void solve(int k, int n, vector<int>& temp, vector<vector<int>>& ret, int start) {
        // Base case: if the sum is zero and the size of the combination equals k, store it
        if (n == 0 && temp.size() == k) {
            ret.push_back(temp); // Store the valid combination
            return;
        }
        
        // If the sum is less than zero, return (no valid combination)
        if (n < 0) {
            return;
        }

        // Iterate over numbers from 'start' to 9
        for (int i = start; i <= 9; i++) {
            // Add the current number to the combination
            temp.push_back(i);
            // Recurse to find the next number in the combination, reducing n by i
            solve(k, n - i, temp, ret, i + 1);
            // Backtrack: remove the last number to explore other possibilities
            temp.pop_back();
        }
    }
};
