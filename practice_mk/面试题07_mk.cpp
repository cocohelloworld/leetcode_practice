/* 2020.02.20 mk */
//96 ms
//117 MB

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
        if(preorder.size() == 0) return  NULL;
        int root = preorder[0];
        vector<int> left_order;
        vector<int> right_order;
        int i=0;
        for(;i<preorder.size();++i){
            if(inorder[i] == root) break;
            left_order.push_back(inorder[i]);
        }
        ++i;
        for(;i<preorder.size();++i){
            right_order.push_back(inorder[i]);
        }
        TreeNode* tree = (TreeNode*) malloc(sizeof(TreeNode));
        tree->val = root;
        tree->left = NULL;
        tree->right = NULL;
        cutTree(left_order, right_order, preorder, inorder, 0, tree);

        return tree;
    }

    void cutTree(vector<int> left_order, vector<int> right_order, vector<int>& preorder, vector<int>& inorder, int level, TreeNode* tree) {
        ++level;
        //left

        vector<int> nleft_order;
        vector<int> nright_order;
        if (left_order.size() != 0){

            TreeNode* left_tree = (TreeNode*) malloc(sizeof(TreeNode));
            left_tree->left = NULL;
            left_tree->right = NULL;
            int root = preorder[level];
            left_tree->val = root;
            tree->left = left_tree;
            int i=0;
            for(;i<left_order.size();++i){
                if(left_order[i] == root) break;
                nleft_order.push_back(left_order[i]);
            }
            ++i;
            for(;i<left_order.size();++i){
                nright_order.push_back(left_order[i]);
            }

            if(left_order.size() > 1) cutTree(nleft_order, nright_order, preorder, inorder, level, left_tree);

        }else{
            tree->left = NULL;
        }



        //right
        nleft_order.clear();
        nright_order.clear();
        if (right_order.size() != 0){
            TreeNode* right_tree = (TreeNode*) malloc(sizeof(TreeNode));
            right_tree->left = NULL;
            right_tree->right = NULL;
            int root = preorder[left_order.size()+level];
            right_tree->val = root;
            tree->right = right_tree;
            int j=0;
            for(;j<right_order.size();++j){
                if(right_order[j] == root) break;
                nleft_order.push_back(right_order[j]);
            }
            ++j;
            for(;j<right_order.size();++j){
                nright_order.push_back(right_order[j]);
            }

            if(right_order.size() > 1) cutTree(nleft_order, nright_order, preorder, inorder, level+left_order.size(), right_tree);
        }else{
            tree->right = NULL;
        }

        return;
    }
};
