class Solution {
public:
    int countVowelPermutation(int n) {
        int mod=1000000007;
        vector<vector<int>> mp{{1},{0,2},{0,1,3,4},{2,4},{0}};
        long long dp[n+1][5];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<5;i++) dp[1][i] = 1;
        for(int i=2;i<n+1;i++){
            dp[i][0]=(dp[i-1][1]%mod+dp[i-1][2]%mod+dp[i-1][4]%mod)%mod;
            dp[i][1]=(dp[i-1][0]%mod+dp[i-1][2]%mod)%mod;
            dp[i][2]=(dp[i-1][1]%mod+dp[i-1][3]%mod)%mod;
            dp[i][3]=(dp[i-1][2])%mod;
            dp[i][4]=(dp[i-1][2]%mod+dp[i-1][3]%mod)%mod;
        
        }
        int ans=0;
        for(int i=0;i<5;i++) ans=(ans%mod + dp[n][i]%mod)%mod;
        return ans;
    }
};