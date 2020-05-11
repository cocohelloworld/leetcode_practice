/*
 *time: 44 ms win: 10.34%
 *memory: 18.6 MB win: 100%
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
      dfs(root, p);
      flag = 0;
      map<TreeNode *, int> pair;
      for (auto p_ : his) {
        pair[p_] = 1;
        //  cout<<"p"<<p_->val;
      }

      his.clear();
      dfs(root, q);
      // cout<<"his"<<his.size()<<endl;
      for (auto q_ : his) {
        if (pair[q_] == 1) {
          return q_;
        }
      }
    }
    return NULL;
  }
  void dfs(TreeNode *root, TreeNode *node) {
    TreeNode *f = root;
    if (flag == 0 && f->val == node->val) {
      // cout<<"win"<<f->val<<endl;
      flag = 1;
      his.push_back(f);
    } else if (flag == 0 && f->val != node->val) {
      // cout<<f->val<<endl;
      if (f->left) {
        dfs(f->left, node);
        if (flag == 1)
          his.push_back(f);
      }

      if (flag == 0 && f->right) {
        dfs(f->right, node);
        if (flag == 1)
          his.push_back(f);
      }
    }
  }
  int flag = 0;
  vector<TreeNode *> his;
};