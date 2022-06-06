class Solution {
public:
    void dfs(int node,vector<int> adj[],vector<bool> &vis){
        vis[node] = true;
        
        for(int i : adj[node]){
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& c) {
        if(c.size() < n-1){
            return -1;
        }
        vector<int> adj[n];
        for(int i=0;i<c.size();i++){
            adj[c[i][0]].push_back(c[i][1]);
            adj[c[i][1]].push_back(c[i][0]);
        }
        
        vector<bool> vis(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                count++;
            }
        }
        return count-1;
    }
};