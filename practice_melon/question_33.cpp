/*
 *time: 4 ms win: 88.05%
 *memory: 12.7 MB win:100%
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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> result;
    queue<pair<TreeNode *, int>> node;
    node.push(make_pair(root, 0));
    vector<int> row;
    int level = 0;
    while (!node.empty() && root != NULL) {
      if (node.front().second > level) {
        result.push_back(row);
        row.clear();
      }
      level = node.front().second;
      TreeNode *k = node.front().first;
      row.push_back((node.front().first)->val);
      if (k->left)
        node.push(make_pair(k->left, level + 1));
      if (k->right)
        node.push(make_pair(k->right, level + 1));

      node.pop();
      if (node.empty())
        result.push_back(row);
    }
    return result;
  }
};