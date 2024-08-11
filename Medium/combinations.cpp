using namespace std;
#include <iostream>
#include <vector>
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp; // Temporary vector to store the current combination
        vector<vector<int>> ret; // Result vector to store all the combinations
        solve(n, k, 1, ret, temp); // Start the backtracking process from 1
        return ret; // Return all possible combinations
    }

    void solve(int n, int k, int start, vector<vector<int>>& ret, vector<int>& temp) {
        // Base case: if the size of the current combination equals k
        if (temp.size() == k) {
            ret.push_back(temp); // Add the current combination to the result
            return;
        }
        
        // Loop through all possible elements starting from 'start'
        for (int i = start; i <= n; i++) {
            temp.push_back(i); // Include the current element in the combination
            solve(n, k, i + 1, ret, temp); // Recur with the next element
            temp.pop_back(); // Backtrack: remove the last element and try the next one
        }
    }
};
