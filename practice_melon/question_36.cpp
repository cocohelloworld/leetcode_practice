/*
 *time: 12 ms win: 80.18%
 *memory: 20.2 MB win:100%
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
  vector<vector<int>> result;
  vector<int> row;
  vector<vector<int>> pathSum(TreeNode *root, int sum) {
    if (root == NULL)
      return result;
    check(root, sum);
    return result;
  }
  int check(TreeNode *root, int sum) {
    if (sum == root->val && root->left == NULL && root->right == NULL) {
      //  cout<<root->val<<endl;
      row.push_back(root->val);
      result.push_back(row);
      row.pop_back();

      return 1;
    } else {
      if (root->left == NULL && root->right == NULL) {
        return 0;
      }
      row.push_back(root->val);
      int left = 0;
      int right = 0;
      if (root->left) {
        left = check(root->left, sum - root->val);
      }
      if (root->right) {
        right = check(root->right, sum - root->val);
      }
      if (!left && !right) {
        row.pop_back();
        return 0;
      } else {
        row.pop_back();
        return 1;
      }
    }
    return 0;
  }
};