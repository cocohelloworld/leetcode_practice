/* 2020.03.13 mk */
//8 ms
//9.9 MB


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
        if(head->val == val) return head->next;
        ListNode* cur;
        cur = head;
        while(cur->next!=NULL){
            if((cur->next)->val != val) cur = cur->next;
            else cur->next = cur->next->next;
        }
        return head;
    }
};
