class Solution {
    public:
    int helper(vector<int> & nums, int target, vector<int> &dp)
    {
        if(target == 0) return 1;
        if(dp[target] != -1) return dp[target];
        int ans = 0;
        for(int i = 0;i < nums.size(); i++)
        {
            if(target - nums[i] < 0) break;
            ans += helper(nums,target - nums[i],dp); 
        }
       return dp[target] = ans;
    }
    
    
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> dp(target+ 1, -1);
        return helper(nums,target,dp);
      }
};