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
    void flatten(TreeNode* root) {
        if(root==NULL) return ;
        TreeNode* cur=root;
        while(cur!=NULL){
            if(cur->left!=NULL){
            TreeNode* next=cur->left;
            while(next->right!=NULL) next=next->right;
            next->right=cur->right;
            cur->right=cur->left;
            cur->left=NULL;
            }
            cur=cur->right;
                
        }
        
    }
};