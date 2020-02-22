/*
time: 104ms
memory: 117.1MB
win:12.69%
coded by jiaxin
too slow!too big!
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int root;
		if (preorder.size() != 0)return build(preorder, inorder, 0);
		else return NULL;
	}
	TreeNode* build(vector<int>& preorder, vector<int>& inorder, int root) {
		TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
		node->val = preorder[root];
		node->left = NULL;
		node->right = NULL;
		int end = 0;
		int flag = 0;
		vector<int> inleft;
		vector<int> inright;

		for (int i = 0; i < inorder.size(); i++) {
			if (preorder[root] != inorder[i] && !flag) {
				inleft.push_back(inorder[i]);
			}
			else if (!flag && preorder[root] == inorder[i]) {
				flag = 1;
				end = i;
				if (!end&&preorder.size() == 1) {
					cout << node->val << endl;
					return node;
				}
				i++;
			}
			if (flag == 1 && i < inorder.size()) {
				inright.push_back(inorder[i]);
			}
		}
		if (inleft.size()) {
			vector<int> preleft(preorder.begin() + 1, preorder.begin() + 1 + end);
			node->left = build(preleft, inleft, 0);
		}
		if (inright.size()) {
			vector<int> preright(preorder.begin() + end + 1, preorder.end());
			node->right = build(preright, inright, 0);
		}
		cout << node->val << endl;
		return node;
	}
};