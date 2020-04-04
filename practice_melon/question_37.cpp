/*
 *time: 16 ms win: 53.10%
 *memory: 11.2 MB win:100%
 *coded by jiaxin
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (head == NULL) return NULL;
    unordered_map<Node*, Node*> map;
    for (auto f = head; f != NULL; f = f->next) {
      map[f] = new Node(f->val);
    }
    for (auto f = head; f != NULL; f = f->next) {
      if (f->next) map[f]->next = map[f->next];
      if (f->random) map[f]->random = map[f->random];
    }
    return map[head];
  }
};