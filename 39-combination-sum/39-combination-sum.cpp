class Solution {
public:
    
    void finder(vector<int> &nums,int ind,int target,vector<vector<int>> &ans,vector<int> temp)
    {
        if(ind==nums.size()){
            if(target==0)   ans.push_back(temp);
             return;
        }
        if(nums[ind]<=target){
            temp.push_back(nums[ind]);
            finder(nums,ind,target-nums[ind],ans,temp);
            temp.pop_back();
        }
        finder(nums,ind+1,target,ans,temp);
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        finder(nums,0,target,ans,temp);
        return ans;
    }
};