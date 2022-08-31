class Solution {
public:
    
    
    void dfs(vector<vector<int>> & heights, vector<vector<bool>> &visited, int i, int j)
    {
       
        if(visited[i][j]) return;
        int m = heights.size();
        int n = heights[0].size();
        visited[i][j] = true;
        //UP
        if(i - 1 >= 0 && heights[i-1][j] >= heights[i][j]) dfs(heights,visited,i-1,j);
        //DOWN
        if(i + 1 < m && heights[i+1][j] >= heights[i][j]) dfs(heights,visited,i+1,j);
        //LEFT
        if(j- 1 >= 0 && heights[i][j-1] >= heights[i][j]) dfs(heights,visited,i,j-1);
        //RIGHT
        if(j + 1 < n && heights[i][j+1] >= heights[i][j]) dfs(heights,visited,i,j+1);
        }
    
    
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> atlantic(m,vector<bool>(n));
        vector<vector<bool>> pacific(m,vector<bool>(n));     
        vector<vector<int>> ans;
        for(int i = 0; i < m; i++){
            dfs(heights,pacific,i,0);                                                               dfs(heights,atlantic,i,n-1);                        
        }                              
        for(int i = 0; i < n; i++){
            dfs(heights,pacific,0,i);                                                               dfs(heights,atlantic,m-1,i);                        
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(atlantic[i][j] && pacific[i][j]) ans.push_back({i,j});
            }
        }
                                     
        return ans;                                                            
        
        
        
        
        
    }
};