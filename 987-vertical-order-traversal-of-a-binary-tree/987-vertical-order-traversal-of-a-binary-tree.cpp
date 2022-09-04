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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> m;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            TreeNode* node=temp.first;
            int level=temp.second.first;
            int v=temp.second.second;
            m[v][level].insert(node->val);
            if(node->left!=NULL)
            {
                q.push({node->left,{level+1,v-1}});
            }
            if(node->right!=NULL)
            {
                q.push({node->right,{level+1,v+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto i:m)
        {
            vector<int> res;
            for(auto j:i.second)
            {
                res.insert(res.end(),j.second.begin(),j.second.end());    
            }
            ans.push_back(res);
        }
        return ans;
    }
};