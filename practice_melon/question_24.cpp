/*
 *time: 40 ms win: 7.10%
 *memory: 20.6 MB win:100%
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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode();
    head->val = 0;
    head->next = NULL;
    ListNode *s = head;
    vector<int> list;
    while (l1 != NULL) {
      list.push_back(l1->val);
      l1 = l1->next;
    }
    while (l2 != NULL) {
      list.push_back(l2->val);
      l2 = l2->next;
    }
    sort(list.begin(), list.end());
    for (int i = 0; i < list.size(); i++) {
      ListNode *merge = new ListNode();
      merge->val = list[i];
      merge->next = NULL;
      s->next = merge;
      s = s->next;
    }
    return head->next;
  }
};