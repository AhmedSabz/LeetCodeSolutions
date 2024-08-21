// You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

// Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

// Return a list of integers representing the size of these parts.

 

// Example 1:

// Input: s = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
// Example 2:

// Input: s = "eccbbbbdec"
// Output: [10]
 

// Constraints:

// 1 <= s.length <= 500
// s consists of lowercase English letters.
using namespace std;
#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Create a map to store the last index of each character
        map<char, int> m;
        vector<int> ret; // Vector to store the result: sizes of each partition
        int lenOfPart = 0; // Variable to hold the length of each partition
        
        // Traverse the string from the end to find the last occurrence of each character
        for (int i = s.length() - 1; i >= 0; i--) {
            if (!m.count(s[i])) { // If the character is not yet in the map, add it
                m[s[i]] = i;
            } else if (m.count(s[i])) { // If the character is already in the map, skip it
                continue;
            }
        }

        int start = 0; // Start index of the current partition
        int end = 0; // End index of the current partition
        
        // Traverse the string to determine the partitions
        for (int i = 0; i < s.length(); i++) {
            end = max(end, m[s[i]]); // Update the end index to the farthest last occurrence of the current character
            if (i == end) { // If the current index matches the end index, a partition is complete
                ret.push_back(end - start + 1); // Store the size of the partition
                start = i + 1; // Update the start index for the next partition
            }
        }
        
        return ret; // Return the list of partition sizes
    }
};
