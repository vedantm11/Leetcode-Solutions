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
    
    int pi=0;
    TreeNode * builder(vector<int> &preorder,vector<int> &inorder,int li,int ri){
        if(li>ri) return NULL;
           int ind;
            TreeNode* root=new TreeNode(preorder[pi++]);
            for(int i=li;i<=ri;i++){
                if(inorder[i]==root->val){
                ind=i;
                break;
            }
        }
        root->left=builder(preorder,inorder,li,ind-1);
        root->right=builder(preorder,inorder,ind+1,ri);
    return root;     
    } 
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return builder(preorder,inorder,0,inorder.size()-1);     
    }
};