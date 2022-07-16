class Solution {
public:
    long long mod=1000000007;
    int r[4]={1,-1,0,0};
    int c[4]={0,0,1,-1};
    int dp[50][50][51];
    int dfs(int m,int n,int move,int sr,int sc){
        if(sr<0 || sc<0 || sr>=m ||sc>=n) return 1;
        if(move == 0) return 0;
        if(dp[sr][sc][move]!=-1) return dp[sr][sc][move];
        int sum=0;
        for(int i=0;i<4;i++) sum=(sum+dfs(m,n,move-1,sr+r[i],sc+c[i]))%mod;
        return dp[sr][sc][move]=sum;
        }
    
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return dfs(m,n,maxMove,startRow,startColumn)%mod;
    }
};