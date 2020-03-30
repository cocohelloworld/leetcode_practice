/*
 *time: 12 ms win: 13.96%
 *memory: 12.5 MB win:100%
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
  vector<int> levelOrder(TreeNode *root) {
    vector<int> result;
    queue<TreeNode *> node;
    node.push(root);
    while (!node.empty() && root != NULL) {
      TreeNode *k = node.front();
      result.push_back(k->val);
      if (k->left)
        node.push(k->left);
      if (k->right)
        node.push(k->right);
      node.pop();
    }
    return result;
  }
};