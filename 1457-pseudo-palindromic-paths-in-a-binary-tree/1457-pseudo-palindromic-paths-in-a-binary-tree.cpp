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
    int ans = 0;
    
    bool isPalindromePossible(){
        if(mp.size()==1) return true;
        int odd_cnt = 0;
        
        for(auto it = mp.begin(); it!=mp.end(); it++){
            if(it->second % 2 != 0) odd_cnt++;
        }
        
        if(odd_cnt > 1) return false;
        return true;
        
    }
    
    void solve(TreeNode* root){
        if(root==NULL) return ;
         mp[root->val]++;
        if(root->left==NULL && root->right==NULL) {
            if(isPalindromePossible()) ans++;
             mp[root->val]--;
            return ;
        }
       
        solve(root->left);
        solve(root->right);
         mp[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
          solve(root);
           return ans;
    }
};