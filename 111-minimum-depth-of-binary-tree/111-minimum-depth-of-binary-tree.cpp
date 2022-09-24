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
    
    void traverse(TreeNode* root, int depth, int &ans){
        
      if(!(root ->left) && !(root -> right)){ 
          ans = min(ans,depth);
          return;
      }
        
      if(root -> left) traverse(root -> left, depth + 1, ans);  
      if(root -> right) traverse(root -> right, depth + 1, ans);  
    }   
    
    
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int ans = INT_MAX;
        traverse(root,1,ans);    
        return ans;
    }
};