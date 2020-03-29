/*
 *time: 4 ms win: 91.96%
 *memory: 16.3 MB win:100%
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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return 1;
        TreeNode* myleft=root->left;
        TreeNode* myright=root->right;
        if(myleft==NULL&&myright==NULL)return 1;
        if(myleft==NULL||myright==NULL)return 0;
        if(myleft->val==myright->val){
            if(match(myleft,myright))return 1;
        }
        return 0;
    }
    bool match(TreeNode* left, TreeNode* right){
        if(left==NULL&&right==NULL)return 1;
        if(left==NULL||right==NULL)return 0;
        if(left->val==right->val){
            if(match(left->left,right->right)&&match(left->right,right->left)){
                return 1;
            }
        }
        return 0;
    }
};