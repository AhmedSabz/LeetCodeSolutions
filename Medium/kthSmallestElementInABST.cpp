// 230. Kth Smallest Element in a BST
// Solved
// Medium
// Topics
// Companies
// Hint
// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

// Example 1:


// Input: root = [3,1,4,null,2], k = 1
// Output: 1
// Example 2:


// Input: root = [5,3,6,2,4,null,null,1], k = 3
// Output: 3
 

// Constraints:

// The number of nodes in the tree is n.
// 1 <= k <= n <= 104
// 0 <= Node.val <= 104
 

// Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
using namespace std;
#include <iostream>

 // Definition for a binary tree node.
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
void preorder(TreeNode* root,int& count,int &k,int &ans){// goes through the nodes in increasing order
    if(!root){
        return ;
    }
        preorder(root->left,count,k,ans);
        count++;//increment as you go
           if(count==k){// once you reach the k value you have found the kth smallest element
                    ans=root->val;
        return;
       }
    preorder(root->right,count,k,ans); // traverse the right subtree

}
    int kthSmallest(TreeNode* root, int k) {
        int count =0;
       int ans=root->val;
        preorder(root,count,k,ans);
        
     
    return ans;
    }
};