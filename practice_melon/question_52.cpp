/*
 *time: 56 ms win:73.81%
 *memory: 14.7 MB win:100%
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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *f_a = headA;
    ListNode *f_b = headB;
    while (f_a != f_b) {
      if (f_a == NULL)
        f_a = headB;
      else
        f_a = f_a->next;
      if (f_b == NULL)
        f_b = headA;
      else
        f_b = f_b->next;
    }
    return f_a;
  }
};