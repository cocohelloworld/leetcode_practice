/*
time: 4ms
win:96.31%
coded by jiaxin
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  vector<int> reversePrint(ListNode* head) {
    vector<int> result;
    while (head != NULL) {
      result.push_back(head->val);
      head = head->next;
    }
    reverse(result.begin(), result.end());
    return result;
  }
};