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
     
    vector<TreeNode*> builder(int l,int r){
        if(l>r) return vector<TreeNode*>{NULL};
        vector<TreeNode*> ans;    
        
        for(int i=l;i<=r;i++){
            vector<TreeNode*> left=builder(l,i-1);
            vector<TreeNode*> right=builder(i+1,r);
            
            for(int m=0;m<left.size();m++){
                for(int n=0;n<right.size();n++){
                    ans.push_back(new TreeNode(i,left[m],right[n]));
                }
            }
        }
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return builder(1,n);
        
        
        
    }
};