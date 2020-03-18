/*
 *time: 8 ms win: 67.56%
 *memory: 9.8 MB win:100%
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
  ListNode *reverseList(ListNode *head) {
    ListNode *s = head;
    vector<int> list;
    if (s == NULL) {
      return s;
    }
    while (s->next != NULL) {
      list.push_back(s->val);
      s = s->next;
    }
    list.push_back(s->val);
    ListNode *myhead = new ListNode;
    myhead->val = 0;
    myhead->next = NULL;
    ListNode *nhead = myhead;
    for (int i = list.size() - 1; i >= 0; i--) {
      ListNode *reverse = new ListNode;
      reverse->val = list[i];
      reverse->next = NULL;
      nhead->next = reverse;
      nhead = nhead->next;
    }

    return myhead->next;
  }
};