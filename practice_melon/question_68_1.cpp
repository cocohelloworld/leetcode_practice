/*
 *time: 40 ms win: 82.73%
 *memory: 23.4 MB win: 100%
 *coded by jiaxin
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == NULL)
      return NULL;
    else {
      vector<TreeNode *> p_his = find(root, p);
      vector<TreeNode *> q_his = find(root, q);
      reverse(p_his.begin(), p_his.end());
      reverse(q_his.begin(), q_his.end());
      map<TreeNode *, int> pair;
      for (auto p_ : p_his) {
        pair[p_] = 1;
      }
      for (auto q_ : q_his) {
        if (pair[q_] == 1)
          return q_;
      }
    }
    return NULL;
  }
  vector<TreeNode *> find(TreeNode *root, TreeNode *node) {
    TreeNode *f = root;
    vector<TreeNode *> history;
    while (1) {
      history.push_back(f);
      if (f->val != node->val) {
        if (f->val > node->val) {
          f = f->left;
        } else if (f->val < node->val) {
          f = f->right;
        }
      } else {
        return history;
      }
    }
  }
};