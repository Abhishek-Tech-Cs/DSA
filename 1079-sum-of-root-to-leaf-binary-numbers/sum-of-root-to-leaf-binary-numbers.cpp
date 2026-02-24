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
    int sumRootToLeaf(TreeNode* root) {
        vector<string>store;
        traverse(root,store);
        int ans=0;
        for(int i=0;i<store.size();i++){
            int sum=0,power=0;
            for(int j=store[i].size()-1;j>=0;j--){
                if(store[i][j]=='1') sum=sum+pow(2,power);
                power++;
            }
            ans+=sum;
        }
        return ans;
    }
    void traverse(TreeNode* root,vector<string> &store,string temp=""){
        if(!root) return;

        char ch=root->val+'0';
        temp.push_back(ch);
        if(!root->left && !root->right){
            store.push_back(temp);
            return;
        }
        traverse(root->left,store,temp);
        traverse(root->right,store,temp);
    }
};