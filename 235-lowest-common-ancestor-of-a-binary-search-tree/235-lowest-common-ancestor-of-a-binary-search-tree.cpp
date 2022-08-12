/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
                if(root == p || root == q)return root;
        if(root->val > min(p->val,q->val) && root->val < max(q->val,p->val))return root;
        if(root->val > max(q->val,p->val))return lowestCommonAncestor(root->left,p,q);
        return lowestCommonAncestor(root->right,p,q);

    }
};