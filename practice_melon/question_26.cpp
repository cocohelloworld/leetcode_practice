/*
 *time: 116 ms win: 5.81%
 *memory: 33.7 MB win:100%
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
  bool isSubStructure(TreeNode *A, TreeNode *B) {
    if (A == NULL && B == NULL)
      return 1;
    if (A == NULL)
      return 0;
    if (B == NULL)
      return 0;
    if (B->val != A->val) {
      if (isSubStructure(A->left, B) || isSubStructure(A->right, B)) {
        return 1;
      }
    } else {
      if (match(A, B))
        return 1;
    }
    return 0;
  }
  bool match(TreeNode *A, TreeNode *B) {
    if (A == NULL && B == NULL)
      return 1;
    if (A != NULL && B == NULL)
      return 1;
    if (A == NULL)
      return 0;
    if (B == NULL)
      return 0;
    if (A->val == B->val) {
      if (match(A->left, B->left) && match(A->right, B->right)) {
        return 1;
      } else {
        return 0;
      }
    }
    return 0;
  }
};