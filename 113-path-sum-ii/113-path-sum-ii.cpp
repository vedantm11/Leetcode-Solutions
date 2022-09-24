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
    
    
    
    vector<vector<int>> ans;
    
    void traverse(TreeNode* root, int targetSum,int curValue,vector<int> curSequence)
    {
        if(root -> left == NULL && root -> right == NULL)
        {
            curValue += root -> val;
            curSequence.push_back(root -> val);
            if(curValue == targetSum) ans.push_back(curSequence);
            return;
        }
        else
        {
            curValue += root -> val;
           // if(curValue >= targetSum) return;
            curSequence.push_back(root -> val);
            if(root -> left) traverse(root -> left,targetSum,curValue,curSequence);
            if(root -> right) traverse(root -> right,targetSum,curValue,curSequence);
        }
    }    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        traverse(root,targetSum,0,{});
        return ans;
        
        
        
        
        
    }
};