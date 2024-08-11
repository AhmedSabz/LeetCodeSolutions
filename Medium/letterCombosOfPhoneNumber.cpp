// 17. Letter Combinations of a Phone Number
// Solved
// Medium
// Topics
// Companies
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]
 

// Constraints:

// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].

using namespace std;
#include <iostream>
#include <map>
#include <vector>

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Map each digit to its corresponding letters, similar to a phone keypad
        std::map<char, std::string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";

        vector<char> inter;       // Temporary vector to store the current combination of letters
        vector<string> ret;       // Result vector to store all possible letter combinations
        string s;                 // Temporary string to build each combination

        // Start the recursive backtracking process
        solve(digits, inter, 0, ret, s, m);

        return ret;               // Return all possible letter combinations
    }

    void solve(string digits, vector<char>& inter, int start, vector<string>& ret, string& s, map<char, string>& m) {
        // If the input digits string is empty, return immediately
        if (digits == "") {
            return;
        }

        // Base case: If the current combination is of the same size as the input digits
        if (inter.size() == digits.length()) {
            // Convert the combination in 'inter' to a string 's' and add it to the result
            for (int k = 0; k < inter.size(); k++) {
                s += inter[k];
            }
            ret.push_back(s);  // Add the combination to the result vector
            s.clear();          // Clear the temporary string for the next combination
            return;
        }

        // Loop through all the letters corresponding to the current digit
        for (int i = 0; i < m[digits[start]].length(); i++) {
            inter.push_back(m[digits[start]][i]);  // Add the current letter to the combination
            solve(digits, inter, start + 1, ret, s, m);  // Recur to build the next part of the combination
            inter.pop_back();  // Backtrack: remove the last letter and try the next one
        }

        // For each letter in m['2'] {
        //     add letter to inter;
        //     solve('3', inter, ...);
        //     remove letter from current combo
        // }
    }
};
