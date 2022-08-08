class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        int l = 1;
        ans.push_back(nums[0]);
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] > ans.back() ){
                ans.push_back(nums[i]);
                l++;
            }
            else{
                auto ind = lower_bound(ans.begin(),ans.end(),nums[i]);
                *ind = nums[i];
            }
        }
        return l;
    }
};