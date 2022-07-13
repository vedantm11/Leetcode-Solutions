class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mn=0;
        for(int i=nums.size()-2;i>=0;i--){
            mn++;
            if(nums[i]>=mn) mn=0;
        }
        return mn==0;
        
    }
};