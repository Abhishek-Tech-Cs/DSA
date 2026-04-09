/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if((!root->left && !root->right)||!root) return true;
        return solve(root->left,root->right);
    }
    bool solve(TreeNode* left,TreeNode* right){
        if(!left && !right) return true;
        else if((!left && right) || (left && !right) ||(left->val!=right->val)) return false;

        bool l,r;
        l=solve(left->left,right->right);
        r=solve(left->right,right->left);
        return l&&r;
    }
};