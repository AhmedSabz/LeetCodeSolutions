#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map to store grouped anagrams
        map<string, vector<string>> anagramGroups;

        // Group strings by their sorted version
        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());  // Sort the string
            anagramGroups[sortedStr].push_back(str);   // Use sorted string as the key
        }

        // Collect the grouped anagrams
        vector<vector<string>> result;
        for (auto& pair : anagramGroups) {
            result.push_back(pair.second);  // Add each group of anagrams to the result
        }

        return result;
    }
};
