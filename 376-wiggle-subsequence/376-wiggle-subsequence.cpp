class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size()<2) return nums.size();
        int ans=1;
        int s=0;
        for (int i=1; i<nums.size();i++) {
            if (nums[i]<nums[i-1] && s!=-1) {         
                s=-1;
                ans++;
            } else if (nums[i]>nums[i-1] && s!=1) {   
                s=1;
                ans++;
            }
        }
        return ans;
        
    }
};