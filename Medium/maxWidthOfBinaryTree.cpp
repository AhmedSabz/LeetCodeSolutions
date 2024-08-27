using namespace std;
#include<iostream>
#include <queue>


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // Queue to store pairs of TreeNode* and its corresponding index
        queue<pair<TreeNode*,int>> q;

        // Variable to store the maximum width
        int maxWidth = 0;

        // Start by pushing the root node with index 0
        q.push({root, 0});

        // Loop until the queue is empty
        while(!q.empty()){
            // Get the number of nodes at the current level
            int n = q.size();

            // Get the index of the rightmost and leftmost nodes at this level
            long long int rightid = q.back().second;
            long long int leftid = q.front().second;

            // Iterate over all nodes at this level
            for(int i = 0; i < n; i++){
                // Get the front node and its index
                auto t = q.front().first;
                auto idx = q.front().second - leftid;  // Normalize index to prevent overflow
                q.pop();

                // If the left child exists, push it into the queue with its index
                if(t->left){
                    q.push({t->left, 2*idx + 1});
                }

                // If the right child exists, push it into the queue with its index
                if(t->right){
                    q.push({t->right, 2*idx});
                }
            }

            // Update the maximum width
            maxWidth = max(maxWidth, abs(int(rightid - leftid)) + 1);
        }

        // Return the maximum width found
        return maxWidth;
    }
};
