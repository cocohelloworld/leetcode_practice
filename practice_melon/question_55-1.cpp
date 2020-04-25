/*
 *time: 16 ms win: 48.93%
 *memory: 19.2 MB win:100%
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
  int maxDepth(TreeNode *root) {
    if (root == NULL)
      return 0;
    if (!root->left && !root->right)
      return 1;
    int left = 0;
    int right = 0;
    if (root->left) {
      left += maxDepth(root->left);
    }

    if (root->right) {
      right += maxDepth(root->right);
    }

    return max(left, right) + 1;
  }
};