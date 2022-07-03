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
    
    void helper(TreeNode* root,int &ans){
        if(root->left && root->left->left==NULL && root->left->right==NULL)
        {
            ans+=root->left->val;
        }
        if(root->left) helper(root->left,ans);
        if(root->right) helper(root->right,ans);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        helper(root,ans);
        return ans;
        
    }
};