/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        if (!root) return {};
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n =q.size();
            vector<int> cur;
            for(int i = 0; i < n; i++)
            {
                Node* temp = q.front();
                q.pop();
                cur.push_back(temp -> val);
                vector<Node*> temp_vec = temp -> children;
                for(int i = 0; i < temp_vec.size(); i++){
                    if(temp_vec[i]) q.push(temp_vec[i]);
                }
            }
            
            ans.push_back(cur);
        }
        
        return ans;
        
        
        
        
    }
};