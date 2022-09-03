class Solution {
public:
    
    vector<int> ans;
    
    void dfs(int cur,int k,int n)
    {
        if(n == 0) ans.push_back(cur);
        else
        {
            int i = cur % 10;
            if(i + k <= 9) dfs(cur * 10 + (i + k),k,n - 1);
            if(k != 0 && (i - k) >= 0) dfs(cur * 10 + (i - k),k,n - 1);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
     
        for(int i = 1;i <= 9; i++) dfs(i,k,n-1);
        return ans;
        
      
        
    }
};