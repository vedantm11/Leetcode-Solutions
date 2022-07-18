class Solution {
public:
    
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    bool ans=false;
    bool isValid(int i,int j, vector<vector<char>> &board)
    {
         return !(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()); 
    }
    void dfs(vector<vector<char>> &board, vector<vector<bool>> & vis, string word, int ind,int i,int j)
    {
        if(ind == word.size()) {
            ans=true; 
            return;
        } 
        
        for(int p=0;p<4;p++){
            if(isValid(i+dir[p][0],j+dir[p][1],board) && !vis[i+dir[p][0]][j+dir[p][1]] && board[i+dir[p][0]][j+dir[p][1]]==word[ind]){
                vis[i][j]=true;
                dfs(board,vis,word,ind+1,i+dir[p][0],j+dir[p][1]);
                vis[i][j]=false;
            }
                                                  }
                                                  }
                                                  
                                                  
                                                  
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int ind=0;
        vector <vector<bool>> vis(m,vector<bool>(n,false)); 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[ind]) dfs(board,vis,word,ind+1,i,j); 
            }
        }
        return ans;
    }
};