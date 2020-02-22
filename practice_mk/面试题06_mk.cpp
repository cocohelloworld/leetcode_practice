/* 2020.02.22 mk */
//72 ms
//11.1 MB

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
        vector<int> r;
        if(!head) return r;
        do r.emplace(r.begin(),head->val);
        while(head = head -> next);
        return r;
    }
};
