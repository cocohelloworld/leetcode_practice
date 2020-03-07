/*
 *time: 12 ms win:58.29%
 *memory: 10.9 MB win:100%
 *coded by jiaxin
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
  ListNode* deleteNode(ListNode* head, int val) {
    ListNode* my = head;
    int k = 0;
    ListNode* mylast = head;

    while (1) {
      if (my->val != val && k) {
        my = my->next;
        mylast = mylast->next;
      } else if (my->val != val && !k) {
        my = my->next;
        mylast = head;
      } else if (k) {
        mylast->next = my->next;
        return head;
      } else if (!k) {
        head = head->next;
        return head;
      }
      k++;
    }
  }
};