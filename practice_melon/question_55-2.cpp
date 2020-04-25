/*
 *time: 20 ms win:63.87%
 *memory: 21.7 MB win:100%
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
  bool isBalanced(TreeNode *root) {
    if (root == NULL)
      return 1;
    int left = height(root->left);
    int right = height(root->right);

    if (abs(left - right) > 1)
      return 0;
    if (result == 1)
      return 0;
    return 1;
  }
  int height(TreeNode *root) {
    if (root == NULL)
      return 0;
    if (!root->left && !root->right)
      return 1;
    int left = 0;
    int right = 0;
    if (root->left) {
      left += height(root->left);
    }

    if (root->right) {
      right += height(root->right);
    }
    if (abs(left - right) > 1)
      result = 1;
    return max(left, right) + 1;
  }
  int result = 0;
};
