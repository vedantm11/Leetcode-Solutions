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
    
    bool helper(TreeNode* root,int sum,int targetSum)
    {
        if(root->left==NULL && root->right==NULL) {
            if((sum+root->val)==targetSum) return true;
            else return false;
        }
        sum+=root->val;
        bool l=false,r=false;
        if(root->left) l=helper(root->left,sum,targetSum);
        if(root->right) r=helper(root->right,sum,targetSum);
        return l || r;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        return helper(root,0,targetSum);
    }
};