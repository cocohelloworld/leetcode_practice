/*
 *time: 8 ms win: 15.90%
 *memory: 8.7 MB win:100%
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
  TreeNode *mirrorTree(TreeNode *root) {
    TreeNode *temp = new TreeNode();
    if (root == NULL)
      return NULL;
    temp->val = root->val;
    temp->left = root->right;
    temp->right = root->left;
    if (temp->left != NULL)
      temp->left = mirrorTree(temp->left);
    if (temp->right != NULL)
      temp->right = mirrorTree(temp->right);

    return temp;
  }
};