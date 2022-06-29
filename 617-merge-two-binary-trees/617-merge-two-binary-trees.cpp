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
    
    TreeNode* helper(TreeNode* root1,TreeNode* root2){
        if(root1==NULL && root2==NULL) return NULL;
        else if(root1==NULL) return root2;           
        else if(root2==NULL) return root1;
        TreeNode* newRoot;
        if(root1 && root2) newRoot=new TreeNode(root1->val+root2->val);
        newRoot->left=helper(root1->left,root2->left);
        newRoot->right=helper(root1->right,root2->right);
        return newRoot;            
    
    }
    
    
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return helper(root1,root2);
    }
};