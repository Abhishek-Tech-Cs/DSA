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
    TreeNode *pre=NULL,*first=NULL, *second=NULL;
    void recoverTree(TreeNode* root) {
        solve(root);
        swap(first->val,second->val);
    }
    void solve(TreeNode* root){
        if(!root) return;

        solve(root->left);
        if(pre && root->val<pre->val){
            if(!first) first=pre;
            second=root;
        }
        pre=root;
        solve(root->right);
    }
};