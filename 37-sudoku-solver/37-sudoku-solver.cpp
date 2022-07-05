class Solution {
public:
     bool isValid(char ch,int row,int col,vector<vector<char>>& board){
        
        // check for 3 conditions 
        
        for(int i=0;i<9;i++){
            
        if(board[row][i]==ch) return false;
        
        if(board[i][col]==ch) return false;
        
        // this is the main condition
            
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == ch )return false;
           
        }
        
        return true;
               
    }
    
    bool Solve(vector<vector<char>>& board){
        
        for(int i=0;i<board.size();i++){
            
            for(int j=0;j<board[0].size();j++){
                
                if(board[i][j]=='.'){
                    
                    for(char c='1';c<='9';c++){
                        
                        if(isValid(c,i,j,board)){
                            
                            board[i][j]=c; // filled the board
                            
                            if(Solve(board)) return true;  
                            
                            else board[i][j]='.';  // backtrack step
                        }
                    }
                    
                    return false;
                }
            }
        }
        
        return true;
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        Solve(board);
        
        
    }
};