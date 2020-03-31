/*
 *time: 4 ms win: 86.29%
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
    queue<pair<TreeNode *, int>> node2;
    node.push(make_pair(root, 0));
    node2.push(make_pair(root, 0));
    vector<int> row;
    int level = 0;
    TreeNode *k;
    TreeNode *k2;
    while (!node.empty() && root != NULL) {
      if (node.front().second > level) {
        result.push_back(row);
        row.clear();
      }
      level = node.front().second;
      k = node.front().first;
      k2 = node2.front().first;
      if (!(level % 2)) {
        row.push_back((node.front().first)->val);
      } else if (level % 2) {
        row.push_back((node2.front().first)->val);
      }

      if (k->left)
        node.push(make_pair(k->left, level + 1));
      if (k->right)
        node.push(make_pair(k->right, level + 1));

      if (k2->right)
        node2.push(make_pair(k2->right, level + 1));
      if (k2->left)
        node2.push(make_pair(k2->left, level + 1));

      node.pop();
      node2.pop();
      if (node.empty())
        result.push_back(row);
    }
    return result;
  }
};