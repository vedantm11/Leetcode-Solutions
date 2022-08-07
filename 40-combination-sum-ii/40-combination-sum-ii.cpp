class Solution {
public:
    
    void helper(vector<int> &nums,int ind,int target,vector<vector<int>> &ans,vector<int> &temp)
    {
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            if(nums[i]>target) break;
            temp.push_back(nums[i]);
            helper(nums,i+1,target-nums[i],ans,temp);
            temp.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums,0,target,ans,temp);
        return ans;
    }
};