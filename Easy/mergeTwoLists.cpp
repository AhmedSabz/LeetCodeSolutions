// 21. Merge Two Sorted Lists
// Solved
// Easy
// Topics
// Companies
// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

 


// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// Example 2:

// Input: list1 = [], list2 = []
// Output: []
// Example 3:

// Input: list1 = [], list2 = [0]
// Output: [0]
 

// Constraints:

// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both list1 and list2 are sorted in non-decreasing order.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to start the merged list
        ListNode* ret = new ListNode();
        // Pointer to traverse the merged list
        ListNode* trav = ret;
        // Pointers to traverse both input lists
        ListNode* a = list1;
        ListNode* b = list2;

        // Traverse both lists until one of them is fully iterated
        while (a && b) {
            // If the value of node in list 'a' is greater than or equal to the node in list 'b'
            if (a->val >= b->val) {
                // Add the smaller node from list 'b' to the merged list
                trav->next = b;
                // Move to the next node in list 'b'
                b = b->next;
            } else {
                // If the node in list 'a' is smaller
                // Add it to the merged list
                trav->next = a;
                // Move to the next node in list 'a'
                a = a->next;
            }
            // Move the traversal pointer forward in the merged list
            trav = trav->next;
        }

        // If list 'b' is not fully iterated and 'a' is fully iterated
       
