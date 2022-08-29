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
  
    
    TreeNode* first_val, *sec_val, *pre;
	void recoverTree(TreeNode* root) {
		pre = new TreeNode(INT_MIN);
		inorder(root);
		swap(first_val->val, sec_val->val);
	}

	void inorder(TreeNode* root) {
		if(root == NULL)    return;
        inorder(root->left);
        if(first_val == nullptr && root->val < pre->val)
			first_val = pre;
		if(first_val != nullptr && root->val < pre->val)
			sec_val = root;
		pre = root;
        
        inorder(root->right);
	}
    
};