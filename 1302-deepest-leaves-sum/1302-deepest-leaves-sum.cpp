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
    
    int mx = INT_MIN;
 
    void dfs(TreeNode* root, int l, vector<pair<int,int>> &nodes)
    {
        if(!root) return;
        nodes.push_back({root -> val,l});
        mx = max(l,mx);
        if(root -> left) dfs(root -> left,l+1,nodes);
        if(root -> right) dfs(root -> right,l+1,nodes);
    }
    
    
    
    int deepestLeavesSum(TreeNode* root) {
        vector<pair<int,int>> nodes;
        dfs(root,0,nodes);
        int ans = 0;
        for(auto i : nodes){
            if(mx == i.second) ans += i.first;
        }
        
        return ans;
    }
};