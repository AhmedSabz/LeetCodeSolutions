#include <iostream>
using namespace std;
#include <vector>

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
        vector<int>v;
        ListNode* a=head;
        while(a){
            v.push_back(a->val);
            a=a->next;
        }
        sort(v.begin(),v.end());
        ListNode*ret= new ListNode();
        ListNode*trav =ret;
        for(int i=0; i<v.size();i++){
            ListNode* add= new ListNode(v[i]);
            trav->next=add;
            trav=trav->next;
        }
        return ret->next;
    }
};