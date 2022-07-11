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
   
    vector<int> ans;
    void rightview(TreeNode* root,int l)
    {
        if(root==NULL)  return;
        if(ans.size()==l)   ans.push_back(root->val);
        rightview(root->right,l+1);
        rightview(root->left,l+1);
           
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        rightview(root,0);
        return ans;
        
    }
};