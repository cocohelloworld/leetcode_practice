/*
 *time: 8 ms win: 85.08%
 *memory: 8.1 MB win:100%
 *coded by jiaxin
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
 public:
  int max = 0;
  int min = 0;
  int flag = 0;

  vector<Node*> map;
  Node* treeToDoublyList(Node* root) {
    if (!list(root)) return NULL;
    if (map.size() == 1) {
      map[0]->left = map[0];
      map[0]->right = map[0];

    } else {
      map[0]->left = map[map.size() - 1];
      map[0]->right = map[1];
      map[map.size() - 1]->left = map[map.size() - 2];
      map[map.size() - 1]->right = map[0];
      for (int i = 1; i < map.size() - 1 && map.size() > 1; i++) {
        map[i]->left = map[i - 1];
        map[i]->right = map[i + 1];
      }
    }

    return map[0];
  }
  int list(Node* root) {
    if (root == NULL) return 0;
    if (!root->left && !root->right) {
      map.push_back(root);
      if (!flag) {
        min = root->val;
        flag = 1;
      }
      return 1;
    }

    if (root->left) {
      list(root->left);
    }

    map.push_back(root);

    if (root->right) {
      list(root->right);
      max = (root->right)->val;
    }
    return 1;
  }
};