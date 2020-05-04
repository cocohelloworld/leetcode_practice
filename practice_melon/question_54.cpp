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
  int kthLargest(TreeNode *root, int k) {
    if (root == NULL)
      return NULL;
    if (flag)
      return result;
    if (!root->left && !root->right) {
      cur++;
      if (cur == k) {
        if (!flag) {
          flag = 1;
          result = root->val;
        }
        return result;
      }
      return 1;
    }

    if (root->right) {
      kthLargest(root->right, k);
    }
    cur++;
    if (cur == k) {
      if (!flag) {
        flag = 1;
        result = root->val;
      }
      return result;
    }
    if (root->left) {
      kthLargest(root->left, k);
    }

    return result;
  }
  int cur = 0;
  int result;
  int flag = 0;
};