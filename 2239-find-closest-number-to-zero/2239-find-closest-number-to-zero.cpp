class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
       int mn = INT_MAX;
       for(int i = 0;i < nums.size(); i++){
           if(abs(nums[i]) < abs(mn)) mn = nums[i];
           if(abs(nums[i]) == abs(mn)) {
               mn = max(nums[i],mn);
           }
          
       } 
        
        return mn; 
        
    }
};