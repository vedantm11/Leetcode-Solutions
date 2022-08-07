class Solution {
public:
    int countVowelPermutation(int n) {
        int mod=1000000007;
        vector<vector<int>> mp{{1},{0,2},{0,1,3,4},{2,4},{0}};
        int dp[n+1][5];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<5;i++) dp[0][i] = 0;
        for(int i=0;i<5;i++) dp[1][i] = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<5;j++){
                for(int k=0;k<mp[j].size();k++) 
                    dp[i+1][mp[j][k]]=(dp[i+1][mp[j][k]]%mod+dp[i][j]%mod)%mod;
            }
        }
        int ans=0;
        for(int i=0;i<5;i++) ans=(ans%mod + dp[n][i]%mod)%mod;
        return ans;
    }
};