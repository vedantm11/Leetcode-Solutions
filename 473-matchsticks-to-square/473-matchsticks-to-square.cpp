class Solution {
public:
     bool makesquare(vector<int>& nums) {
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        if (nums.size() < 4 || sum % 4) return false;
        
        vector<int> visited(nums.size(), false);
        sort(nums.begin(),nums.end(),greater<int>());
        return backtrack(nums, visited, sum / 4, 0, 0,4);
    }
    
    bool backtrack(vector<int>& nums,vector<int>& visited, int target, int curr_sum, int i, int k) {
        if (k == 0) 
            return true;
        
        if (curr_sum == target) 
            return backtrack(nums, visited, target, 0, 0, k-1);
        
        for (int j = i; j < nums.size(); j++) {
            if (visited[j] || curr_sum + nums[j] > target) continue;
            
            visited[j] = true;
            if (backtrack(nums, visited, target, curr_sum + nums[j], j+1, k)) return true;
            visited[j] = false;
        }
        
        return false;
    }
};