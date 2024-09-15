#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Step 1: Extract all values from the linked list into a vector
        vector<int> v;           // Vector to store node values
        ListNode* a = head;      // Pointer to traverse the linked list
        
        // Traverse the linked list and push each node's value into the vector
        while (a) {
            v.push_back(a->val); // Add the value of the current node to the vector
            a = a->next;         // Move to the next node in the list
        }

        // Step 2: Sort the values stored in the vector
        sort(v.begin(), v.end()); // Sort the vector in ascending order

        // Step 3: Create a new sorted linked list from the sorted values
        ListNode* ret = new ListNode(); // Dummy node to start the new linked list
        ListNode* trav = ret;           // Pointer to traverse the new list
        
        // Iterate over the sorted values in the vector and create new nodes
        for (int i = 0; i < v.size(); i++) {
            ListNode* add = new ListNode(v[i]); // Create a new node with the sorted value
            trav->next = add;                   // Link the new node to the current list
            trav = trav->next;                  // Move the pointer to the new node
        }

        // Step 4: Return the head of the sorted linked list (skip the dummy node)
        return ret->next;
    }
};
