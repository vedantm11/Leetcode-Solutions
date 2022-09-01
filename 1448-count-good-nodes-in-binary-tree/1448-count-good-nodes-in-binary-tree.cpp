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
    
    void traverse(TreeNode* root,vector<int> nodes)
    {
        if(!root) return;
        int flag = 0;
        for( auto i : nodes){
            if(i > root->val){
                flag  = 1;
                break;
            }
        }
        if(!flag) ans++;
        nodes.push_back(root -> val);
        traverse(root->left,nodes);
        traverse(root->right,nodes);
    }
    
    
    int goodNodes(TreeNode* root) {
        vector<int> nodes;
        traverse(root,nodes);
        return ans;
        
    }
};