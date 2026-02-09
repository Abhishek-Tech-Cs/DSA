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
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*>inorder;
        traverse(root,inorder);
        return solve(inorder,0,inorder.size());
    }
    void traverse(TreeNode* root,vector<TreeNode*> &inorder){
        if(!root) return;
        traverse(root->left,inorder);
        inorder.push_back(root);
        traverse(root->right,inorder);
    }
    TreeNode* solve(vector<TreeNode*>inorder,int st,int end){
        if(st>=end) return NULL;
        int mid=(st+end)/2;
        inorder[mid]->left=inorder[mid]->right=NULL;

        inorder[mid]->left=solve(inorder,st,mid);
        inorder[mid]->right=solve(inorder,mid+1,end);
        return inorder[mid];
    }
};