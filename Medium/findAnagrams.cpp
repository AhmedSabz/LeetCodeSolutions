//Problem Statement

// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
// Example 2:

// Input: s = "abab", p = "ab"
// Output: [0,1,2]
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".
 

// Constraints:

// 1 <= s.length, p.length <= 3 * 104
// s and p consist of lowercase English letters
using namespace std;
#include <iostream>
#include <vector>
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret; // To store the starting indices of the anagrams found in 's'
        
        // If 'p' is longer than 's', no anagram can exist, so return an empty vector
        if (p.length() > s.length()) {
            return ret;
        }
        
        // Frequency arrays to store character counts for 'p' and the current window in 's'
        vector<int> pFreq(26, 0); // Frequency array for characters in 'p'
        vector<int> sFreq(26, 0); // Frequency array for the current window in 's'
        
        // Initialize the frequency arrays with the first 'p.length()' characters
        for (int i = 0; i < p.length(); ++i) {
            pFreq[p[i] - 'a']++; // Increment frequency count for each character in 'p'
            sFreq[s[i] - 'a']++; // Increment frequency count for the corresponding character in 's'
        }
        
        // Slide the window over 's' to check all substrings of length 'p.length()'
        for (int i = 0; i <= s.length() - p.length(); ++i) {
            // If the frequency arrays match, an anagram is found, add the starting index to the result
            if (pFreq == sFreq) {
                ret.push_back(i);
            }
            // Slide the window: remove the leftmost character of the current window from sFreq,
            // and add the next character in the string to sFreq
            if (i + p.length() < s.length()) {
                sFreq[s[i + p.length()] - 'a']++; // Add the next character to the window
                sFreq[s[i] - 'a']--; // Remove the leftmost character from the window
            }
        }
        
        // Return the list of starting indices where anagrams of 'p' are found in 's'
        return ret;
    }
};
