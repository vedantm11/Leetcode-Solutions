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
    map<int,int> mp;
    void preorder(TreeNode* root){
        if(root){
            mp[root->val]++;
            preorder(root->left);
            preorder(root->right);
        }
    }
    
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        preorder(root);
        int mx = INT_MIN;
        for(auto i : mp) mx = max(mx,i.second);
        for(auto i : mp) if(mx == i.second) ans.push_back(i.first);
        return ans;
        
    }
};