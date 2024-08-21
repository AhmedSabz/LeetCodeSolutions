// 846. Hand of Straights
// Solved
// Medium
// Topics
// Companies
// Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

// Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 

// Example 1:

// Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
// Output: true
// Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
// Example 2:

// Input: hand = [1,2,3,4,5], groupSize = 4
// Output: false
// Explanation: Alice's hand can not be rearranged into groups of 4.

 

// Constraints:

// 1 <= hand.length <= 104
// 0 <= hand[i] <= 109
// 1 <= groupSize <= hand.length
using namespace std;
#include <iostream>
#include <vector>

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // Check if the total number of cards is divisible by groupSize.
        // If not, it's impossible to form groups of the required size.
        if (hand.size() % groupSize != 0) {
            return false;
        }

        // Create a map to store the frequency of each card.
        map<int, int> m;
        for (int i = 0; i < hand.size(); i++) {
            m[hand[i]]++;
        }

        // Iterate as long as the map is not empty.
        while (m.size() != 0) {
            // Start with the smallest card available.
            auto p = m.begin()->first;

            // Try to form a group of 'groupSize' starting from the smallest card.
            for (int i = 0; i < groupSize; i++) {
                // Check if the current card (p + i) is available.
                if (m[p + i] > 0) {
                    // Decrease the count of the current card.
                    m[p + i]--;

                    // If the count of the current card becomes 0, remove it from the map.
                    if (m[p + i] == 0) {
                        m.erase(p + i);
                    }
                } else {
                    // If the current card is missing, it's impossible to form a valid group.
                    return false;
                }
            }
        }

        // If all cards are used up and groups are successfully formed, return true.
        return true;
    }
};
