/*
 *time: 8 ms win: 44.86%
 *memory: 11.9 MB win:100%
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
  ListNode *getKthFromEnd(ListNode *head, int k) {
    ListNode *s = head;
    ListNode *sk = head;
    int sum = 0;
    while (s->next != NULL) {

      s = s->next;
      sum++;
      if (sum >= k) {
        sk = sk->next;
      }
    }
    return sk;
  }
};