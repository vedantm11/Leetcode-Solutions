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
    
    vector<string> strs;
    
    void traverse(string str, TreeNode* root)
    {
        str += char(root -> val + 97);
        
        if(root -> left == NULL && root -> right  == NULL){
          reverse(str.begin(),str.end());
          strs.push_back(str);
          return;  
        }
        
        if(root -> left) traverse(str,root -> left);
        if(root -> right) traverse(str,root -> right);
    }
    
    
    
    string smallestFromLeaf(TreeNode* root) {
     
        if(!root) return "";
        string str = "";
        traverse(str,root);
        sort(strs.begin(),strs.end());
        return strs[0];
    }
};