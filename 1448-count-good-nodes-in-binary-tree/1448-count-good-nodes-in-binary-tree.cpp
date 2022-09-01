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
    int ans = 0;
    
    void traverse(TreeNode* root,int mx)
    {
        if(!root) return;
        if(mx <= root->val) ans++;
         mx = max(mx,root->val);
        traverse(root->left,mx);
        traverse(root->right,mx);
    }
    
    
    int goodNodes(TreeNode* root) {
        vector<int> nodes;
        traverse(root,INT_MIN);
        return ans;
        
    }
};