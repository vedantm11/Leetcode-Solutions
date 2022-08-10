class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int> &nums,int num, int s, int k,int n)
    {
        if(s==k) 
        {
            ans.push_back(nums);
            return;
        }
        for(int i = num + 1; i <= n; i++){
            if(n - num >= k - s)
            {
                nums.push_back(i);
                helper(nums,i,s+1,k,n);
                nums.pop_back();
            }
        }
        return;
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        for(int i = 1;i <= n; i++){
            vector<int> nums;
            if(n - i >= k-1)
            {
                nums.push_back(i);
                helper(nums,i,1,k,n);
                nums.pop_back();
            }
        }
        return ans;  
    }
};