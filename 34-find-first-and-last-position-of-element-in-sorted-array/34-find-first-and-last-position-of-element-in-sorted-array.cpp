class Solution {
public:
    
    int get_bounds(vector<int> &nums, int l, int r, int target, bool check){
        int ans = -1;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(nums[mid] == target) {
                ans = mid;
                if(check) r = mid - 1;
                else l = mid + 1;
            }
            else if(nums[mid] > target) r = mid - 1;
            else l = mid + 1; 
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n == 0) return {-1,-1};
        int l = 0, r = n - 1;
        int left = get_bounds(nums,l,r,target,true);
        if(left == -1) return {-1,-1};
        int right = get_bounds(nums,left,r,target,false);
        return {left,right};
    }
};