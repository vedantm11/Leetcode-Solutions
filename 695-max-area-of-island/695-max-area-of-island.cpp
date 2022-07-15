class Solution {
public:
    
    int r[4]={0,1,0,-1};
    int c[4]={1,0,-1,0};
    
  
    
    int dfs(int i, int j,vector<vector<bool>> &vis, vector<vector<int>> &grid)
    {
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || grid[i][j]==0 or vis[i][j]) return 0;
        vis[i][j]=true;
        return (1+dfs(i,j+1,vis,grid)+dfs(i+1,j,vis,grid)+dfs(i,j-1,vis,grid)+dfs(i-1,j,vis,grid));
       
        
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> vis(grid.size(),(vector<bool>(grid[0].size(),false)));
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0 && !vis[i][j]) ans=max(ans,dfs(i,j,vis,grid)); 
            }
        }
        
        return ans;
    }
};