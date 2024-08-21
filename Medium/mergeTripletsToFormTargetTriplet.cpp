using namespace std;
#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // Set to track which elements of target can be matched
        set<int> s;

        // Loop through each triplet in the input
        for (int i = 0; i < triplets.size(); i++) {
            // Skip this triplet if any of its values exceed the corresponding target value
            if (triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]) {
                continue; // Move to the next triplet
            }

            // Check if the current triplet can contribute to forming the target
            for (int j = 0; j < target.size(); j++) {
                // If the triplet's value matches the target at index j, add j to the set
                if (triplets[i][j] == target[j]) {
                    s.insert(j); // Insert the index into the set
                }
            }
        }

        // If the set contains all 3 indices (0, 1, and 2), we can form the target triplet
        return s.size() == 3; // Return true if all 3 target values can be matched
    }
};
