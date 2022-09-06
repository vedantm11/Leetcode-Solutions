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
    
    bool traverse(TreeNode* root)
    {
        if(!root) return false;
        bool left = traverse(root -> left);
        bool right = traverse(root -> right);
        
        if(!left) root -> left = NULL;
        if(!right) root -> right = NULL;
        if(!left && !right && root -> val != 1) return false;
        return true;
    }
    
    
    
    
    TreeNode* pruneTree(TreeNode* root) {
        
           bool ans =  traverse(root);
            if(ans) return root;
            return NULL;
        
        }
};